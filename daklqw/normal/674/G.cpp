#include <bits/stdc++.h>

const int MAXN = 150010;
int D;
struct val {
	int a[5], b[5];
	val() { memset(a, 0, 20); memset(b, 0, 20); }
	void append(int x, int v) {
		for (int i = 0; i < D; ++i) if (a[i] == x)
			return (void) (b[i] += v);
		for (int i = 0; i < D; ++i) if (a[i] == 0)
			return (void) (a[i] = x, b[i] = v);
		int t = std::min(*std::min_element(b, b + D), v);
		v -= t;
		for (int i = 0; i < D; ++i) if (a[i])
		{ b[i] -= t; if (b[i] == 0) a[i] = 0; }
		if (!v) return ;
		for (int i = 0; i < D; ++i) if (a[i] == 0)
			return (void) (a[i] = x, b[i] = v);
	}
	friend val operator + (val a, val b) {
		for (int i = 0; i != D; ++i) if (b.a[i]) a.append(b.a[i], b.b[i]);
		return a;
	}
} tree[MAXN << 2];
int tag[MAXN << 2];
void mkset(int u, int v, int l) {
	tree[u] = val(); tree[u].append(v, l);
	tag[u] = v;
}
void pushdown(int u, int l) {
	if (int & t = tag[u]) {
		mkset(u << 1, t, l + 1 >> 1);
		mkset(u << 1 | 1, t, l >> 1);
		t = 0;
	}
}
void modify(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkset(u, v, r - l + 1);
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	if (L <= mid) modify(u << 1, l, mid, L, R, v);
	if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
val qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	val res;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int n, m, K;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K; D = 100 / K;
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, modify(1, 1, n, i, i, t);
	while (m --> 0) {
		int opt, l, r, v;
		std::cin >> opt >> l >> r;
		if (opt == 1) {
			std::cin >> v;
			modify(1, 1, n, l, r, v);
		} else {
			val res = qry(1, 1, n, l, r);
			int cnt = 0;
			for (int i = 0; i != D; ++i) cnt += !!res.a[i];
			std::cout << cnt;
			for (int i = 0; i != D; ++i) if (res.a[i])
				std::cout << ' ' << res.a[i];
			std::cout << '\n';
		}
	}
	return 0;
}