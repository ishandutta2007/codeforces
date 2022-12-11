#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
	
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
const int UP = 320;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], dfn[MAXN], idfn[MAXN], dep[MAXN], tot, t0t, val[MAXN], sz[MAXN];
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
int t1, t2;
void dfs(int u, int fa) {
	sz[u] = 1;
	idfn[dfn[u] = ++t0t] = u;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa) {
		dep[to[i]] = dep[u] + 1;
		dfs(to[i], u);
		sz[u] += sz[to[i]];
	}
}
const int MAXNODE = 42000000;
// const int MAXNODE = 8000000;
int tree[MAXNODE], ls[MAXNODE], rs[MAXNODE], txt;
int rt[17][MAXN], lg2[MAXN], n, m, r;
int modify(int u, int l, int r, int tar, int v) {
	if (!u) tree[u = ++txt] = INF;
	if (l == r) {
		if (tree[u] > v) tree[u] = v;
		return u;
	}
	int mid = l + r >> 1;
	if (tar <= mid) ls[u] = modify(ls[u], l, mid, tar, v);
	else rs[u] = modify(rs[u], mid + 1, r, tar, v);
	tree[u] = std::min(tree[ls[u]], tree[rs[u]]);
	return u;
}
int merge(int x, int y) {
	if (!x || !y) return x | y;
	int now = ++txt;
	tree[now] = std::min(tree[x], tree[y]);
	ls[now] = merge(ls[x], ls[y]);
	rs[now] = merge(rs[x], rs[y]);
	return now;
}
int query(int u, int l, int r, int L, int R) {
	if (!u) return INF;
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1, res = INF;
	if (L <= mid) res = std::min(res, query(ls[u], l, mid, L, R));
	if (mid < R) res = std::min(res, query(rs[u], mid + 1, r, L, R));
	return res;
}
int getroot(int x, int y) {
	if (rt[x][y]) return rt[x][y];
	return rt[x][y] = merge(getroot(x - 1, y), getroot(x - 1, y + (1 << x - 1)));
}
int query2(int x, int y, int L, int R) {
	if (rt[x][y]) return query(rt[x][y], 1, n, L, R);
	return std::min(query2(x - 1, y, L, R), query2(x - 1, y + (1 << x - 1), L, R));
}
int main() {
	// freopen("aaa.in", "r+", stdin);
	tree[0] = INF;
	scanf("%d%d", &n, &r);
//	std::cerr << "OK0 " << n << " " << r << std::endl;
	lg2[0] = -1;
	for (int i = 1; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
//	std::cerr << "OK1 " << n << " " << r << std::endl;
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		addedge(t1, t2);
	}
//	std::cerr << "OK2 " << std::endl;
	dep[r] = 1; dfs(r, 0);
	for (int i = 1; i <= n; ++i) rt[0][i] = modify(rt[0][i], 1, n, dep[idfn[i]], val[idfn[i]]); 
	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= n - (1 << i - 1) + 1; ++j)
			rt[i][j] = merge(rt[i - 1][j], rt[i - 1][j + (1 << i - 1)]);
	std::cerr << "OK " << txt << std::endl;

	scanf("%d", &m);
	int lans = 0;
	while (m --> 0) {
		scanf("%d%d", &t1, &t2);
		t1 = (lans + t1) % n + 1; t2 = (lans + t2) % n;
		const int l = dfn[t1], r = dfn[t1] + sz[t1] - 1;
		const int lg = lg2[r - l + 1];
		if (txt < MAXNODE - 1000000) 
		printf("%d\n", lans = std::min(query(getroot(lg, l), 1, n, dep[t1], dep[t1] + t2),
								query(getroot(lg, r - (1 << lg) + 1), 1, n, dep[t1], dep[t1] + t2)));
		else printf("%d\n", lans = std::min(query2(lg, l, dep[t1], dep[t1] + t2), query2(lg, r - (1 << lg) + 1, dep[t1], dep[t1] + t2)));
	}
	std::cerr << "OK " << txt << std::endl;
	return 0;
}