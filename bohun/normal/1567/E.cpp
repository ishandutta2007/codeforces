//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

template<class node>
struct segment_tree {
	int n;
	vector<node> t;
	segment_tree(int n) : n(n), t(4 << __lg(n)) {}
	segment_tree(vector<node> init) : segment_tree(init.size()) {
		function<void(int, int, int)> build = [&](int u, int l, int r) {
			if (l == r) {
				t[u] = init[l];
				return;
			}
			int m = (l + r) / 2;
			build(2 * u, l, m);
			build(2 * u + 1, m + 1, r);
			t[u] = t[2 * u] + t[2 * u + 1];
		};
		build(1, 0, n - 1);
	}
	void modify(int u, int l, int r, int x, const node &p) {
		if (l == r) {
			t[u] = p;
			return;
		}
		int m = (l + r) / 2;
		if (x <= m)
			modify(2 * u, l, m, x, p);
		else
			modify(2 * u + 1, m + 1, r, x, p);
		t[u] = t[2 * u] + t[2 * u + 1];
	}
	void modify(int x, const node &p) {
		modify(1, 0, n - 1, x, p);
	}
	node query(int u, int l, int r, int x, int y) {
		if (y < l || r < x)
			return node();
		if (x <= l && r <= y) 
			return t[u];
		int m = (l + r) / 2;
		return query(2 * u, l, m, x, y) + query(2 * u + 1, m + 1, r, x, y);
	}
	node query(int x, int y) {
		return query(1, 0, n - 1, x, y);
	}
}; 

struct node {
	ll l, r, res, full;
	node() : l(0), r(0), res(0), full(1) {}
	node(int x) : l(x), r(x), res(x), full(x) {}
	friend node operator+ (node a, node b) {
		node c;
		c.res = a.res + b.res + a.r * b.l;
		c.l = (a.full ? a.l + b.l : a.l);
		c.r = (b.full ? a.r + b.r : b.r);
		c.full = (a.full && b.full);
		return c;
	}
};

const int N = 1 << 18;

int n, q, a[N];
segment_tree<node> T(N);

void modify(int x) {
	if (0 <= x && x + 1 < n) {
		T.modify(x, (a[x] <= a[x + 1]));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> q;
	FOR(i, n) 
		cin >> a[i];
	FOR(i, n - 1) 
		modify(i);

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			a[x] = y;
			modify(x - 1);
			modify(x);
		}
		else {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << T.query(l, r - 1).res + (r - l + 1) << '\n';
		}
	}

	return 0;
}