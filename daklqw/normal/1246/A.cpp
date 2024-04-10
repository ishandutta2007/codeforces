#include <bits/stdc++.h>

typedef long long LL;
int n, P;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> P;
	for (int i = 0; i <= 100000; ++i) {
		LL now = n - (LL) P * i;
		if (now < 0) continue;
		int t = __builtin_popcountll(now);
		if (t <= i && now >= i) {
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << -1 << '\n';
	return 0;
}