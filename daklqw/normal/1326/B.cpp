#include <bits/stdc++.h>

typedef long long LL;
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	LL ma = 0;
	for (int i = 1, t; i <= n; ++i) {
		std::cin >> t;
		LL x = t + ma;
		std::cout << x << ' ';
		if (t > 0) ma = x;
	}
	return 0;
}