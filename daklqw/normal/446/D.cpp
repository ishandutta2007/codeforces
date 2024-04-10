#include <bits/stdc++.h>

const int MAXN = 510;
// typedef long double db;
typedef double db;
const db eps = 1e-7;
int n, m, K, typ[MAXN];
int SZ;
int to[MAXN];
struct M {
	db A[MAXN][MAXN];
	friend M operator * (M a, M b) {
		M r;
		for (int i = 1; i <= SZ; ++i)
			for (int j = 1; j <= SZ; ++j)
				r.A[i][j] = 0;
	//	for (int i = 1; i <= SZ; ++i)
	//		for (int j = 1; j <= SZ; ++j) {
	//			db v = 0;
	//			for (int k = 1; k <= SZ; ++k)
	//				v += a.A[i][k] * b.A[k][j];
	//			r.A[i][j] = v;
	//		}
		for (int i = 1; i <= SZ; ++i)
			for (int j = 1; j <= SZ; ++j) if (a.A[i][j] > eps)
				for (int k = 1; k <= SZ; ++k)
					r.A[i][k] += a.A[i][j] * b.A[j][k];
		r.fix();
		return r;
	}
	bool same(const M & b) {
		for (int i = 1; i <= SZ; ++i)
			for (int j = 1; j <= SZ; ++j)
				if (std::abs(b.A[i][j] - A[i][j]) > eps)
					return false;
		return true;
	}
	void reduce() {
		for (int i = 1; i <= n; ++i) if (to[i])
			for (int j = 1; j <= n; ++j) if (to[j])
				A[to[i]][to[j]] = A[i][j];
	}
	void print() {
		std::cout << "------------" << std::endl;
		for (int i = 1; i <= SZ; ++i, std::cout << '\n')
			for (int j = 1; j <= SZ; ++j)
				std::cout << A[i][j] << ' ';
	}
	void fix() {
		for (int i = 1; i <= SZ; ++i) {
			db sm = 1;
			for (int j = 1; j < SZ; ++j)
				sm -= A[j][i];
			A[SZ][i] = sm;
		}
	}
} r1, r2, I, ans;

int mat[MAXN][MAXN], deg[MAXN];
M pow(M a, int b, M r = I) {
	for (; b; b >>= 1, a = a * a) if (b & 1) r = a * r;
	return r;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K; SZ = n;
	for (int i = 1; i <= n; ++i) std::cin >> typ[i];
	for (int i = 1, b, e; i <= m; ++i) {
		std::cin >> b >> e;
		++mat[b][e], ++mat[e][b];
		++deg[b], ++deg[e];
	}
	for (int i = 1; i <= n; ++i) I.A[i][i] = 1;
	ans.A[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (mat[i][j]) {
				int t = typ[i] ? i : j;
				db v = mat[i][j] / (db) deg[i];
				r1.A[t][i] += v;
				r2.A[j][i] += v;
			}
	}
	for (int i = 1; i <= 32; ++i)
		r1 = r1 * r1;
	r2 = r1 * r2;
	ans = r1 * ans;
	SZ = 0;
	typ[1] = true;
	for (int i = 1; i <= n; ++i) if (typ[i]) to[i] = ++SZ;
	r2.reduce(), ans.reduce();
	ans = pow(r2, K - 2, ans);
	// ans.print();
	std::cout << std::fixed << std::setprecision(10);
	std::cout << ans.A[SZ][1] << std::endl;
	return 0;
}