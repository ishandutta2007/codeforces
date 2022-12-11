#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAXN = 200010;
struct Q {
	int l, r, K, bel, id;
	inline bool operator < (const Q & b) const {
		return bel == b.bel ?  r < b.r : bel < b.bel;
	}
} qs[MAXN];
#define BLO 350
int col[MAXN], n, m, t1, t2, bak, idfn[MAXN], ansl[MAXN], cnt[MAXN], tree[MAXN];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, sz[MAXN], dfn[MAXN], t0t;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
int dfs(int u, int fa) {
	sz[u] = 1; idfn[dfn[u] = ++t0t] = u;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa) sz[u] += dfs(to[i], u);
	return sz[u];
}
void add(int a, int v) {
	if (cnt[a] > 0) for (int x = cnt[a]; x; x -= x & -x) --tree[x];
	cnt[a] += v;
	if (cnt[a] > 0) for (int x = cnt[a]; x; x -= x & -x) ++tree[x];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
	for (int i = 1; i != n; ++i) scanf("%d%d", &t1, &t2), addedge(t1, t2);
	dfs(1, 0);
	for (int i = 1; i <= m; ++i) scanf("%d%d", &t1, &t2), qs[++bak] = (Q) {dfn[t1], dfn[t1] + sz[t1] - 1, t2, dfn[t1] / BLO, i} ;
	std::sort(qs + 1, qs + 1 + m);
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i) {
		int L = qs[i].l, R = qs[i].r;
		while (l > L) add(col[idfn[--l]], 1);
		while (r < R) add(col[idfn[++r]], 1);
		while (l < L) add(col[idfn[l++]], -1);
		while (r > R) add(col[idfn[r--]], -1);
		int ans = 0;
		for (int x = qs[i].K; x <= n; x += x & -x) ans += tree[x];
		ansl[qs[i].id] = ans;
	}
	for (int i = 1; i <= m; ++i) printf("%d\n", ansl[i]);
	return 0;
}