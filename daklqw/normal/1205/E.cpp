#include <bits/stdc++.h>

const int MAXN = 200010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
std::vector<int> fac[MAXN];
int n, K;
int dp[MAXN];
int calc(int A, int B) {
	return A <= B ? A + 1 : std::max(B * 2 - A + 1, 0);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K; const int m = n * 2;
	for (int i = 1; i <= m; ++i)
		for (int j = i; j <= m; j += i)
			fac[j].push_back(i);
	int Ans = 0;
	for (int i = 1; i <= m; ++i) {
		std::sort(fac[i].begin(), fac[i].end());
		const int S = fac[i].size();
		for (int j = S - 1; ~j; --j) {
			int t = fac[i][j];
			dp[t] = calc(i / t - 2, (n - 1) / t - 1);
			for (int k = j + 1; k < S; ++k)
				if (fac[i][k] % t == 0)
					reduce(dp[t] -= dp[fac[i][k]]);
			reduce(Ans += pow(K, std::max(i - n, t), dp[t]) - mod);
			// std::cout << "DBG " << i << ' ' << t << " : " << dp[t] << std::endl;
		}
	}
	// std::cout << "FIN " << Ans << std::endl;
	Ans = pow(pow(K, mod - 2), n, Ans);
	std::cout << Ans << std::endl;
	return 0;
}