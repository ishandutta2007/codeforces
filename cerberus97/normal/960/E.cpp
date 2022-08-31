/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, mod = 1e9 + 7;

vector<int> g[N];
ll v[N], sz[N], ctr[N][2];
bool par[N];

void dfs1(int cur);
ll dfs2(int cur);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, w;
		cin >> u >> w;
		g[u].pb(w);
		g[w].pb(u);
	}
	dfs1(1);
	cout << dfs2(1);
}

void dfs1(int cur) {
	bool p = par[cur];
	sz[cur] = ctr[cur][p] = 1;
	for (auto &i : g[cur]) {
		if (!sz[i]) {
			par[i] = !p;
			dfs1(i);
			sz[cur] += sz[i];
			ctr[cur][p] += ctr[i][p];
			ctr[cur][!p] += ctr[i][!p];
		}
	}
}

ll dfs2(int cur) {
	bool p = par[cur];
	ll ans = v[cur], temp = 0;
	temp += (ctr[1][p] - ctr[cur][p]) * sz[cur];
	temp -= (ctr[1][!p] - ctr[cur][!p]) * sz[cur];
	temp += sz[1] - 1;
	temp %= mod;
	for (auto &i : g[cur]) {
		if (sz[i] < sz[cur]) {
			ans += dfs2(i);
			temp += (ctr[i][p] - ctr[i][!p]) * (sz[1] - sz[i]);
			temp %= mod;
		}
	}
	ans += (temp * v[cur]);
	ans %= mod;
	ans += mod;
	ans %= mod;
	return ans;
}