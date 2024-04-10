#include <bits/stdc++.h>

const int MAXN = 410;
const int N = 400;
int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}
void fms(int & x, int y, int z) {
	x = ((LL) (mod - y) * z + x) % mod;
}
int fac[MAXN];
int f[MAXN], g[MAXN], h[MAXN];
int pr[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T >> mod;
	for (int i = *fac = 1; i != MAXN; ++i)
		fac[i] = mul(fac[i - 1], i);
	pr[0][0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k <= i; ++k)
				fma(pr[i][j], pr[i - k][j - 1], fac[k]);
	f[1] = 1, f[2] = 1, f[3] = 3;
	h[1] = 1, h[2] = 2;
	for (int i = 4; i <= N; ++i) {
		static int cv[MAXN];
		memset(cv, 0, N + 1 << 2);
		cv[0] = 1;
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k < i && k <= j; ++k)
				fma(cv[j], cv[j - k], f[k] + g[k]);
		f[i] = cv[i];
		reduce(g[i] = fac[i] - mul(f[i], 2));
		h[i] = g[i];
		for (int j = 4; j < i; ++j)
			fms(h[i], pr[i][j], h[j]);
	}
	while (T --> 0) {
		int n; std::cin >> n;
		std::cout << h[n] << std::endl;
	}
	return 0;
}