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

const int N = 1e3 + 10;

vector<int> g[N];
int par[N], d[N];

void dfs(int u);
int ask(char c, int x);
void answer(int x);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		par[1] = 0;
		d[1] = 0;
		dfs(1);
		int k1; cin >> k1;
		set<int> x_nodes, y_nodes;
		for (int i = 0; i < k1; ++i) {
			int x; cin >> x;
			x_nodes.insert(x);
		}
		int k2; cin >> k2;
		for (int i = 0; i < k2; ++i) {
			int y; cin >> y;
			y_nodes.insert(y);
		}
		int my_root = *x_nodes.begin();
		for (auto &x : x_nodes) {
			if (d[x] < d[my_root]) {
				my_root = x;
			}
		}
		int my_root_other = ask('A', my_root);
		if (y_nodes.find(my_root_other) != y_nodes.end()) {
			answer(my_root);
			continue;
		}
		int x_cand = ask('B', *y_nodes.begin());
		while (x_cand != 1 and x_nodes.find(x_cand) == x_nodes.end()) {
			x_cand = par[x_cand];
		}
		int y_cand = ask('A', x_cand);
		if (x_nodes.find(x_cand) != x_nodes.end() and y_nodes.find(y_cand) != y_nodes.end()) {
			answer(x_cand);
		} else {
			answer(-1);
		}
	}
}

void dfs(int u) {
	for (auto &v : g[u]) {
		if (v != par[u]) {
			par[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
		}
	}
}

int ask(char c, int x) {
	cout << c << ' ' << x << endl;
	int ans; cin >> ans;
	return ans;
}

void answer(int x) {
	cout << "C " << x << endl;
}