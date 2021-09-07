#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

template<class Os, class Co> Os& operator<<(Os& os, const Co& v) {
	for (auto i : v) os << i << ' ';
	return os << '\t';
}
//集合操作
int main()
{
	const auto
		v1 = { 'a', 'b', 'c', 'f', 'h', 'x' },
		v2 = { 'a', 'b', 'c' },
		v3 = { 'a', 'c' },
		v4 = { 'a', 'a', 'b' },
		v5 = { 'g' },
		v6 = { 'a', 'c', 'g' },
		v7 = { 'A', 'B', 'C' };

	auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };

	//判断是否含有子序列
	std::cout
		<< v1 << "\nincludes:\n" << std::boolalpha
		<< v2 << ": " << std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n'
		<< v3 << ": " << std::includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << '\n'
		<< v4 << ": " << std::includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << '\n'
		<< v5 << ": " << std::includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << '\n'
		<< v6 << ": " << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end()) << '\n'
		<< v7 << ": " << std::includes(v1.begin(), v1.end(), v7.begin(), v7.end(), no_case)
		<< " (case-insensitive)\n\n";

	const std::vector<int> vv1{ 1, 2, 5, 5, 5, 9 };
	const std::vector<int> vv2{ 2, 5, 7 };
	std::vector<int> diff;
	std::vector<int> com;

	std::set_difference(vv1.begin(), vv1.end(), vv2.begin(), vv2.end(),
		std::inserter(diff, diff.begin()));

	std::cout << vv1 << std::endl;
	std::cout << vv2 << std::endl;
	std::cout << diff << std::endl<<std::endl;

	const std::vector<int> vvv1{ 1, 2, 7, 8, 9 };
	const std::vector<int> vvv2{ 2, 8 ,11};
	std::set_intersection(vvv1.begin(), vvv1.end(), vvv2.begin(), vvv2.end(),
		std::inserter(com, com.begin()));//已排序的基础上


	std::cout << vvv1 << std::endl;
	std::cout << vvv2 << std::endl;
	std::cout << com << std::endl;
}
