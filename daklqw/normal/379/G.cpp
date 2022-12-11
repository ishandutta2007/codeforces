#include <bits/stdc++.h>

const int MAXN = 2510;
int head[MAXN], nxt[MAXN << 2], to[MAXN << 2], tot = 1;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}

int dp[MAXN][3][MAXN];
int dep[MAXN], fa[MAXN];
int n, m;
void gma(int & x, int y) { x < y ? x = y : 0; }
const int NINF = 0xcfcfcfcf;
int size(const int * arr) {
	int sz = n + 1;
	while (sz && arr[sz - 1] == NINF) --sz;
	return sz;
}
void convo(const int * A, const int * B, int * dst) {
	static int tmp[MAXN];
	const int lsz = size(A), rsz = size(B);
	const int sz = lsz + rsz - 1;
	memset(tmp, 0xcf, sz << 2);
	for (int i = 0; i < lsz; ++i)
		for (int j = 0; j < rsz; ++j)
			gma(tmp[i + j], A[i] + B[j]);
	for (int i = 0; i < sz; ++i)
		gma(dst[i], tmp[i]);
	// memcpy(dst, tmp, sz << 2);
}
int dfs(int u) {
	int rr = 0;
	dp[u][0][0] = 0;
	dp[u][1][1] = 0;
	dp[u][2][0] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			if (dep[to[i]]) {
				if (dep[to[i]] < dep[u]) rr = i;
			} else {
				dep[to[i]] = dep[u] + 1;
				fa[to[i]] = u;
				int ret = dfs(to[i]);
				if (ret && dep[to[ret]] < dep[u]) rr = ret;
			}
		}
	if (!fa[u]) return 0;
	if (!rr) {
		static int tmp[3][MAXN];
		memset(tmp, 0xcf, sizeof tmp);
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				if ((j | k) != 3)
					convo(dp[fa[u]][j], dp[u][k], tmp[j]);
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k <= n; ++k)
				gma(dp[fa[u]][j][k], tmp[j][k]);
	} else if (to[rr] == fa[u]) {
		static int f[2][3][MAXN];
		for (int i = 0; i != 3; ++i) {
			memset(f, 0xcf, sizeof f);
			int now = 0, lst = 1;
			f[now][i][0] = 0;
			int v = to[rr ^ 1];
			while (v != fa[u]) {
				std::swap(now, lst);
				for (int j = 0; j < 3; ++j)
					for (int k = 0; k < 3; ++k)
						if ((j | k) != 3)
							convo(f[lst][j], dp[v][k], f[now][k]);
				v = fa[v];
			}
			static int tmp[MAXN];
			memset(tmp, 0xcf, sizeof tmp);
			for (int j = 0; j < 3; ++j)
				if ((i | j) != 3)
					convo(dp[fa[u]][i], f[now][j], tmp);
			for (int j = 0; j <= n; ++j)
				gma(dp[fa[u]][i][j], tmp[j]);
		}
	}
	return rr;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	memset(dp, 0xcf, sizeof dp);
	std::cin >> n >> m;
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e);
	dfs(dep[1] = 1);
	for (int i = 0; i <= n; ++i) {
		int t = 0;
		for (int j = 0; j < 3; ++j)
			gma(t, dp[1][j][i]);
		std::cout << t << (" \n" [i == n]);
	}
	return 0;
}