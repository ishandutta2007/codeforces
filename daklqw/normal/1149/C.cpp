#include <bits/stdc++.h>

const int MAXN = 200010;
int n, Q;
struct node {
	int ma, mi;
	int lm, rm, mm;
	friend node operator + (node a, node b) {
		node r;
		r.ma = std::max(a.ma, b.ma);
		r.mi = std::min(a.mi, b.mi);
		r.lm = std::max(a.ma - b.mi * 2, std::max(a.lm, b.lm));
		r.rm = std::max(b.ma - a.mi * 2, std::max(a.rm, b.rm));
		r.mm = std::max(std::max(a.lm + b.ma, b.rm + a.ma), std::max(a.mm, b.mm));
		return r;
	}
} tree[MAXN << 2];
int tag[MAXN << 2];
void mkadd(int x, int v) {
	tree[x].ma += v, tree[x].mi += v;
	tree[x].lm -= v, tree[x].rm -= v;
	tag[x] += v;
}
void pushdown(int x) {
	if (int & t = tag[x]) {
		mkadd(x << 1, t);
		mkadd(x << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
char buf[MAXN];
void mkeff(int i, int c) {
	if (buf[i] == '(') mdf(1, 1, n, i + 1, n, c);
	else mdf(1, 1, n, i + 1, n, -c);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q >> buf + 1; n = (n - 1) * 2 + 1;
	for (int i = 1; i < n; ++i) mkeff(i, 1);
	std::cout << tree[1].mm << '\n';
	while (Q --> 0) {
		int x, y; std::cin >> x >> y;
		mkeff(x, -1), mkeff(y, -1);
		std::swap(buf[x], buf[y]);
		mkeff(x, 1), mkeff(y, 1);
		std::cout << tree[1].mm << '\n';
	}
	return 0;
}