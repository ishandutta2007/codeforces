#include <bits/stdc++.h>

const int MAXN = 50;
typedef long long LL;
int mat[MAXN][MAXN];
int n, m, cnt, cnq;
int vis[MAXN];
void dfs(int u, int c = 0) {
	vis[u] = c;
	for (int i = 1; i <= n; ++i)
		if (mat[u][i] && vis[i] == -1)
			dfs(i, c ^ 1);
}
LL calc0() { return 1ll << cnq; } 
LL calc1() {
	bool can = true;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (mat[i][j] && vis[i] == vis[j])
				can = false;
	return ((LL) can) << cnt;
}
LL calc01() {
	static int hav[1 << 20], can[1 << 20];
	const int L = std::min(20, n);
	hav[0] = 1;
	for (int i = 1; i != (1 << L); ++i)
		if (hav[i] = hav[i & i - 1]) {
			int u = __builtin_ctz(i);
			for (int j = 0; j < L; ++j)
				if ((i >> j & 1) && mat[u + 1][j + 1]) {
					hav[i] = 0; break;
				}
		}
	for (int i = 0; i != L; ++i)
		for (int j = 0; j != (1 << L); ++j)
			if (j >> i & 1)
				hav[j] += hav[j ^ (1 << i)];
	LL res = 0;
	const int R = n - L;
	for (int i = 0; i != (1 << R); ++i) {
		if (i) {
			if (can[i] = can[i & i - 1]) {
				int u = __builtin_ctz(i);
				for (int j = 0; j < R; ++j)
					if ((i >> j & 1) && mat[u + 1 + L][j + 1 + L]) {
						can[i] = 0; break;
					}
			}
		} else can[i] = true;
		if (can[i]) {
			int S = (1 << L) - 1;
			for (int j = 0; j < L; ++j)
				for (int k = 0; k < R; ++k) if (i >> k & 1)
					if (mat[k + L + 1][j + 1]) {
						S ^= 1 << j; break;
					}
			res += hav[S];
		}
	}
	return res;
}
LL calc02() { return 1ll << cnt; }
LL allno() { return (LL) (cnt == cnq) << cnt; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, mat[b][e] = mat[e][b] = true;
	memset(vis, -1, sizeof vis);
	for (int i = 1; i <= n; ++i)
		if (vis[i] == -1) {
			dfs(i), ++cnt;
			bool hav = false;
			for (int j = 1; j <= n; ++j) hav |= mat[i][j];
			if (!hav) ++cnq;
		}
	LL ans = 1ll << n;
	ans -= calc01() * 2 + calc02();
	ans += calc0() * 2 + calc1();
	ans -= allno();
	std::cout << ans << std::endl;
	return 0;
}