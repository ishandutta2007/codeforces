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

const int N = 1e5 + 10;

vector<pii> g[N];
bool seen1[N], seen2[N][2];
ll c[N], ans[N];

void dfs1(int u);
bool dfs2(int u, bool b, ll add);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}
	dfs1(1);
	bool ok = true;
	if (c[1] and !dfs2(1, 0, c[1] / 2)) {
		ok = false;
	}
	if (ok) {
		cout << "YES\n";
		for (int i = 1; i <= m; ++i) {
			cout << ans[i] << '\n';
		}
	} else {
		cout << "NO\n";
	}
}

void dfs1(int u) {
	seen1[u] = true;
	for (auto& e : g[u]) {
		int v = e.first, id = e.second;
		if (seen1[v]) {
			continue;
		}
		dfs1(v);
		ans[id] = c[v];
		c[u] -= c[v];
		c[v] = 0;
	}
}

bool dfs2(int u, bool b, ll add) {
	if (u == 1 and b) {
		return true;
	}
	seen2[u][b] = true;
	for (auto& e : g[u]) {
		int v = e.first, id = e.second;
		if (seen2[v][b ^ 1]) {
			continue;
		}
		ans[id] += add;
		if (dfs2(v, b ^ 1, -add)) {
			return true;
		}
		ans[id] -= add;
	}
	return false;
}