#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;

int d[N], a[N];

void build(int u, int l, int r) {
	if (l == r) {
		d[u] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	d[u] = __gcd(d[u + u], d[u + u + 1]);
}

void update(int u, int l, int r, int p, int x) {
	if (l == r) {
		d[u] = a[l];
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) update(u + u, l, mid, p, x);
	else update(u + u + 1, mid + 1, r, p, x);
	d[u] = __gcd(d[u + u], d[u + u + 1]);
}

int query(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return d[u];
	int ret = 0;
	int mid = l + r >> 1;
	if (ll <= mid) ret = __gcd(ret, query(u + u, l, mid, ll, rr));
	if (mid < rr) ret = __gcd(ret, query(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

int find_first(int u, int l, int r, int p, int x) {
	if (l == r) {
		if (d[u] % x != 0) return l;
		return r + 1;
	}
	if (l >= p) {
		if (d[u] % x == 0) return r + 1;
		int mid = l + r >> 1;
		int t = find_first(u + u, l, mid, p, x);
		if (t <= mid) return t;
		return find_first(u + u + 1, mid + 1, r, p, x);
	}
	int mid = l + r >> 1;
	if (p <= mid) {
		int t = find_first(u + u, l, mid, p, x);
		if (t <= mid) return t;
	}
	return find_first(u + u + 1, mid + 1, r, p, x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			int last = find_first(1, 1, n, l, x);
//			cerr << last << endl;
			int ans = 1;
			if (last < r) {
//				cerr << query(1, 1, n, last+1, r) << ' ' << x << endl;
				ans = (query(1, 1, n, last+1, r) % x == 0);
			}
			puts(ans ? "YES" : "NO");
		} else {
			int i, x; scanf("%d%d", &i, &x);
			a[i] = x;
			update(1, 1, n, i, x);
		}
	}
	return 0;
}