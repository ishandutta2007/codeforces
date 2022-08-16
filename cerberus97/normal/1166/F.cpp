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

set<int> vertex_list[N], comp_list[N];
map<pii, int> edges;
int sz[N], par[N];

void add_edge(int u, int v, int c);
int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int n, m, t, q;
	cin >> n >> m >> t >> q;
	for (int i = 1; i <= n; ++i) {
		sz[i] = 1;
		par[i] = i;
	}
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		add_edge(u, v, c);
	}
	while (q--) {
		char type; cin >> type;
		if (type == '+') {
			int u, v, c;
			cin >> u >> v >> c;
			add_edge(u, v, c);
		} else {
			int u, v;
			cin >> u >> v;
			u = get_root(u);
			if (u == get_root(v) or comp_list[v].find(u) != comp_list[v].end()) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}

void add_edge(int u, int v, int c) {
	int c1 = edges[{u, c}];
	int c2 = edges[{v, c}];
	edges[{u, c}] = v;
	edges[{v, c}] = u;
	if (c1) {
		merge(c1, v);
	}
	if (c2) {
		merge(c2, u);
	}
	comp_list[u].insert(get_root(v));
	comp_list[v].insert(get_root(u));
	vertex_list[get_root(u)].insert(v);
	vertex_list[get_root(v)].insert(u);
}

int get_root(int u) {
	if (par[u] != u) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return;
	}
	if (sz[u] < sz[v]) {
		swap(u, v);
	}
	sz[u] += sz[v];
	par[v] = u;
	for (auto &w : vertex_list[v]) {
		comp_list[w].erase(v);
		comp_list[w].insert(u);
		vertex_list[u].insert(w);
	}
	vertex_list[v].clear();
}