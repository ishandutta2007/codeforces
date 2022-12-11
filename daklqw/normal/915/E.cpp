#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 300010;
const int MAXNODE = MAXN * 60;
int tree[MAXNODE], ls[MAXNODE], rs[MAXNODE], tot;
char tag[MAXNODE];

void pushdown(int u, int sz) {
	if (~tag[u]) {
		if (!ls[u]) ls[u] = ++tot;
		if (!rs[u]) rs[u] = ++tot;
		tree[ls[u]] = tag[u] * (sz + 1 >> 1);
		tree[rs[u]] = tag[u] * (sz >> 1);
		tag[ls[u]] = tag[u];
		tag[rs[u]] = tag[u];
		tag[u] = -1;
	}
}
int modify(int u, int l, int r, int L, int R, int v) {
	if (!u) u = ++tot;
	if (L <= l && r <= R) {
		tree[u] = v * (r - l + 1);
		tag[u] = v;
		return u;
	}
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	if (L <= mid) ls[u] = modify(ls[u], l, mid, L, R, v);
	if (mid < R) rs[u] = modify(rs[u], mid + 1, r, L, R, v);
	tree[u] = tree[ls[u]] + tree[rs[u]];
	return u;
}
int n, Q, t1, t2, t3, rt;
int main() {
	memset(tag, -1, sizeof tag);
	scanf("%d%d", &n, &Q);
	rt = modify(rt, 1, n, 1, n, 1);
	while (Q --> 0) {
		scanf("%d%d%d", &t1, &t2, &t3);
		modify(rt, 1, n, t1, t2, t3 - 1);
		printf("%d\n", tree[rt]);
	}
	return 0;
}