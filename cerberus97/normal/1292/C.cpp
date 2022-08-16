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

const int N = 3e3 + 10;

int n;
vector<int> g[N];
int sz[N];
bool seen[N][N];
ll dp[N][N];

void dfs(int u, int p);
ll solve(int u, int v, int pu, int pv);
ll get_size(int u, int par);

int main() {
	fast_cin();
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	ll ans = 0;
	for (int u = 1; u <= n; ++u) {
		ans = max(ans, solve(u, u, 0, 0));
	}
	cout << ans << endl;
}

void dfs(int u, int p) {
	sz[u] = 1;
	for (auto& v : g[u]) {
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}

ll solve(int u, int v, int pu, int pv) {
	if (seen[u][v]) {
		return dp[u][v];
	} else {
		seen[u][v] = true;
		ll& ans = dp[u][v];
		ans = 0;
		for (auto& x : g[u]) {
			if (x == pu) {
				continue;
			}
			int npu = u, npv = (pv == 0 ? x : pv);
			ans = max(ans, get_size(x, u) * get_size(v, npv) + solve(x, v, npu, npv));
		}
		for (auto& y : g[v]) {
			if (y == pv) {
				continue;
			}
			int npu = (pu == 0 ? y : pu), npv = v;
			ans = max(ans, get_size(u, npu) * get_size(y, v) + solve(u, y, npu, npv));
		}
		return ans;
	}
}

ll get_size(int u, int par) {
	if (sz[par] > sz[u]) {
		return sz[u];
	} else {
		return n - sz[par];
	}
}