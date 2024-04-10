#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << (n * 8 + k - 1) / k + (n * 5 + k - 1) / k + (n * 2 + k - 1) / k << std::endl;
	return 0;
}