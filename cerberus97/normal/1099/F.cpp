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

const int N = 1e5 + 10, M = 1e6 + 10;
const ll inf = 1e18 + 42;

vector<pll> g[N];
ll x[N], t[N];
pll tree[4 * M];

ll dfs(int u, int n, ll T);
void update(int i, int l, int r, int p, ll x);
ll query(int i, int l, int r, ll T);

int main() {
	fast_cin();
	int n; ll T;
	cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	for (int i = 2; i <= n; ++i) {
		int p, l;
		cin >> p >> l;
		g[p].pb({i, l});
	}
	cout << dfs(1, n, T) << endl;
}

ll dfs(int u, int n, ll T) {
	if (T < 0) {
		return -inf;
	}
	update(1, 1, M, t[u], x[u]);
	vector<ll> children_vals;
	for (auto &e : g[u]) {
		children_vals.pb(dfs(e.first, n, T - 2 * e.second));
	}
	if (u == 1) {
		children_vals.pb(inf);
	}
	sort(children_vals.begin(), children_vals.end(), greater<ll>());
	ll ans = query(1, 1, M, T);
	if (children_vals.size() >= 2) {
		ans = max(ans, children_vals[1]);
	}
	update(1, 1, M, t[u], -x[u]);
	return ans;
}

void update(int i, int l, int r, int p, ll v) {
	tree[i].first += v;
	tree[i].second += v * p;
	if (l == r) {
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(lc, l, mid, p, v);
		} else {
			update(rc, mid + 1, r, p, v);
		}
	}
}

ll query(int i, int l, int r, ll T) {
	if (l == r) {
		return min(T / l, tree[i].first);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (T >= tree[lc].second) {
			return tree[lc].first + query(rc, mid + 1, r, T - tree[lc].second);
		} else {
			return query(lc, l, mid, T);
		}
	}
}