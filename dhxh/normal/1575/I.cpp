#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define lc t[p].lchild
#define rc t[p].rchild
using namespace std;
const int maxn = 210000;
int cur, root, dfn, dep[maxn], siz[maxn], pa[maxn], id[maxn], son[maxn], top[maxn];
long long ans, A[maxn], val[maxn];
vector<int> G[maxn];
struct segment {
	int l, r, lchild, rchild;
	long long sum, add;
}t[maxn * 4];
inline void maintain(int p) {
	t[p].sum = t[lc].sum + t[rc].sum;
}
inline void mark(int p, long long addv) { //
	if (addv) {
		t[p].add += addv;
		t[p].sum += addv * (t[p].r - t[p].l + 1);
	}
}
inline void pushdown(int p) { //pushdown
	mark(lc, t[p].add);
	mark(rc, t[p].add);
	t[p].add = 0;
}
int build(int L, int R) {
	int p = ++cur;
	t[p].l = L;
	t[p].r = R;
	t[p].add = 0;
	if (L == R) {
		mark(p, val[L]);
	}
	else {
		int mid = (L + R) >> 1;
		lc = build(L, mid);
		rc = build(mid + 1, R);
		maintain(p);
	}
	return p;
}
void update(int p, int L, int R, long long v) {
	if (L <= t[p].l && R >= t[p].r) {
		mark(p, v);
	}
	else {
		pushdown(p); //pushdownmaintain
		int mid = (t[p].l + t[p].r) >> 1;
		if (L <= mid)
			update(lc, L, R, v);
		if (R > mid)
			update(rc, L, R, v);
		maintain(p);
	}
}
void query(int p, int L, int R) {
	if (L <= t[p].l && R >= t[p].r) {
		ans += t[p].sum;
	}
	else {
		pushdown(p);
		int mid = (t[p].l + t[p].r) >> 1;
		if (L <= mid)
			query(lc, L, R);
		if (R > mid)
			query(rc, L, R);
	}
}
void dfs1(int x, int fa, int d) {
	dep[x] = d;
	siz[x] = 1;
	son[x] = 0;
	pa[x] = fa;
	for (auto y : G[x]) if (y != fa) {
		dfs1(y, x, d + 1);
		siz[x] += siz[y];
		if (siz[son[x]] < siz[y])
			son[x] = y;
	}
}
void dfs2(int x, int tp) {
	top[x] = tp;
	id[x] = ++dfn; //id[x]xDFS
	if (son[x])
		dfs2(son[x], tp);
	for (auto y : G[x])
		if (y != pa[x] && y != son[x])
			dfs2(y, y);
}
long long ask(int x, int y) {
	::ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		query(root, id[top[x]], id[x]);
		x = pa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	query(root, id[x], id[y]);
	return ans;
}
void add(int x, int y, int v) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		update(root, id[top[x]], id[x], v);
		x = pa[top[x]];
	}
	//if (x == y) return ans;
	if (dep[x] > dep[y]) swap(x, y);
	update(root, id[x], id[y], v); //id[son[x]]
}
void init(int n) { //
	cur = dfn = siz[0] = 0;
	dfs1(1, -1, 1); //sdfs1(s, -1, 1), dfs2(s, s);
	dfs2(1, 1);
	for (int i = 1; i <= n; ++i)
		val[id[i]] = A[i]; //A[i]iDFS
	::root = build(1, n);
}
int n, q;
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &A[i]);
	for (int i = 1; i <= n; ++i)
		A[i] = abs(A[i]);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	init(n);
	while (q--) {
		int tp, x, y;
		scanf("%d %d %d", &tp, &x, &y);
		if (tp == 1) {
			long long delta = abs(y) - A[x];
			add(x, x, delta);
			A[x] = abs(y);
		}
		else if (tp == 2) {
			long long answer = ask(x, y) * 2 - A[x] - A[y];
			printf("%lld\n", answer);
		}
	}
	return 0;
}