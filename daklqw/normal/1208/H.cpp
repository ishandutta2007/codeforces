#include <bits/stdc++.h>

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int fa[MAXN], top[MAXN], son[MAXN], sz[MAXN];
int dfn[MAXN], t0t, down[MAXN], dep[MAXN];

namespace splay {
	int son[MAXN][2], fa[MAXN], val[MAXN];
	inline int get(int x, int b = 1) { return son[fa[x]][b] == x; }
	inline int isroot(int x) { return !fa[x]; }
	int sz[MAXN];
	void update(int x) {
		if (x) sz[x] = sz[son[x][0]] + 1 + sz[son[x][1]];
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y]; bool b = get(x);
		if (!isroot(y)) son[z][get(y)] = x;
		son[y][b] = son[x][!b], son[x][!b] = y;
		fa[x] = z, fa[y] = x; if (son[y][b]) fa[son[y][b]] = y;
		update(y);
	}
	void splay(int x, int & rt, int to = 0) {
		for (; fa[x] != to; rotate(x)) if (fa[fa[x]] != to)
			rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
		update(x);
		if (!to) rt = x;
	}
	int st[MAXN], top, idx;
	int newnode(int v, int f = 0) {
		int now = top ? st[top--] : ++idx;
		val[now] = v, fa[now] = f, sz[now] = 1;
		return now;
	}
	void delnode(int u) {
		son[u][0] = son[u][1] = 0;
		st[++top] = u;
	}
	int rightmost(int u) {
		while (son[u][1]) u = son[u][1];
		return u;
	}
	struct splaytree {
		int rt;
		void ins(int v) {
			if (!rt) return (void) (rt = newnode(v));
			int u = rt;
			while (true) {
				bool b = val[u] <= v;
				if (son[u][b]) { u = son[u][b];  continue; }
				splay(son[u][b] = newnode(v, u), rt);
				break;
			}
		}
		void del(int v) {
			int u = rt;
			while (true) {
				if (val[u] == v) {
					splay(u, rt);
					int x = son[u][0], y = son[u][1];
					delnode(u), fa[x] = fa[y] = 0;
					if (x && y) {
						int p = rightmost(x); fa[y] = p;
						splay(son[p][1] = y, rt);
					} else rt = x | y;
					break;
				} else u = son[u][val[u] < v];
			}
		}
		int calc(int B, int dd) {
			int u = rt, lst = 0, all = dd + sz[u];
			int al = -INF, ar = INF, ax = B;
			while (u) {
				lst = u;
				int tb = B + sz[son[u][1]] + 1;
				if (tb * 2 - all >= val[u])
					al = val[u], u = son[u][1], ax = tb - 1;
				else {
					ar = val[u]; ax = tb;
					B += sz[son[u][1]] + 1, u = son[u][0];
				}
			}
			splay(lst, rt);
			int res = std::max(std::min(ar, 2 * ax - all), al);
			return res;
		}
	} ;
}
splay::splaytree rt[MAXN];

void dfs(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dep[to[i]] = dep[u] + 1;
			sz[u] += sz[to[i]];
			fa[to[i]] = u;
			dfs(to[i]);
			sz[u] += sz[to[i]];
			if (sz[to[i]] > sz[son[u]]) son[u] = to[i];
		}
}
void hld(int u) {
	dfn[u] = ++t0t;
	if (son[u])
		top[son[u]] = top[u], hld(son[u]), down[u] = down[son[u]];
	else down[u] = u;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			top[to[i]] = to[i], hld(to[i]);
}
struct info {
	int l0, l1;
	inline int operator () (int x) {
		return l1 <= x ? l1 : std::max(l0, x);
	}
	friend info operator + (info a, info b) {
		return (info) {a(b.l0), a(b.l1)};
	}
} tree[MAXN << 2];
void mdf(int u, int l, int r, int tar, info t) {
	if (l == r) return (void) (tree[u] = t);
	int mid = l + r >> 1;
	if (tar <= mid) mdf(u << 1, l, mid, tar, t);
	else mdf(u << 1 | 1, mid + 1, r, tar, t);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
info qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; info res;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) {
		info t = qry(u << 1 | 1, mid + 1, r, L, R);
		res = L <= mid ? res + t : t;
	}
	return res;
}
int inter[MAXN], A[MAXN], n;

void calc(int u) {
	info tar;
	if (down[u] == u) {
		int t = A[u] == -1 ? rt[u].calc(0, 0) : (A[u] ? INF : -INF);
		tar = (info) {t, t};
	} else
		tar = (info) {rt[u].calc(0, 1), rt[u].calc(1, 1)};
	mdf(1, 1, n, dfn[u], tar);
}
void updtop(int u, bool flg = true) {
	u = top[u];
	if (fa[u] && flg) rt[fa[u]].del(inter[u]);
	inter[u] = qry(1, 1, n, dfn[u], dfn[down[u]]).l0;
	if (fa[u]) rt[fa[u]].ins(inter[u]);
}
void build(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) build(to[i]);
	calc(u);
	if (u == top[u]) updtop(u, false);
}
void mdf(int u, int v) {
	A[u] = v;
	while (u) calc(u), updtop(u), u = fa[top[u]];
}
int qry(int u, int v) {
	info t = qry(1, 1, n, dfn[u], dfn[down[u]]);
	return v <= t.l0;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int K, Q; std::cin >> n >> K;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	dfs(1); hld(top[1] = 1); build(1);
	std::cin >> Q;
	while (Q --> 0) {
		int opt, u, v;
		std::cin >> opt >> u;
		if (opt == 1) std::cout << qry(u, K) << '\n';
		else if (opt == 2) std::cin >> v, mdf(u, v);
		else K = u;
	}
	return 0;
}