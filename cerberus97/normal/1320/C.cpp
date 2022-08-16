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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, inf = 2e9 + 42;

ll tree[4 * N], lazy[4 * N];

void update(int i, int l, int r, int ql, int qr, ll val);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	int n, m, p;
	cin >> n >> m >> p;
	vector<pii> wp(n), ar(m);
	vector<pair<pii, pii>> mo(p);
	for (auto& i : wp) {
		cin >> i.first >> i.second;
	}
	for (auto& i : ar) {
		cin >> i.first >> i.second;
	}
	for (auto& i : mo) {
		cin >> i.first.second >> i.first.first >> i.second.first;
	}
	sort(wp.begin(), wp.end());
	sort(ar.begin(), ar.end());
	sort(mo.begin(), mo.end());
	for (int i = m - 2; i >= 0; --i) {
		ar[i].second = min(ar[i].second, ar[i + 1].second);
	}
	ar.pb({inf, inf});
	int j = 0;
	for (int i = 0; i < p; ++i) {
		while (j < m and ar[j].first <= mo[i].first.first) {
			++j;
		}
		update(1, 0, p - 1, i, i, -ar[j].second);
		swap(mo[i].first.first, mo[i].first.second);
		mo[i].second.second = i;
	}
	sort(mo.begin(), mo.end());
	ll best = -inf;
	j = 0;
	for (int i = 0; i < n; ++i) {
		while (j < p and mo[j].first.first < wp[i].first) {
			int id = mo[j].second.second, val = mo[j].second.first;
			update(1, 0, p - 1, id, p - 1, val);
			++j;
		}
		best = max(best, ll(-ar[0].second - wp[i].second));
		best = max(best, tree[1] - wp[i].second);
	}
	cout << best << '\n';
}

void update(int i, int l, int r, int ql, int qr, ll val) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += val;
		lazy[i] += val;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, val);
		update(rc, mid + 1, r, ql, qr, val);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc] += lazy[i];
	tree[rc] += lazy[i];
	lazy[lc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}