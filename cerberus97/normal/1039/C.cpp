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

const int N = 5e5 + 10, mod = 1e9 + 7;
const ll inf = (1ll << 62);

struct edge {
	int u, v; ll val;
	bool operator<(const edge &o) const {
		return val < o.val;
	}
};

vector<edge> edges;
vector<int> g[N];
set<int> used;
ll c[N], p2[N];
bool seen[N];

ll solve(ll n);
void dfs(int u);

int main() {
	fast_cin();
	p2[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edges.pb({u, v, c[u] ^ c[v]});
	}
	ll ans = (p2[n] * p2[k]) % mod;
	edges.pb({0, 0, inf});
	sort(edges.begin(), edges.end());
	int st = 0;
	for (int i = 0; i <= m; ++i) {
		if (edges[i].val != edges[st].val) {
			ans -= solve(n);
			ans += mod;
			ans %= mod;
			for (auto &u : used) {
				g[u].clear();
				seen[u] = false;
			}
			used.clear();
			st = i;
		}
		used.insert(edges[i].u);
		used.insert(edges[i].v);
		g[edges[i].u].pb(edges[i].v);
		g[edges[i].v].pb(edges[i].u);
	}
	cout << ans;
}

ll solve(ll n) {
	ll m = used.size();
	ll ans = p2[m];
	ll comp = 0;
	for (auto &u : used) {
		if (!seen[u]) {
			++comp;
			dfs(u);
		}
	}
	ans += mod - p2[comp];
	ans %= mod;
	ans *= p2[n - m];
	return ans % mod;
}

void dfs(int u) {
	seen[u] = true;
	for (auto &v : g[u]) {
		if (!seen[v]) {
			dfs(v);
		}
	}
}