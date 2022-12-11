#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
char S[MAXN];
int n, m;
LL dp[MAXN][2][2][2][2];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> (S + 1);
	for (int i = 1; i <= n; ++i) S[i] -= 'a';
	dp[0][1][0][0][0] = 1;
	S[0] = S[n + 1] = m;
	for (int i = 1; i <= n; ++i) {
		for (int a00 = 0; a00 < 2; ++a00)
		for (int a01 = 0; a01 < 2; ++a01)
		for (int a10 = 0; a10 < 2; ++a10)
		for (int a11 = 0; a11 < 2; ++a11) {
			LL tmp = dp[i - 1][a00][a01][a10][a11];
			for (int j = 0; j < m; ++j) {
				int b00 = 0, b01 = 0, b10 = 0, b11 = 0;
				// no ecc
				b00 |= a00 && (j == S[i]);
				b01 |= a01 && (j == S[i + 1]);
				b10 |= a10 && (j == S[i - 1]);
				b11 |= a11 && (j == S[i]);
				// l add
				b10 |= a00;
				b11 |= a01;
				// r add
				b01 |= a00 && (j == S[i + 1]);
				b11 |= a10 && (j == S[i - 1]);
				// l, r add
				b11 |= a00;
				dp[i][b00][b01][b10][b11] += tmp;
			}
		}
	}
	LL ans = std::accumulate(***dp[n], ***dp[n + 1], 0ll) - ****dp[n];
	std::cout << (ans - 1) << std::endl;
	return 0;
}