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

const int N = 5e5 + 10, P = 2 * N;
const ll inf = 1e15 + 42;

map<int, int> mp;
vector<pll> at[P];
ll x[N], y[N], c[N], rev[P];
pll tree[4 * P];
ll lazy[4 * P];

void build_tree(int i, int l, int r);
void update(int i, int l, int r, int ql, int qr, ll val);
pll query(int i, int l, int r, int ql, int qr);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> c[i];
		if (x[i] > y[i]) {
			swap(x[i], y[i]);
		}
		mp[x[i]];
		mp[y[i]];
	}
	int lid = 0;
	for (auto &i : mp) {
		i.second = ++lid;
		rev[i.second] = i.first;
	}
	for (int i = 1; i <= n; ++i) {
		at[mp[x[i]]].pb({mp[y[i]], c[i]});
	}
	ll ans = 0;
	pii pt = {2e9, 2e9};
	build_tree(1, 1, lid);
	for (int i = 1; i <= lid; ++i) {
		update(1, 1, lid, i, i, -rev[i]);
	}
	for (int x = lid; x >= 1; --x) {
		for (auto &p : at[x]) {
			int y = p.first, cost = p.second;
			update(1, 1, lid, y, lid, cost);
		}
		auto q = query(1, 1, lid, x, lid);
		if (q.first + rev[x] > ans) {
			ans = q.first + rev[x];
			pt = {rev[x], rev[q.second]};
		}
		// ans = max(ans, query(1, 1, lid, x, lid) - rev[x]);
	}
	cout << ans << '\n';
	cout << pt.first << ' ' << pt.first << ' ' << pt.second << ' ' << pt.second << endl;
}

void build_tree(int i, int l, int r) {
	if (l == r) {
		tree[i] = {0, l};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build_tree(lc, l, mid);
		build_tree(rc, mid + 1, r);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

void update(int i, int l, int r, int ql, int qr, ll val) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i].first += val;
		lazy[i] += val;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, val);
		update(rc, mid + 1, r, ql, qr, val);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

pll query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return {-inf, 0};
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		return max(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc].first += lazy[i];
	tree[rc].first += lazy[i];
	lazy[lc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}