#include <bits/stdc++.h>

const int MAXN = 50;
typedef long long LL;
int n;
char buf[MAXN];
int fail[MAXN], tr[MAXN][2];
LL dp[MAXN][MAXN][2];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> buf + 1; int S = strlen(buf + 1);
	for (int i = 1; i <= S; ++i) {
		int now = fail[i - 1];
		while (now && (now + 1 == i || buf[now + 1] != buf[i])) now = fail[now];
		fail[i] = now + 1 != i && buf[now + 1] == buf[i] ? now + 1 : 0;
	}
	for (int i = 0; i <= S; ++i)
		for (int j = 0; j < 2; ++j) {
			int now = i;
			while (now && buf[now + 1] != j + '0') now = fail[now];
			tr[i][j] = buf[now + 1] == j + '0' ? now + 1 : 0;
		}
	LL ans = 0;
	for (int i = 0; i <= S; ++i) {
		memset(dp, 0, sizeof dp);
		dp[0][i][i == S] = 1;
		for (int j = 1; j <= n; ++j)
		for (int k = 0; k <= S; ++k)
		for (int l = 0; l < 2; ++l)
		for (int p = 0; p < 2; ++p)
			dp[j][tr[k][p]][(tr[k][p] == S) || l] += dp[j - 1][k][l];
		ans += dp[n][i][1];
	}
	std::cout << ans << std::endl;
	return 0;
}