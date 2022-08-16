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

const int N = 2e5 + 10, mod = 1e9 + 7;

ll a[N], w[N], tree[4 * N][2];

void update(int i, int l, int r, int p, ll w);
ll query0(int i, int l, int r, int ql, int qr);
ll query1(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		update(1, 1, n, i, w[i]);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			update(1, 1, n, -x, y);
			w[-x] = y;
		} else {
			int l = x, r = y, i = -1;
			while (x <= y) {
				int mid = (x + y) / 2;
				ll z1 = query0(1, 1, n, l, mid - 1);
				ll z2 = query0(1, 1, n, mid + 1, r);
				if (w[mid] < z2 - z1) {
					x = mid + 1;
				} else if (w[mid] < z1 - z2) {
					y = mid - 1;
				} else {
					i = mid;
					break;
				}
			}
			ll ans = query1(1, 1, n, i + 1, r) + ((i - a[i]) * (query0(1, 1, n, i + 1, r) % mod)) % mod;
			ans   -= query1(1, 1, n, l, i - 1) + ((i - a[i]) * (query0(1, 1, n, l, i - 1) % mod)) % mod;
			cout << ((ans % mod) + mod) % mod << '\n';
		}
	}
}

void update(int i, int l, int r, int p, ll nw) {
	if (l == r) {
		tree[i][0] = nw;
		tree[i][1] = (nw * (a[p] - p)) % mod;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(lc, l, mid, p, nw);
		} else {
			update(rc, mid + 1, r, p, nw);
		}
		tree[i][0] = (tree[lc][0] + tree[rc][0]);
		tree[i][1] = (tree[lc][1] + tree[rc][1]) % mod;
	}
}

ll query0(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i][0];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query0(lc, l, mid, ql, qr) + query0(rc, mid + 1, r, ql, qr);
	}
}

ll query1(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i][1];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query1(lc, l, mid, ql, qr) + query1(rc, mid + 1, r, ql, qr);
	}
}