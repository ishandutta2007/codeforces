#include <bits/stdc++.h>

typedef long long LL;
int main() {
	LL a, b, c;
	std::cin >> a >> b >> c;
	std::cout << c * 2 + std::min(a, b) * 2 + (a != b) << '\n';
	return 0;
}