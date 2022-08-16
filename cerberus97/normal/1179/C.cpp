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

const int N = 3e5 + 10, A = 1e6 + 10;

int a[N], b[N];
int tree[4 * A], lazy[4 * A];

void update(int i, int l, int r, int ql, int qr, int x);
void propagate(int i, int lc, int rc);
int query(int i, int l, int r);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 1, A, 1, a[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		update(1, 1, A, 1, b[i], 1);
	}
	int q; cin >> q;
	while (q--) {
		int t, i, x;
		cin >> t >> i >> x;
		if (t == 1) {
			update(1, 1, A, 1, a[i], 1);
			a[i] = x;
			update(1, 1, A, 1, a[i], -1);
		} else {
			update(1, 1, A, 1, b[i], -1);
			b[i] = x;
			update(1, 1, A, 1, b[i], 1);
		}
		cout << query(1, 1, A) << '\n';
	}
}

void update(int i, int l, int r, int ql, int qr, int x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += x;
		lazy[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		tree[i] = min(tree[lc], tree[rc]);
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc] += lazy[i];
	lazy[lc] += lazy[i];
	tree[rc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}

int query(int i, int l, int r) {
	if (tree[i] >= 0) {
		return -1;
	} else if (l == r) {
		return l;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		if (tree[rc] < 0) {
			return query(rc, mid + 1, r);
		} else {
			return query(lc, l, mid);
		}
	}
}