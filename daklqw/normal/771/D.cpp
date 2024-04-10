#include <bits/stdc++.h>

const int MAXN = 76;
char buf[MAXN];
int n, dp[MAXN][MAXN][MAXN][2];
std::vector<int> lv, lk, le;
void gmin(int & x, int y) { x > y ? x = y : 0; }
int calc(int a, int b, int c, int v) {
	int res = 0;
	for (int i = 0; i < a; ++i) res += lv[i] > v;
	for (int i = 0; i < b; ++i) res += lk[i] > v;
	for (int i = 0; i < c; ++i) res += le[i] > v;
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1;
	for (int i = 1; i <= n; ++i) {
		if (buf[i] == 'V') lv.push_back(i);
		else if (buf[i] == 'K') lk.push_back(i);
		else le.push_back(i);
	}
	memset(dp, 0x3f, sizeof dp);
	int ans = ****dp;
	dp[0][0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= lv.size(); ++j)
		for (int k = 0; k <= lk.size(); ++k)
		for (int p = 0; p < 2; ++p) {
			int l = i - 1 - j - k;
			if (l > le.size()) continue;
			if (j != lv.size())
				gmin(dp[i][j + 1][k][1], dp[i - 1][j][k][p] + calc(j, k, l, lv[j]));
			if (k != lk.size() && !p)
				gmin(dp[i][j][k + 1][0], dp[i - 1][j][k][p] + calc(j, k, l, lk[k]));
			if (l != le.size())
				gmin(dp[i][j][k][0], dp[i - 1][j][k][p] + calc(j, k, l, le[l]));
		}
	}
	for (int i = 0; i < 2; ++i)
		gmin(ans, dp[n][lv.size()][lk.size()][i]);
	std::cout << ans << std::endl;
	return 0;
}