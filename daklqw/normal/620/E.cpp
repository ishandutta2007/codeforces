#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 400010;
typedef long long LL;
LL tree[MAXN << 2], tag[MAXN << 2];
void pushdown(int u) {
	if (tag[u]) {
		tree[u << 1] = 1LL << tag[u];
		tree[u << 1 | 1] = 1LL << tag[u];
		tag[u << 1] = tag[u];
		tag[u << 1 | 1] = tag[u];
		tag[u] = 0;
	}
}
void modify(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		tree[u] = 1LL << v;
		tag[u] = v;
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) modify(u << 1, l, mid, L, R, v);
	if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] | tree[u << 1 | 1];
}
LL query(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; LL res = 0;
	pushdown(u);
	if (L <= mid) res |= query(u << 1, l, mid, L, R);
	if (mid < R) res |= query(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
inline void addedge(int b, int e) {
	nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
	nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
}
int n, dfn[MAXN], col[MAXN], sz[MAXN], t0t, Q, t1, t2, opt;
int dfs(int u, int fa) {
	sz[u] = 1; dfn[u] = ++t0t;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa) sz[u] += dfs(to[i], u);
	return sz[u];
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
	for (int i = 1; i != n; ++i) {
		scanf("%d%d", &t1, &t2);
		addedge(t1, t2);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) modify(1, 1, n, dfn[i], dfn[i], col[i]);
	while (Q --> 0) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d", &t1, &t2);
			modify(1, 1, n, dfn[t1], dfn[t1] + sz[t1] - 1, t2);
		} else {
			scanf("%d", &t1);
			printf("%d\n", __builtin_popcountll(query(1, 1, n, dfn[t1], dfn[t1] + sz[t1] - 1)));
		}
	}

	return 0;
}