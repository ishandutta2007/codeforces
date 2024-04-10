/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define mp make_pair
const int N = 301234, SegN = (1 << 20);
pii seg[SegN];
int lz[SegN];
int a[N], n;

pii merge (pii p, pii q) {
	if (p.F == q.F) 
		return mp(p.F, q.S + p.S);
	else if (p.F < q.F)
		return p;
	else
		return q;
}

void shift (int v) {
	if (!lz[v])
		return;
	lz[v << 1] += lz[v];
	lz[v << 1 | 1] += lz[v];
	seg[v << 1].F += lz[v];
	seg[v << 1 | 1].F += lz[v];
	lz[v] = 0;
}

void add (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (r < tl || tr < l)
		return;
	if (l <= tl && tr <= r) {
		lz[v] += x;
		seg[v].F += x;
		return;
	}
	shift (v);
	int mid = (tl + tr) >> 1;
	add (l, r, x, v << 1, tl, mid);
	add (l, r, x, v << 1 | 1, mid + 1, tr);
	seg[v] = merge(seg[v << 1], seg[v << 1 | 1]);
}

void build (int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) 
		seg[v] = mp(tl, 1);
	else {
		int mid = (tl + tr) >> 1;
		build (v << 1, tl, mid);
		build (v << 1 | 1, mid + 1, tr);
		seg[v] = merge(seg[v << 1], seg[v << 1 | 1]);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x] = y;
	}
	build ();
	vector <int> mn, mx;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		add (1, n, -1);
		while (!mn.empty() && a[mn.back()] > a[i]) {
			int r = mn.back();
			mn.pop_back();
			int l = (mn.empty() ? 1 : mn.back() + 1);
			add (l, r, a[r] - a[i]);
		}
		while (!mx.empty() && a[mx.back()] < a[i]) {
			int r = mx.back();
			mx.pop_back();
			int l = (mx.empty() ? 1 : mx.back() + 1);
			add (l, r, a[i] - a[r]);
		}
		mn.push_back(i);
		mx.push_back(i);
		ans += seg[1].S;
	}
	cout << ans;
}