#include <bits/stdc++.h>

const int MAXN = 16;
const int MAXK = 16 * 15 / 2;
int dp[1 << MAXN][MAXK + 1];
int typ[MAXN], xs[MAXN], ys[MAXN];
int n;
void gmin(int & x, int y) { x > y ? x = y : 0; }
void gmax(int & x, int y) { x < y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	int ax = 0, ay = 0;
	for (int i = 0; i < n; ++i) {
		static char buf[10];
		std::cin >> buf >> xs[i] >> ys[i];
		ax += xs[i], ay += ys[i];
		typ[i] = *buf == 'B';
	}
	memset(dp, 0xcf, sizeof dp);
	const int NINF = **dp; **dp = 0;
	const int U = 1 << n;
	int ans = 0x3f3f3f3f;
	for (int i = 0; i != U; ++i)
		for (int j = 0; j <= MAXK; ++j)
			if (dp[i][j] != NINF) {
				if (i == U - 1)
					gmin(ans, std::max(ax - j, ay - dp[i][j]));
				int dx = 0, dy = 0;
				for (int k = 0; k != n; ++k) if (i >> k & 1)
					dx += typ[k] == 0, dy += typ[k] == 1;
				for (int k = 0; k != n; ++k) if (~i >> k & 1) {
					int xx = std::min(dx, xs[k]);
					int xy = std::min(dy, ys[k]);
					gmax(dp[i | 1 << k][j + xx], dp[i][j] + xy);
				}
			}
	std::cout << ans + n << std::endl;
	return 0;
}