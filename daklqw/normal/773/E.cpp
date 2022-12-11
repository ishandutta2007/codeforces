#include <bits/stdc++.h>

const int MAXN = 1000010;
const int INF = 0x3f3f3f3f;
struct info {
	// min(x + a, b)
	int a, b;
	friend info operator + (info a, info b) {
		return (info) {a.a + b.a, std::min(a.b + b.a, b.b)};
	}
	int operator () (int x) const { return std::min(x + a, b); }
} ;
info emp = (info) {0, INF};
struct seg {
	info tree[MAXN << 2];
	void mdf(int u, int l, int r, int tar, info v) {
		if (l == r) return (void) (tree[u] = v);
		int mid = l + r >> 1;
		if (tar <= mid) mdf(u << 1, l, mid, tar, v);
		else mdf(u << 1 | 1, mid + 1, r, tar, v);
		tree[u] = tree[u << 1] + tree[u << 1 | 1];
	}
	info qry(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) return tree[u];
		int mid = l + r >> 1; info res = emp;
		if (L <= mid) res = qry(u << 1, l, mid, L, R);
		if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
		return res;
	}
	int pre(int u, int l, int r, info now) {
		if (l == r) {
			now = now + tree[u];
			return now.a <= now.b ? l : l - 1;
		}
		int mid = l + r >> 1;
		info t = now + tree[u << 1];
		if (t.a <= t.b)
			return pre(u << 1 | 1, mid + 1, r, t);
		return pre(u << 1, l, mid, now);
	}
} le, ma;
std::map<int, int> val;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	const int R = 500000;
	for (int i = -R; i <= R; ++i) {
		if (i > 0) le.mdf(1, 1, R, i, emp);
		ma.mdf(1, -R, R, i, emp);
	}
	int n; std::cin >> n;
	for (int T = 1, t; T <= n; ++T) {
		std::cin >> t; ++val[t];
		if (t < 0)
			le.mdf(1, 1, R, R + t + 1, (info) {val[t], -t});
		ma.mdf(1, -R, R, t, (info) {val[t], t});
		int at = le.pre(1, 1, R, emp);
		int now = at ? -le.qry(1, 1, R, 1, at)(0) : 0;
		// std::cout << "DBG " << now << ' ' << at << std::endl;
		now = ma.qry(1, -R, R, at - R, R)(now);
		std::cout << now << '\n';
	}
	return 0;
}