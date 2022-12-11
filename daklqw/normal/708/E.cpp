#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1.5e3 + 10;
const int MAXS = 1e5 + 10;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}

int n, m, K;
int ps[MAXN], pre[MAXN];
int fac[MAXS], inv[MAXS];
int C(int a, int b) {
	return (LL) fac[a] * inv[b] % mod * inv[a - b] % mod;
}

int f[MAXN][MAXN];
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i < MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i < MAXS; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	scanf("%d%d", &n, &m);
	int a, b; scanf("%d%d", &a, &b);
	int P = pow(b, mod - 2, a);
	scanf("%d", &K);
	for (int i = 0; i <= m && i <= K; ++i)
		ps[i] = pow(P, i, pow(1 + mod - P, K - i, C(K, i)));
	for (int i = 0; i <= m; ++i)
		reduce(pre[i] = ps[i] + (i ? pre[i - 1] - mod : 0));
	f[0][m] = 1;
	for (int i = 1; i <= n; ++i) {
		static int tp[MAXN], ts[MAXN];
		for (int j = 1; j <= m; ++j) {
			reduce(tp[j] = tp[j - 1] + f[i - 1][j] - mod);
			fma(ts[j] = ts[j - 1], ps[j], tp[j]);
		}
		for (int r = 1; r <= m; ++r) {
			int sm = mul(pre[r - 1], tp[m] - tp[m - r] + mod);
			reduce(sm -= ts[r - 1]);
			f[i][r] = mul(ps[m - r], sm);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		reduce(ans += f[n][i] - mod);
	printf("%d\n", ans);
	return 0;
}