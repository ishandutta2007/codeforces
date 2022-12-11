#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
struct info {
	LL hav[10];
	void set(info a, info b) {
		for (int i = 0; i != 10; ++i)
			hav[i] = a.hav[i] + b.hav[i];
	}
	LL operator () () {
		LL res = 0;
		for (int i = 1; i != 10; ++i)
			res += i * hav[i];
		return res;
	}
} tree[MAXN << 2];
struct perf {
	int to[10];
	bool hav() {
		for (int i = 0; i != 10; ++i) if (to[i] != i) return true;
		return false;
	}
} tag[MAXN << 2], ori;
int A[MAXN], n, Q;
void build(int u, int l, int r) {
	tag[u] = ori;
	if (l == r) {
		int now = 1;
		for (int i = 0; i != 10 && now <= A[l]; ++i, now *= 10)
			tree[u].hav[A[l] / now % 10] += now;
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	tree[u].set(tree[u << 1], tree[u << 1 | 1]);
}
void mkset(int u, perf t) {
	static LL nv[10];
	static int nt[10];
	memset(nv, 0, 80);
	memset(nt, 0, 40);
	for (int i = 0; i < 10; ++i)
		nv[t.to[i]] += tree[u].hav[i];
	for (int i = 0; i < 10; ++i)
		nt[i] = t.to[tag[u].to[i]];
	memcpy(tree[u].hav, nv, 80);
	memcpy(tag[u].to, nt, 40);
}
void pushdown(int u) {
	if (tag[u].hav()) {
		mkset(u << 1, tag[u]);
		mkset(u << 1 | 1, tag[u]);
		tag[u] = ori;
	}
}
perf tmp;
void mdf(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return mkset(u, tmp);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R);
	tree[u].set(tree[u << 1], tree[u << 1 | 1]);
}
LL qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u]();
	int mid = l + r >> 1; LL res = 0;
	pushdown(u);
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res += qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	for (int i = 0; i != 10; ++i) ori.to[i] = i;
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	build(1, 1, n);
	while (Q --> 0) {
		int opt, l, r, x, y;
		std::cin >> opt >> l >> r;
		if (opt == 1) {
			std::cin >> x >> y;
			tmp = ori, tmp.to[x] = y;
			mdf(1, 1, n, l, r);
		} else std::cout << qry(1, 1, n, l, r) << '\n';
	}
	return 0;
}