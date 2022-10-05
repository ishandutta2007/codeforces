#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define REP(i,a) for (int i=0; i<(a); i++)
#define clr(a) memset(a, 0, sizeof a)
using namespace std; const int maxn = (1 << 17) + 4, MOD = 998244353;
int a[maxn], b[maxn], c[maxn], d[maxn], d1[maxn], e[maxn], e1[maxn], f[maxn];
int R[maxn], w[maxn], N, K, n = 4, rev, tmp;
inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}
void NTT(int a[maxn], int n, int f) {
	REP (i, n) if (i < R[i]) swap(a[i], a[R[i]]);
	for (int d=1,t=n>>1; d<n; d<<=1,t>>=1)
		for (int i=0; i<n; i+=(d<<1)) REP (j, d) {
			tmp = 1LL * w[f?n-t*j:t*j] * a[i+j+d] % MOD;
			a[i+j+d] = (a[i+j] - tmp + MOD) % MOD;
			a[i+j] = (a[i+j] + tmp) % MOD;
		}
	if (!f) return; rev = power(n, MOD - 2);
	REP (i, n) a[i] = 1LL * a[i] * rev % MOD;
}
void get(int a[maxn], int b[maxn], int c[maxn]) {
	memset(c, 0, sizeof w); c[0] = 1; rep (i, 1, K) c[i] = (1LL * b[i] + b[i-1] + a[i-1]) % MOD;
}
void solve(int x) {
	if (!x) { clr(a); clr(b); a[0] = 1; b[0] = b[1] = 1; return; }
	if (x == 1) { clr(a); clr(b); a[0] = a[1] = 1; b[0] = 1; b[1] = 3; b[2] = 1; return; }
	solve(x/2 - 1); get(a, b, c);
	NTT(a, n, 0); NTT(b, n, 0); NTT(c, n, 0);
	REP (i, n) {
		d[i] = 1LL * b[i] * b[i] % MOD; d1[i] = 1LL * a[i] * a[i] % MOD;
		e[i] = 1LL * b[i] * c[i] % MOD; e1[i] = 1LL * a[i] * b[i] % MOD;
	}
	NTT(d, n, 1); NTT(d1, n, 1); NTT(e, n, 1); NTT(e1, n, 1);
	rep (i, 1, n-1) d[i] = (d[i] + d1[i-1]) % MOD, e[i] = (e[i] + e1[i-1]) % MOD;
	if (x & 1) { get(d, e, f); REP (i, n) a[i] = (i <= K) * e[i], b[i] = (i <= K) * f[i]; }
	else { REP(i, n) a[i] = (i <= K) * d[i], b[i] = (i <= K) * e[i]; }
}
int main() {
	scanf("%d%d", &N, &K); while (n <= 2 * K) n <<= 1;
	REP (i, n) R[i] = (R[i>>1]>>1) | ((i&1)*(n>>1));
	w[0] = w[n] = 1; w[1] = power(3, (MOD - 1) / n);
	rep (i, 2, n-1) w[i] = 1LL * w[i-1] * w[1] % MOD;
	solve(N); rep (i, 1, K) printf("%d ", a[i]);
	return 0;
}