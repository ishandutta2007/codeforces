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

const int N = 1e5 + 10;

set<int> g[N], components;
vector<int> in[N];
int par[N];

int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	int ans = n - 1;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		components.insert(i);
		in[i].pb(i);
	}
	for (int i = 1; i <= n; ++i) {
		vector<int> to_merge;
		for (auto &j : components) {
			if (j >= i) {
				break;
			}
			for (auto &u : in[j]) {
				if (!g[i].count(u)) {
					to_merge.pb(j);
					break;
				}
			}
		}
		for (auto &u : to_merge) {
			merge(i, u);
			--ans;
		}
	}
	cout << ans << '\n';
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (in[u].size() < in[v].size()) {
		swap(u, v);
	}
	for (auto &w : in[v]) {
		in[u].pb(w);
	}
	in[v].clear();
	par[v] = u;
	components.erase(v);
}