#include <bits/stdc++.h>
using namespace std;

const int M = 1<<18;
const int N = 130000;

const int P = 998244353;

int a[M], b[M], f[6][M], g[6][M], c[6][6][N];
char s[N], t[N];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

typedef long long LL;

int IM;
int p[M+1], rev[M];

void init() {
	int fac[10] = {0}, n = 0;
	for (int Q = P - 1, q = 2; Q > 1; q++) if (Q % q == 0) {
		fac[n++] = q;
		while (Q % q == 0) Q /= q;
	}
	int G = 2;
	while (1) {
		int flg = 1;
		for (int i = 0; i < n; i++) if (modExp(G, P / fac[i], P) == 1) flg = 0;
		if (flg) break;
		G++;
	}
	G = modExp(G, P / M, P);
	for (int i = 0; i <= M; i++) p[i] = (i == 0 ? 1 : (LL)p[i-1] * G % P);
	for (int i = 0, j = 1; j < M; j++) {
		for (int k = M >> 1; (i ^= k) < k; k >>= 1);
		rev[j] = i;
	}
	IM = modExp(M, P - 2, P);
}

void NTT(int *B, int *A, int N, int D) {
	for (int j = 0, d = __builtin_ctz(M/N); j < N; j++) A[rev[j]>>d] = B[j];
	for (int n = 1, m = M/2*D; n < N; m /= 2, n <<= 1) {
		for (int i = 0; i < N; i += n<<1) {
			int *w = (D == 1 ? p : p + M), *a = A+i, *b = A+i+n;
			for (int j = 0; j < n; j++, a++, b++, w += m) {
				int x = 1LL * *w * *b % P;
				*b = (*a + P - x) % P; *a = (*a + x) % P;
			}
		}
	}
}

int r[6];

int find_set(int u) {
	return r[u] == -1 ? u : r[u] = find_set(r[u]);
}

int main() {
	scanf("%s%s", s, t);
	int ns = strlen(s);
	int nt = strlen(t);
	reverse(t, t+nt);
	int m = 1 << (32 - __builtin_clz(ns + nt - 2));
	init();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < ns; j++) a[j] = (s[j] == 'a' + i);
		for (int j = ns; j < m; j++) a[j] = 0;
		NTT(a, f[i], m, 1);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < nt; j++) a[j] = (t[j] == 'a' + i);
		for (int j = nt; j < m; j++) a[j] = 0;
		NTT(a, g[i], m, 1);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j) continue;
			for (int k = 0; k < m; k++) a[k] = 1LL * f[i][k] * g[j][k] % P;
			NTT(a, b, m, -1);
			for (int k = nt-1; k <= ns-1; k++) c[i][j][k-nt+1] += !!b[k];
		}
	}
	for (int i = 0; i < ns-nt+1; i++) {
		memset(r, -1, sizeof r);
		int ans = 0;
		for (int j = 0; j < 6; j++) {
			for (int k = j+1; k < 6; k++) {
				if (c[j][k][i] || c[k][j][i]) {
					int u = find_set(j), v = find_set(k);
					if (u == v) continue;
					r[u] = v;
					ans++;
				}
			}
		}
		printf("%d ", ans);
	}
	return 0;
}