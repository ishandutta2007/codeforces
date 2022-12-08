#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m, sum, alarm;
int head[MAXN], fa[MAXN], sz[MAXN], dep[MAXN], dfn[MAXN], top[MAXN], son[MAXN];
struct Edge { int link, to; } e[MAXN << 1];
inline void add(int u, int v) { e[++sum] = (Edge) { v, head[u] }, head[u] = sum; }
template <int N>
struct SegmentTree {
	#define lc ((x) << 1)
	#define rc ((x) << 1 | 1)
	static const int M = N << 2;
	int col[M], tag[M];
	inline void pushDown(int x) { if (~tag[x]) { col[lc] = col[rc] = tag[lc] = tag[rc] = tag[x], tag[x] = -1; } }
	void build(int x, int L, int R) {
		tag[x] = -1, col[x] = 0;
		if (L == R) return;
		int mid = L + R >> 1;
		return build(lc, L, mid), build(rc, mid + 1, R);
	}
	void update(int x, int L, int R, int ql, int qr, int val) {
		if (ql <= L && R <= qr) { col[x] = tag[x] = val; return; }
		int mid = L + R >> 1; pushDown(x);
		if (ql <= mid) update(lc, L, mid, ql, qr, val);
		if (qr > mid) update(rc, mid + 1, R, ql, qr, val);
		return;
	}
	int query(int x, int L, int R, int pos) {
		if (L == R) return col[x];
		int mid = L + R >> 1; pushDown(x);
		return pos <= mid ? query(lc, L, mid, pos) : query(rc, mid + 1, R, pos);
	}
	#undef lc
	#undef rc
};
SegmentTree <MAXN> Tr;
void dfs1(int u, int fafa) {
	sz[u] = 1, dep[u] = dep[fafa] + 1, fa[u] = fafa;
	for (int i = head[u]; i; i = e[i].to) {
		int v = e[i].link;
		if (v == fafa) continue;
		dfs1(v, u), sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
	return;
}
void dfs2(int u, int tp) {
	top[u] = tp, dfn[u] = ++alarm;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = e[i].to) {
		int v = e[i].link;
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
	return;
}
inline void change(int u) {
	for (; u; u = fa[top[u]]) Tr.update(1, 1, n, dfn[top[u]], dfn[u], 0);
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), add(u, v), add(v, u);
	dfs1(1, 0), dfs2(1, 1), Tr.build(1, 1, n);
	scanf("%d", &m);
	for (int opt, x; m --> 0;) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) Tr.update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, 1);
		if (opt == 2) change(x);
		if (opt == 3) printf("%d\n", Tr.query(1, 1, n, dfn[x]));
	}
	return 0;
}