#include <bits/stdc++.h>

const int MAXN = 1010;
int C[10];
char buf[MAXN];
int arr[MAXN][MAXN], bse[MAXN];
int n, L;
int dp[MAXN][MAXN], rk[MAXN][MAXN];
int buc[10], cnt[10], suc[11];
int dig[MAXN];
void add(int x, int v) {
	cnt[x] += v;
	for (int i = 0; i < 10; ++i)
		buc[i] += v * C[(i + x) % 10];
}
void gma(int & x, int y) { x < y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf; int BL = strlen(buf); L = BL;
	for (int i = 0; i < L; ++i)
		bse[L - i] = buf[i] == '?' ? -1 : buf[i] - '0';
	std::cin >> n;
	for (int T = 1; T <= n; ++T) {
		std::cin >> buf;
		int t = strlen(buf); dig[T] = std::max(t, BL);
		for (int i = 0; i < t; ++i) arr[T][t - i] = buf[i] - '0';
		L = std::max(L, t);
	}
	++L;
	for (int i = 0; i < 10; ++i) std::cin >> C[i];
	memset(dp, 0xcf, sizeof dp);
	const int NINF = **dp;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) rk[0][i] = i;
	for (int i = 1; i <= L; ++i) {
		memset(buc, 0, sizeof buc);
		for (int j = 1; j <= n; ++j) ++buc[arr[j][i]];
		for (int j = 1; j < 10; ++j) buc[j] += buc[j - 1];
		for (int j = n; j; --j) {
			int u = rk[i - 1][j];
			rk[i][buc[arr[u][i]]--] = u;
		}
		int DOWN = i == BL, UP = 9;
		if (bse[i] != -1) DOWN = UP = bse[i];
		memset(buc, 0, sizeof buc);
		memset(cnt, 0, sizeof cnt);
		int up = 0, dta = 0;
		for (int j = 1; j <= n; ++j) {
			add(arr[j][i], 1);
			if (i > dig[j]) dta += C[0];
		}
		for (int j = 0; j <= n; ++j) {
			if (j) {
				int u = rk[i - 1][n - j + 1];
				add(arr[u][i], -1);
				add((arr[u][i] + 1) % 10, 1);
				up += arr[u][i] == 9;
				if (i > dig[u]) dta -= C[0];
			}
			if (dp[i - 1][j] == NINF) continue;
			for (int k = 0; k < 10; ++k) suc[k] = cnt[k];
			for (int k = 9; ~k; --k) suc[k] += suc[k + 1];
			for (int k = DOWN; k <= UP; ++k)
				gma(dp[i][suc[10 - k] + up], buc[k] + dp[i - 1][j] - dta);
		}
	}
	int ans = *std::max_element(dp[L], dp[L + 1]);
	std::cout << ans << std::endl;
	return 0;
}