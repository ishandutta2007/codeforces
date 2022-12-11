#include <bits/stdc++.h>

const int MAXN = 200010;
int n, Q;
void gma(int & x, int y) { x < y ? x = y : 0; }
struct sgt1 {
	int tree[MAXN << 2];
	void mdf(int tar, int v, int u = 1, int l = 1, int r = n) {
		if (l == r) return (void) (tree[u] = v);
		int mid = l + r >> 1;
		if (tar <= mid) mdf(tar, v, u << 1, l, mid);
		else mdf(tar, v, u << 1 | 1, mid + 1, r);
		tree[u] = std::max(tree[u << 1], tree[u << 1 | 1]);
	}
	int qry(int L, int R, int u = 1, int l = 1, int r = n) {
		if (L <= l && r <= R) return tree[u];
		int mid = l + r >> 1, res = 0;
		if (L <= mid) res = qry(L, R, u << 1, l, mid);
		if (mid < R) gma(res, qry(L, R, u << 1 | 1, mid + 1, r));
		return res;
	}
} mat;
struct info {
	int mi, cnt, atl, atr;
	friend info operator + (info a, info b) {
		if (a.mi == b.mi) {
			a.cnt += b.cnt;
			if (b.atl) a.cnt += mat.qry(a.atr + 1, b.atl);
			a.atr = b.atr;
			return a;
		}
		return a.mi < b.mi ? a : b;
	}
} tree[MAXN << 2];
int tag[MAXN << 2];
void mkadd(int u, int v) {
	tree[u].mi += v, tag[u] += v;
}
void pushdown(int u) {
	if (int & t = tag[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int L, int R, int v, int u = 1, int l = 1, int r = n) {
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(L, R, v, u << 1, l, mid);
	if (mid < R) mdf(L, R, v, u << 1 | 1, mid + 1, r);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
void attach(int tar, int u = 1, int l = 1, int r = n) {
	if (l == r) {
		tree[u] = (info) {tag[u], 0, l, l};
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (tar <= mid) attach(tar, u << 1, l, mid);
	else attach(tar, u << 1 | 1, mid + 1, r);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
std::set<int> at[MAXN];
int A[MAXN];
int L[MAXN], R[MAXN];
void upd(int x) {
	if (L[x] && R[x]) {
		mat.mdf(L[x], 0);
		attach(L[x]);
		if (L[x] < R[x]) mdf(L[x], R[x] - 1, -1);
	}
	L[x] = R[x] = 0;
	if (!at[x].empty()) {
		L[x] = *at[x].begin(), R[x] = *at[x].rbegin();
		mat.mdf(L[x], at[x].size());
		attach(L[x]);
		if (L[x] < R[x]) mdf(L[x], R[x] - 1, 1);
	}
}
int calc() {
	int res = n - tree[1].cnt;
	res -= mat.qry(1, tree[1].atl);
	if (tree[1].atr < n)
		res -= mat.qry(tree[1].atr + 1, n);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], at[A[i]].insert(i);
	for (int i = 1; i <= n; ++i) attach(i);
	for (int i = 1; i <= 200000; ++i) upd(i);
	std::cout << calc() << std::endl;
	while (Q --> 0) {
		int x, v; std::cin >> x >> v;
		if (A[x] != v) {
			at[A[x]].erase(x);
			at[v].insert(x);
			upd(A[x]), upd(v);
			A[x] = v;
		}
		std::cout << calc() << std::endl;
	}
	return 0;
}