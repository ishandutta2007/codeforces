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

const int N = 3e5 + 10;

void dfs(int v, int p);

int parent[N], sz[N];
vector<int> g[N];

int main() {
	fast_cin();
	ll n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(x, 0);
	ll s1 = sz[y];
	while (parent[y] != x) {
		y = parent[y];
	}
	ll s2 = n - sz[y];
	cout << n * (n - 1) - s1 * s2;
}

void dfs(int v, int p) {
	parent[v] = p;
	sz[v] = 1;
	for (auto &u : g[v]) {
		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}