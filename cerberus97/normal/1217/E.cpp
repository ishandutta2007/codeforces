/* cerberus97 - Hanit Banga */
 
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int N = 2e5 + 10, D = 10;
const ll inf = 2e9 + 42;
 
int a[N], t[N], qa[N], qb[N];
pii tree[D][4 * N];
 
void set_val(int i, int val, int n);
void update(int i, int l, int r, int p, int val, int mask);
pii query(pii *tree, int i, int l, int r, int ql, int qr);
pii combine(pii t1, pii t2);
 
int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		set_val(i, a[i], n);
	}
	for (int i = 1; i <= m; ++i) {
		// int t; cin >> t;
		cin >> t[i] >> qa[i] >> qb[i];
	}
	for (int i = 1; i <= m; ++i) {
		if (t[i] == 1) {
			int p = qa[i], x = qb[i];
			a[p] = x;
			set_val(p, x, n);
		} else {
			int l = qa[i], r = qb[i];
			ll best = inf;
			for (int d = 0; d < D; ++d) {
				pll q = query(tree[d], 1, 1, n, l, r);
				best = min(best, q.first + q.second);
			}
			if (best >= inf) {
				cout << -1 << '\n';
			} else {
				cout << best << '\n';
			}
		}
	}
}
 
void set_val(int i, int val, int n) {
	int mask = 0;
	for (int d = 0; d < D; ++d) {
		if (val % 10) {
			// update(tree[d], 1, 1, n, i, a[i]);
			mask |= (1 << d);
		} else {
			// update(tree[d], 1, 1, n, i, inf);
		}
		val /= 10;
	}
	update(1, 1, n, i, a[i], mask);
}
 
void update(int i, int l, int r, int p, int val, int mask) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		for (int d = 0; d < D; ++d) {
			if (mask & (1 << d)) {
				tree[d][i] = {val, inf};
			} else {
				tree[d][i] = {inf, inf};
			}
		}
		// tree[i] = {val, inf};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, val, mask);
		update(rc, mid + 1, r, p, val, mask);
		for (int d = 0; d < D; ++d) {
			tree[d][i] = combine(tree[d][lc], tree[d][rc]);		
		}
	}
}
 
pii query(pii *tree, int i, int l, int r, int ql, int qr) {
	if (ql > r or l > qr) {
		return {inf, inf};
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return combine(query(tree, lc, l, mid, ql, qr), query(tree, rc, mid + 1, r, ql, qr));
	}
}
 
pii combine(pii t1, pii t2) {
	if (t1 > t2) {
		swap(t1, t2);
	}
	t1.second = min(t1.second, t2.first);
	return t1;
}