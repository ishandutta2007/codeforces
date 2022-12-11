#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int n, W;
int cntl[MAXN], cntr[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> W >> n;
	if (W == 1) return std::cout << 0 << std::endl, 0;
	for (int i = 1; i < W; ++i) cntl[i] = 1 + (i == 1);
	for (int i = 2; i <= W; ++i) cntr[i + n] = 1 + (i == W);
	for (int i = 1, t; i <= n; ++i) {
		std::cin >> t;
		cntl[i + t] += cntl[i + t - 1];
		cntl[i + t - 1] = 0;
		cntr[t - i + n] += cntr[t - i + n + 1];
		cntr[t - i + n + 1] = 0;
	}
	LL ans = W;
	for (int i = 1; i <= W + n; ++i) {
		ans -= cntl[i] * (LL) std::max(1, i - n);
		ans += cntr[i] * (LL) std::min(W, i);
	}
	std::cout << ans << std::endl;
	return 0;
}