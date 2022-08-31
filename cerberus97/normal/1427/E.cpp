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

const int N = 2e6 + 10;

struct op_t {
	ll x, y;
	char type;
};

void solve(ll x);
void add(vector<ll>& b, ll x);
void dfs(ll u);

vector<op_t> ops;
map<ll, pll> g;
set<ll> seen;

int main() {
	fast_cin();
	ll x; cin >> x;
	solve(x);
	seen.insert(x);
	dfs(1);
	cout << ops.size() << '\n';
	for (auto& op : ops) {
		cout << op.x << ' ' << op.type << ' ' << op.y << '\n';
	}
}

void solve(ll x) {
	vector<ll> basis = {x};
	g[x] = {0, 0};
	for (ll i = 2; i < N; ++i) {
		if (!g.count(i * x)) {
			g[i * x] = {(i / 2) * x, ((i + 1) / 2) * x};
		}
		add(basis, i * x);
		if (*(basis.rbegin()) == 1) {
			return;
		}
	}
}

void add(vector<ll>& b, ll x) {
	vector<op_t> tmp;
	for (auto& i : b) {
		if ((x ^ i) < x) {
			if (!g.count(x ^ i)) {
				g[x ^ i] = {x, i};
			}
			x = (x ^ i);
		}
	}
	if (x) {
		b.pb(x);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
	}
}

void dfs(ll u) {
	if (seen.count(u)) {
		return;
	}
	dfs(g[u].first);
	dfs(g[u].second);
	seen.insert(u);
	if (g[u].first + g[u].second == u) {
		ops.pb({g[u].first, g[u].second, '+'});
	} else {
		ops.pb({g[u].first, g[u].second, '^'});
	}
}