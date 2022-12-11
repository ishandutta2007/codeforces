#include <bits/stdc++.h>

char buf[10];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf;
	std::cout << (buf[6] & 1) << std::endl;
	return 0;
}