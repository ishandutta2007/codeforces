#include <bits/stdc++.h>

const int MAXN = 110;
const int MAXM = 410;
typedef long long LL;
int mod;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int fastpow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int A[MAXM][MAXM], B[MAXM][MAXM], idxa, idxb;
int ma[MAXN][MAXN], mb[MAXN][MAXN];
int faa[MAXN * MAXN], fab[MAXN * MAXN];
int n, m;
void adde(int A[MAXM][MAXM], int b, int e) {
	if (b == e) return ;
	reduce(A[b][b] += 1 - mod), reduce(A[e][e] += 1 - mod);
	reduce(--A[b][e]), reduce(--A[e][b]);
}
int find(int * fa, int x) {
	return fa[x] == x ? x : fa[x] = find(fa, fa[x]);
}
void merge(int * fa, int a, int b) {
	a = find(fa, a), b = find(fa, b);
	if (a == b) exit((std::cout << "0" << std::endl, 0));
	fa[a] = b;
}
int det(int A[MAXM][MAXM], int n) {
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		int at = 0;
		for (int j = i; j <= n; ++j)
			if (A[j][i]) { at = j; break; }
		if (!at) return 0;
		if (at != i) reduce(res = -res), std::swap(A[i], A[at]);
		res = mul(res, A[i][i]);
		const int I = fastpow(A[i][i], mod - 2);
		for (int j = i; j <= n; ++j) A[i][j] = mul(A[i][j], I);
		for (int j = i + 1; j <= n; ++j) if (A[j][i]) {
			const int V = A[j][i];
			for (int k = i; k <= n; ++k)
				reduce(A[j][k] -= mul(A[i][k], V));
		}
	}
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> mod;
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 1; j <= m + 1; ++j)
			if (i + j & 1) ma[i][j] = ++idxa;
			else mb[i][j] = ++idxb;
	for (int i = 1; i <= idxa; ++i) faa[i] = i;
	for (int i = 1; i <= idxb; ++i) fab[i] = i;
	std::vector<std::pair<int, int> > blo;
	for (int i = 1; i <= n; ++i) {
		static char buf[MAXN];
		std::cin >> buf + 1;
		for (int j = 1; j <= m; ++j) {
			if (buf[j] == '/') {
				if (i + j & 1) merge(fab, mb[i][j + 1], mb[i + 1][j]);
				else merge(faa, ma[i][j + 1], ma[i + 1][j]);
			} else if (buf[j] == '\\') {
				if (i + j & 1) merge(faa, ma[i][j], ma[i + 1][j + 1]);
				else merge(fab, mb[i][j], mb[i + 1][j + 1]);
			} else blo.emplace_back(i, j);
		}
	}
	static int ida[MAXN * MAXN], idb[MAXN * MAXN];
	int da = 0, db = 0;
	for (int i = 1; i <= idxa; ++i) if (i == find(faa, i)) ida[i] = ++da;
	for (int i = 1; i <= idxb; ++i) if (i == find(fab, i)) idb[i] = ++db;
	for (auto t : blo) {
		int i, j; std::tie(i, j) = t;
		int xa, ya, xb, yb;
		if (i + j & 1) {
			xa = ma[i][j], ya = ma[i + 1][j + 1];
			xb = mb[i][j + 1], yb = mb[i + 1][j];
		} else {
			xa = ma[i][j + 1], ya = ma[i + 1][j];
			xb = mb[i][j], yb = mb[i + 1][j + 1];
		}
		xa = ida[find(faa, xa)];
		xb = idb[find(fab, xb)];
		ya = ida[find(faa, ya)];
		yb = idb[find(fab, yb)];
		adde(A, xa, ya), adde(B, xb, yb);
	}
	int ans = det(A, da - 1) + det(B, db - 1) - mod;
	reduce(ans);
	std::cout << ans << std::endl;
	return 0;
}