#include <bits/stdc++.h>

const int MAXN = 2010;
int n, A, B;
double f[MAXN], g[MAXN], h[MAXN];
typedef std::pair<double, int> pi;
pi dp[MAXN][MAXN];
void gma(pi & a, pi b) { if (a < b) a = b; }
pi solve(double k) {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
			dp[i][j].first = -1e100;
	dp[0][0] = pi(0, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			pi t = dp[i - 1][j];
			gma(dp[i][j], t);
			t.first += f[i];
			gma(dp[i][j + 1], t);
			t.first += g[i] - f[i] - k, ++t.second;
			gma(dp[i][j], t);
			t.first += h[i] - g[i];
			gma(dp[i][j + 1], t);
		}
	}
	return dp[n][A];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> A >> B;
	for (int i = 1; i <= n; ++i) std::cin >> f[i];
	for (int i = 1; i <= n; ++i) std::cin >> g[i];
	for (int i = 1; i <= n; ++i) h[i] = f[i] + g[i] - f[i] * g[i];
	double l = 0, r = 1, ans = 0;
	for (int T = 1; T <= 60; ++T) {
		double mid = (l + r) / 2;
		pi res = solve(mid);
		if (res.second >= B) ans = mid, l = mid;
		else r = mid;
	}
	pi res = solve(ans);
	std::cout << std::fixed << std::setprecision(10);
	std::cout << res.first + B * ans << '\n';
	return 0;
}