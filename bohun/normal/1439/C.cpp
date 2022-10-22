#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int T = 1 << 18;

int n, q, a[T];

struct SegmentTree {
	struct Node {
		ll mn, sum, tag;
	} t[2 * T];
	void pull(int v) {
		t[v].mn = min(t[2 * v].mn, t[2 * v + 1].mn);
		t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = {a[l], a[l], 0};
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m);
		build(2 * v + 1, m, r);
		pull(v);
	}
	void set(int v, int l, int r, ll val) {
		t[v].mn = val;
		t[v].sum = (r - l) * val;
		t[v].tag = val;
	}
	void push(int v, int l, int r) {
		if (t[v].tag) {
			int m = (l + r) / 2;
			set(2 * v, l, m, t[v].tag);
			set(2 * v + 1, m, r, t[v].tag);
			t[v].tag = 0;
		}
	}
	int bound(int v, int l, int r, int val) {
		if (r - l == 1) return t[v].mn <= val ? l : r;
		int m = (l + r) / 2;
		push(v, l, r);
		if (t[2 * v].mn <= val)
			return bound(2 * v, l, m, val);
		else
			return bound(2 * v + 1, m, r, val);
	} 
	void setrange(int v, int l, int r, int x, int y, int val) {
		if (l >= y || r <= x) return;
		if (l >= x && r <= y) return set(v, l, r, val);
		int m = (l + r) / 2;
		push(v, l, r);
		setrange(2 * v, l, m, x, y, val);
		setrange(2 * v + 1, m, r, x, y, val);
		pull(v);
	}
	void setrange(int x, int y) {
		int l = min(x, bound(1, 0, n, y));
		setrange(1, 0, n, l, x, y);
	}
	int query(int v, int l, int r, int x, int &y) {
		if (r <= x) return 0;
		if (t[v].mn > y) return 0;
		if (x <= l && t[v].sum <= y) {
			y -= t[v].sum;
			return r - l;
		}
		int m = (l + r) / 2, res = 0;
		push(v, l, r);
		res += query(2 * v, l, m, x, y);
		res += query(2 * v + 1, m, r, x, y);
		return res;
	}
	int query(int x, int y) {
		return query(1, 0, n, x, y);
	}
} tree;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	tree.build(1, 0, n);
	while (q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1)
			tree.setrange(x, y);
		else
			printf("%d\n", tree.query(--x, y));
	}
	return 0;
}