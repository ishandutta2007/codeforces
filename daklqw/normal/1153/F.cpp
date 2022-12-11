#include <bits/stdc++.h>

const int MAXN = 2010;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int n, K, L, dp[MAXN * 2][MAXN];
int fac[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	for (int i = *fac = 1; i != MAXN; ++i) fac[i] = mul(fac[i - 1], i);
	std::cin >> n >> K >> L;
	dp[0][0] = 1;
	for (int i = 1; i <= n * 2; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j) reduce(dp[i][j] += dp[i - 1][j - 1] - mod);
			reduce(dp[i][j] += mul(dp[i - 1][j + 1], j + 1) - mod);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n * 2; ++i)
		for (int j = K; j <= n; ++j)
			reduce(ans += (LL) dp[i][j] * dp[n * 2 - i][j] % mod * fac[j] % mod - mod);
	ans = pow(dp[n * 2][0], mod - 2, ans);
	ans = pow(2 * n + 1, mod - 2, mul(ans, L));
	std::cout << ans << std::endl;
	return 0;
}