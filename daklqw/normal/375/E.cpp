#include <bits/stdc++.h>

const int MAXN = 510;
typedef long long LL;
int dis[MAXN][MAXN], n, X, col[MAXN];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
void dfs(int u, int rt, int fa = 0, LL d = 0) {
	if (d <= X) dis[u][rt] = dis[rt][u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			dfs(to[i], rt, u, d + val[i]);
}
namespace Simplex {
	const double eps = 1e-6;
	double A[MAXN][MAXN * 2], * B = A[0];
	int base[MAXN * 2];
	int n, m;
	void append(double * src, double tar, int typ) {
		if (typ == 2) append(src, tar, 0), append(src, tar, 1);
		else if (typ == 1) {
			for (int i = 1; i <= n; ++i) src[i] = -src[i];
			append(src, -tar, 0);
		} else {
			++m; base[m + n] = m; A[m][0] = tar;
			memcpy(A[m] + 1, src + 1, n << 3);
			for (int i = 1; i <= n + m; ++i) A[m][i] = -A[m][i];
		}
	}
	bool errtag;
	void pivot(int x, int y) {
		int at = base[x];
		double coef = 1 / A[at][y];
		A[at][y] = 0, A[at][x] = -1;
		for (int i = 0; i <= n + m; ++i)
			A[at][i] *= -coef;
		for (int i = 0; i <= m + 1; ++i) {
			coef = A[i][y], A[i][y] = 0;
			for (int j = 0; j <= n + m; ++j)
				A[i][j] += coef * A[at][j];
		}
		std::swap(base[x], base[y]);
	}
	double simplex() {
		while (true) {
			int at = 0; double v = eps;
			for (int i = 1; i <= n + m; ++i)
				if (!base[i] && B[i] > v)
					v = B[i], at = i;
			if (!at) return *B;
			int a2 = 0; double vx = 1e20;
			for (int i = 1; i <= n + m; ++i) if (int b = base[i])
				if (A[b][at] < -eps && A[b][0] < vx * -A[b][at])
					a2 = i, vx = -A[b][0] / A[b][at];
			if (!a2) { errtag = true; return 1e20; } // Unbounded
			pivot(a2, at);
		}
	}
	void init() {
		int at = 0; double tv = -eps;
		for (int i = 1; i <= n + m; ++i) if (int b = base[i])
			if (A[b][0] < tv) tv = A[b][0], at = i;
		if (!at) return ;
		std::swap(A[0], A[m + 1]);
		++n, B[n + m] = -1;
		for (int i = 1; i <= m; ++i) A[i][n + m] = 1;
		pivot(at, n + m), simplex();
		if (fabs(B[0]) > eps) { errtag = true; return ; }
		std::swap(A[0], A[m + 1]);
		++m, base[n + m] = m;
	}
}


int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> X;
	int m = 0;
	for (int i = 1; i <= n; ++i) std::cin >> col[i], m += col[i];
	for (int i = 1; i < n; ++i) {
		int t1, t2, t3;
		std::cin >> t1 >> t2 >> t3;
		addedge(t1, t2, t3);
	}
	for (int i = 1; i <= n; ++i) dfs(i, i);
	static double tmp[MAXN];
	memset(tmp, 0, sizeof tmp);
	Simplex::n = n;
	for (int i = 1; i <= n; ++i) Simplex::B[i] = col[i];
	for (int i = 1; i <= n; ++i) tmp[i] = 1;
	Simplex::append(tmp, m, 2);
	for (int i = 1; i <= n; ++i) {
		memset(tmp, 0, sizeof tmp);
		for (int j = 1; j <= n; ++j)
			tmp[j] = dis[i][j];
		Simplex::append(tmp, 1, 1);
	}
	Simplex::init();
	double res = Simplex::errtag ? 0 : Simplex::simplex();
	int ans = m - floor(res + 0.1);
	if (Simplex::errtag) ans = -1;
	std::cout << ans << std::endl;
	return 0;
}