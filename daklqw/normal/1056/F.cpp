#include <bits/stdc++.h>

const int MAXN = 110;
typedef double db;
const db eps = 1e-6;
db C, T;
int n;
struct obj {
	int a, p;
	bool operator < (const obj & b) const {
		return a == b.a ? p > b.p : a > b.a;
	}
} ps[MAXN];
db pw[MAXN];
db dp[110][1010];
void gmi(db & x, db y) { x > y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; std::cin >> Q;
	*pw = 1;
	for (int i = 1; i != MAXN; ++i)
		pw[i] = pw[i - 1] * 10 / 9;
	while (Q --> 0) {
		std::cin >> n >> C >> T;
		int sm = 0;
		for (int i = 1; i <= n; ++i)
			std::cin >> ps[i].a >> ps[i].p, sm += ps[i].p;
		std::sort(ps + 1, ps + 1 + n);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= sm; ++j)
				dp[i][j] = 1e100;
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = n; j; --j)
				for (int k = sm; k >= ps[i].p; --k)
					gmi(dp[j][k], dp[j - 1][k - ps[i].p] + ps[i].a * pw[j]);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = ans + 1; j <= sm; ++j)
				if (dp[i][j] < 1e10) {
					db ub = T - 10 * i;
					if (ub < -eps) continue;
					db b = ub - 1. / C, c = (dp[i][j] - ub) / C;
					if (b * b - 4 * c >= 0) {
						if (c <= eps) ans = j;
						if (c >= -eps && b >= -eps) ans = j;
					}
				}
		}
		std::cout << ans << '\n';
	}
	return 0;
}