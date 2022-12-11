#include <bits/stdc++.h>

typedef long long LL;
LL test(LL a, LL x) {
	LL res = 1;
	while (a % x == 0) a /= x, res *= x;
	return res;
}
LL calc(LL a, LL b, LL j) {
	if (j == 1) return 0;
	return a / test(a, j) * (test(b, j) / j);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		LL a, b;
		std::cin >> a >> b;
		if (a % b == 0) {
			LL ma = 0;
			for (int j = 1; j * j <= b; ++j) {
				if (b % j == 0) {
					ma = std::max(ma, calc(a, b, j));
					ma = std::max(ma, calc(a, b, b / j));
				}
			}
			std::cout << ma << std::endl;
		} else {
			std::cout << a << std::endl;
		}
	}
	return 0;
}