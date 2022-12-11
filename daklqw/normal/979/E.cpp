#include <bits/stdc++.h>

const int MAXN = 60;
int n, P, A[MAXN];
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int dp[MAXN][MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> P;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k <= i; ++k) if (dp[i - 1][j][k]) {
				if (A[i] == 0 || A[i] == -1) {
					int t = pow(2, i - 1 - (!!k), dp[i - 1][j][k]);
					reduce(dp[i][j + 1][k] += t - mod);
					if (k)
					reduce(dp[i][j][k] += t - mod);
				}
				if (A[i] == 1 || A[i] == -1) {
					int t = pow(2, i - 1 - (!!j), dp[i - 1][j][k]);
					reduce(dp[i][j][k + 1] += t - mod);
					if (j)
					reduce(dp[i][j][k] += t - mod);
				}
			}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			if ((i + j & 1) == P)
				reduce(ans += dp[n][i][j] - mod);
	std::cout << ans << std::endl;
	return 0;
}