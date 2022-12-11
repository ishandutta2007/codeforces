#include <bits/stdc++.h>

typedef long long LL;
int da, re, ti, co;
LL ma;
LL calc(int x) {
	LL r = (LL) (x + 1) * da - (LL) re * co * ((LL) x * (x + 1) / 2);
	ma = std::max(ma, r);
	return r;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> da >> re >> ti >> co;
		if ((LL) re * ti < da) {
			std::cout << -1 << std::endl;
			continue;
		}
		ma = 0;
		int C = ti / co;
		// (u + 1) * da - re * co * u * (u + 1) / 2
		int l = 0, r = C - 1;
		calc(C);
		while (l <= r) {
			LL mid = l + r >> 1;
			LL lhs = calc(mid), rhs = calc(mid + 1);
			if (lhs <= rhs) l = mid + 1;
			else r = mid - 1;
		}
		std::cout << ma << '\n';
	}
	return 0;
}