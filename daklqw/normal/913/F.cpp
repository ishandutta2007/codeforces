#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXN = 3010;
int n, P;
int dp[MAXN][MAXN];
int pwp[MAXN], pwq[MAXN];
int f[MAXN], g[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	static int _a, _b;
	std::cin >> _a >> _b;
	P = pow(_b, mod - 2, _a);
	for (int i = 0; i <= n; ++i)
		pwp[i] = pow(P, i), pwq[i] = pow(1 - P + mod, i);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			dp[i][j] = ((LL) dp[i - 1][j] * pwp[j] + (LL) dp[i - 1][j - 1] * pwq[i - j]) % mod;
	}
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		for (int j = 1; j < i; ++j)
			t = (t + (LL) dp[i][j] * f[j] + mod) % mod;
		reduce(f[i] = 1 - t);
	}
	for (int i = 2; i <= n; ++i) {
		int t = 0;
		for (int j = 1; j <= i; ++j) {
			int co = mul(dp[i][j], f[j]);
			int ce = (g[j] + g[i - j] + j * (j - 1ll) / 2 + (LL) j * (i - j)) % mod;
			t = (t + (LL) co * ce) % mod;
		}
		g[i] = pow(1 - f[i] + mod, mod - 2, t);
	}
	std::cout << g[n] << std::endl;
	return 0;
}