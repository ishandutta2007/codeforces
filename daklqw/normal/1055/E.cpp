#include <bits/stdc++.h>

const int MAXN = 1510;
int A[MAXN], ls[MAXN], rs[MAXN], n, m, S, K;
int rmost[MAXN];
int li[MAXN], bak;
int B[MAXN], pre[MAXN];
int dp[MAXN][MAXN];
void gma(int & x, int y) { x < y ? x = y : 0; }
bool solve(int lim) {
	for (int i = 1; i <= n; ++i)
		pre[i] = (B[i] = A[i] <= lim) + pre[i - 1];
	for (int i = 0; i <= n; ++i)
		memset(dp[i], 0xcf, S + 1 << 2);
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= S; ++j) {
			gma(dp[i + 1][j], dp[i][j]);
			if (rmost[i] > i && j < S)
				gma(dp[rmost[i]][j + 1], dp[i][j] + pre[rmost[i]] - pre[i]);
		}
	}
	return *std::max_element(dp[n], dp[n + 1]) >= K;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> S >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], li[++bak] = A[i];
	for (int i = 1; i <= m; ++i)
		std::cin >> ls[i] >> rs[i], gma(rmost[ls[i] - 1], rs[i]);
	for (int i = 1; i <= n; ++i) gma(rmost[i], rmost[i - 1]);
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	int l = 1, r = bak, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (solve(li[mid])) ans = li[mid], r = mid - 1;
		else l = mid + 1;
	}
	std::cout << ans << std::endl;
	return 0;
}