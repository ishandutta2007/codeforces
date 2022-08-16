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

const int N = 2e5 + 10;

bool is_leaf[N];
int leaves[N], buds[N], tot_leaves[N];
vector<int> g[N];

void dfs(int u, int p);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1, 0);
		int ans = tot_leaves[1];
		if (leaves[1]) {
			ans -= (buds[1]);
		} else {
			ans -= (buds[1] - 1);
		}
		cout << ans << '\n';
	}
}

void dfs(int u, int p) {
	is_leaf[u] = true;
	leaves[u] = buds[u] = tot_leaves[u] = 0;
	for (auto& v : g[u]) {
		if (v == p) {
			continue;
		}
		is_leaf[u] = false;
		dfs(v, u);
		if (is_leaf[v]) {
			++leaves[u];
			++tot_leaves[u];
		} else {
			buds[u] += buds[v];
			tot_leaves[u] += tot_leaves[v] - leaves[v];
			if (leaves[v]) {
				++buds[u];
				tot_leaves[u] += leaves[v];
			} else {
				++leaves[u];
				++tot_leaves[u];
			}
		}
	}
}