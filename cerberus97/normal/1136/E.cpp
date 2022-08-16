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

const int N = 1e5 + 10;
const ll inf = 1e18 + 42;

ll a[N], k[N], s[N], tree[4 * N], lazy[4 * N];
set<int> pos;

void update(int i, int l, int r, int ql, int qr, ll x);
ll query(int i, int l, int r, int ql, int qr);
void propagate(int i, int l, int r);
void add(int i, ll x);
void sub(int i, ll x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 1, n, i, i, a[i]);
	}
	for (int i = 1; i <= n - 1; ++i) {
		cin >> k[i];
		s[i] = (a[i + 1] - a[i]) - k[i];
	}
	s[n] = inf;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != 0) {
			pos.insert(i);
		}
	}
	int q; cin >> q;
	while (q--) {
		char c; cin >> c;
		if (c == '+') {
			int i; ll x;
			cin >> i >> x;
			if (i > 1) {
				add(i - 1, x);
			}
			while (x) {
				if (s[i] != 0) {
					update(1, 1, n, i, i, x);
					ll temp = min(x, s[i]);
					x -= temp;
					sub(i, temp);
					++i;
				} else {
					int j = *pos.upper_bound(i) - 1;
					update(1, 1, n, i, j, x);
					i = j + 1;
				}
			}
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}

void update(int i, int l, int r, int ql, int qr, ll x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		lazy[i] += x;
		tree[i] += (r - l + 1) * x;
	} else {
		propagate(i, l, r);
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

ll query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		propagate(i, l, r);
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}

void propagate(int i, int l, int r) {
	int lc = 2 * i, rc = lc + 1;
	int mid = (l + r) / 2;
	lazy[lc] += lazy[i];
	lazy[rc] += lazy[i];
	tree[lc] += (mid - l + 1) * lazy[i];
	tree[rc] += (r - mid) * lazy[i];
	lazy[i] = 0;
}

void add(int i, ll x) {
	if (s[i] == 0) {
		pos.insert(i);
	}
	s[i] += x;
}

void sub(int i, ll x) {
	if (s[i] == x) {
		pos.erase(i);
	}
	s[i] -= x;
}