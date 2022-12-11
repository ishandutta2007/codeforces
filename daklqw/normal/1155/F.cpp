#include <bits/stdc++.h>

const int MAXN = 14;
int mat[MAXN][MAXN];
int dp[1 << MAXN][MAXN][MAXN], pre[1 << MAXN][MAXN][MAXN];
int n, m;
typedef std::pair<int, int> pi;
typedef std::vector<pi> V;
pi red(int a, int b) { if (a > b) std::swap(a, b); return pi(a, b); }
void get(int S, int i, int j, V & res) {
	int now = S, x = j;
	while (now & now - 1) {
		res.push_back(red(x, pre[now][i][x]));
		int tn = x == i ? now : now ^ (1 << x);
		x = pre[now][i][x], now = tn;
	}
}
int f[1 << MAXN], pu[1 << MAXN], ps[1 << MAXN], pt[1 << MAXN];
int ppc[1 << MAXN];
void gmin(int A, int v, int a, int b, int c) {
	if (v < f[A]) {
		f[A] = v;
		pu[A] = a, ps[A] = b, pt[A] = c;
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, t1, t2; i <= m; ++i) {
		std::cin >> t1 >> t2, --t1, --t2;
		mat[t1][t2] = mat[t2][t1] = true;
	}
	for (int i = 0; i < n; ++i)
		dp[1 << i][i][i] = true, pre[1 << i][i][i] = 0;
	const int U = 1 << n;
	for (int i = 1; i != U; ++i) ppc[i] = ppc[i & i - 1] + 1;
	for (int i = 1; i != U; ++i) {
		for (int j = 0; j != n; ++j)
			for (int k = 0; k != n; ++k) if (dp[i][j][k]) {
				if (j == k && ppc[i] > 1) continue;
				for (int l = 0; l != n; ++l)
					if ((~i >> l & 1) && mat[k][l]) {
						dp[i | 1 << l][j][l] = true;
						pre[i | 1 << l][j][l] = k;
					}
				if (ppc[i] > 2 && mat[k][j]) {
					dp[i][j][j] = true;
					pre[i][j][j] = k;
				}
			}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; ++i)
		gmin(1 << i, 0, -1, 0, 0);
	const int INF = *f;
	for (int i = 1; i != U; ++i) if (f[i] != INF) {
		const int I = U - i - 1;
		for (int j = I; j; j = j - 1 & I) {
			for (int k = 0; k < n; ++k) if (i >> k & 1)
				for (int l = 0; l < n; ++l) if (i >> l & 1) {
					int s = j | 1 << k | 1 << l;
					if (dp[s][k][l])
						gmin(i | j, f[i] + ppc[s] - (k != l), j, k, l);
				}
		}
	}
	int now = U - 1;
	V ans;
	while (pu[now] != -1) {
		int s = 1 << ps[now] | 1 << pt[now] | pu[now];
		get(s, ps[now], pt[now], ans);
		now ^= pu[now];
	}
	std::cout << ans.size() << '\n';
	for (auto t : ans)
		std::cout << t.first + 1 << ' ' << t.second + 1 << '\n';
	return 0;
}