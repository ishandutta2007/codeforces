#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN], fa[MAXN];
int n, Q;
int sz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], idx;
void dfs(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		dfs(i);
		sz[u] += sz[i];
		if (sz[i] > sz[son[u]]) son[u] = i;
	}
}
void hld(int u) {
	dfn[u] = ++idx;
	if (son[u]) top[son[u]] = top[u], hld(son[u]);
	for (int i = head[u]; i; i = nxt[i])
		if (i != son[u])
			top[i] = i, hld(i);
}
struct node {
	int v, s;
	node operator + (node b) {
		node res;
		res.v = v + b.v;
		res.s = std::max(b.s, s + b.v);
		return res;
	}
} tree[MAXN << 2], tag[MAXN << 2];
const int NINF = 0xcfcfcfcf;
node emp = (node) {0, NINF};
void mkset(int u, int len, node v) {
	tag[u] = v;
	tree[u].v = len * v.v;
	tree[u].s = std::max(tag[u].v, tree[u].v);
}
void pushdown(int u, int len) {
	if (tag[u].v != 0 || tag[u].s != NINF) {
		mkset(u << 1, len + 1 >> 1, tag[u]);
		mkset(u << 1 | 1, len >> 1, tag[u]);
		tag[u] = emp;
	}
}
node qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; node res = emp;
	pushdown(u, r - l + 1);
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void mdf(int u, int l, int r, int L, int R, node v) {
	if (L <= l && r <= R) return mkset(u, r - l + 1, v);
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
void add(int x, int v) {
	node t = qry(1, 1, n, dfn[x], dfn[x]);
	t.v += v, t.s += v;
	mdf(1, 1, n, dfn[x], dfn[x], t);
}
node qry(int x) {
	node t = emp;
	while (x) t = qry(1, 1, n, dfn[top[x]], dfn[x]) + t, x = fa[top[x]];
	return t;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 2; i <= n; ++i)
		std::cin >> fa[i], nxt[i] = head[fa[i]], head[fa[i]] = i;
	dfs(1); top[1] = 1, hld(1);
	mkset(1, n, (node) {-1, -1});
	while (Q --> 0) {
		int opt, x;
		std::cin >> opt >> x;
		if (opt == 1) add(x, 1);
		else if (opt == 2) {
			mdf(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, (node) {-1, -1});
			node t = qry(x);
			add(x, -1 - t.s);
		} else std::cout << (qry(x).s >= 0 ? "black\n" : "white\n");
	}
	return 0;
}