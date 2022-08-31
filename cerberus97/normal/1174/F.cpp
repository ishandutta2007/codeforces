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

const int N = 2e5 + 10, LOG = log2(N) + 2;

vector<int> g[N];
int depth[N], sz[N], heavy_leaf[N];
int up[N][LOG];
int queries_left = 36;

void dfs(int u, int p);
int go_up(int u, int x);
int query(char c, int u);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	int d = query('d', 1);
	int u = 1;
	while (depth[u] != d) {
		int l = heavy_leaf[u];
		int v = go_up(l, (depth[l] + query('d', l) - d) / 2);
		if (depth[v] == d) {
			u = v;
			break;
		} else {
			u = query('s', v);
		}
	}
	cout << "! " << u << endl;
}

void dfs(int u, int p) {
	up[u][0] = p;
	for (int j = 1; j < LOG; ++j) {
		up[u][j] = up[up[u][j - 1]][j - 1];
	}
	sz[u] = 1;
	heavy_leaf[u] = u;
	int cand = 0;
	for (auto &v : g[u]) {
		if (v == p) {
			continue;
		}
		depth[v] = depth[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > cand) {
			cand = sz[v];
			heavy_leaf[u] = heavy_leaf[v];
		}
	}
}

int go_up(int u, int x) {
	for (int j = LOG - 1; j >= 0; --j) {
		if ((1 << j) <= x) {
			x -= (1 << j);
			u = up[u][j];
		}
	}
	return u;
}

int query(char c, int u) {
	if (!queries_left) {
		assert(0);
	}
	--queries_left;
	cout << c << ' ' << u << endl;
	int ans; cin >> ans;
	return ans;
}