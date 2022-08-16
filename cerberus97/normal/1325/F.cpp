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

vector<int> g[N];
int deg[N], depth[N], par[N];
bool seen[N];

void dfs(int u);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int sq = sqrt(n) - 1;
	while (sq * sq < n) {
		++sq;
	}
	for (int u = 1; u <= n; ++u) {
		for (auto& v : g[u]) {
			if (depth[u] - depth[v] + 1 >= sq) {
				cout << 2 << '\n' << depth[u] - depth[v] + 1 << '\n';
				cout << u << ' ';
				for (int i = u; i != v; i = par[i]) {
					cout << par[i] << ' ';
				}
				cout << endl;
				return 0;
			}
		}
	}
	vector<int> leaves, ind_set;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			leaves.pb(i);
		}
	}
	vector<bool> bad(n + 1, false);
	while (!leaves.empty()) {
		auto u = leaves.back();
		leaves.pop_back();
		--deg[par[u]];
		if (deg[par[u]] == 1) {
			leaves.pb(par[u]);
		}
		if (!bad[u]) {
			ind_set.pb(u);
			for (auto& v : g[u]) {
				bad[v] = true;
			}
		}
	}
	cout << 1 << '\n';
	assert(int(ind_set.size()) >= sq);
	ind_set.resize(sq);
	for (auto& i : ind_set) {
		cout << i << ' ';
	}
	cout << endl;
}

void dfs(int u) {
	seen[u] = true;
	for (auto& v : g[u]) {
		if (!seen[v]) {
			par[v] = u;
			++deg[u]; ++deg[v];
			depth[v] = depth[u] + 1;
			dfs(v);
		}
	}
}