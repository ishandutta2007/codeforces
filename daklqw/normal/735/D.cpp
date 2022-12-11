#include <iostream>
#include <cstdio>
bool ispri(int x) {
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false; return true;
}
int main() {
	int n; std::cin >> n;
	if (ispri(n)) puts("1"); else if (ispri(n - 2) || !(n & 1)) puts("2"); else puts("3");
	return 0;
}