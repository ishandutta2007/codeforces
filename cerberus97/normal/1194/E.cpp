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

const int N = 5e3 + 10;

struct segment {
	int x1, y1, x2, y2;
	bool operator<(const segment &o) const {
		return x1 < o.x1;
	}
};

segment a[N];
int tree[8 * N];

void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, int ql, int qr);
ll c2(ll x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		if (a[i].x1 > a[i].x2) {
			swap(a[i].x1, a[i].x2);
		}
		if (a[i].y1 > a[i].y2) {
			swap(a[i].y1, a[i].y2);
		}
	}
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i].x1 == a[i].x2) {
			vector<pii> hz;
			memset(tree, 0, sizeof(tree));
			for (int j = 1; j <= n; ++j) {
				if (a[j].y1 == a[j].y2 and a[j].x1 <= a[i].x1) {
					hz.pb({a[j].x2, a[j].y1});
					update(1, -N, N, a[j].y1, 1);
				}
			}
			sort(hz.begin(), hz.end());
			vector<segment> vt;
			for (int j = 1; j <= n; ++j) {
				if (a[j].x1 == a[j].x2 and a[j].x1 > a[i].x1) {
					vt.push_back(a[j]);
				}
			}
			int p = 0, sz = hz.size();
			for (auto &seg : vt) {
				while (p < sz and hz[p].first < seg.x1) {
					update(1, -N, N, hz[p].second, -1);
					++p;
				}
				int lo = max(a[i].y1, seg.y1);
				int hi = min(a[i].y2, seg.y2);
				if (lo <= hi) {
					ans += c2(query(1, -N, N, lo, hi));
				}
			}
		}
	}
	cout << ans << endl;
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] += x;
	} else {
		int mid = l + (r - l) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = l + (r - l) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}

ll c2(ll x) {
	return (x * (x - 1)) / 2;
}