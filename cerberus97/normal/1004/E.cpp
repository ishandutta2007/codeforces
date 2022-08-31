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

const int N = 1e5 + 10, inf = 1e9 + 42;

struct edge {
	int v; ll len;
};

vector<edge> g[N];
ll max_depth[N], max_up[N], path_len[N], n, k;
bool check;

void dfs1(int u, int p);
void dfs2(int u, int p);
void dfs3(int u, int p, ll t);

int main() {
	fast_cin();
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v; ll d;
		cin >> u >> v >> d;
		g[u].pb({v, d});
		g[v].pb({u, d});
	}
	dfs1(1, 0);
	dfs2(1, 0);
	ll lo = 0, hi = inf;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		check = false;
		dfs3(1, 0, mid);
		if (check) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << hi + 1;
}

void dfs1(int u, int p) {
	for (auto &e : g[u]) {
		if (e.v != p) {
			dfs1(e.v, u);
			max_depth[u] = max(max_depth[u], e.len + max_depth[e.v]);
		}
	}
}

void dfs2(int u, int p) {
	multiset<int> cand;
	cand.insert(max_up[u]);
	for (auto &e : g[u]) {
		if (e.v != p) {
			cand.insert(e.len + max_depth[e.v]);
		}
	}
	for (auto &e : g[u]) {
		if (e.v != p) {
			cand.erase(cand.find(e.len + max_depth[e.v]));
			max_up[e.v] = e.len + *cand.rbegin();
			cand.insert(e.len + max_depth[e.v]);
		}
	}
	cand.clear();
	for (auto &e : g[u]) {
		if (e.v != p) {
			dfs2(e.v, u);
		}
	}
}

void dfs3(int u, int p, ll t) {
	int ctr = 0;
	path_len[u] = 1;
	for (auto &e : g[u]) {
		if (e.v != p) {
			dfs3(e.v, u, t);
			if (e.len + max_depth[e.v] > t) {
				++ctr;
				path_len[u] = 1 + path_len[e.v];
			}
		}
	}
	if (ctr > 1) {
		path_len[u] = k + 1;
	}
	ctr = 0;
	if (max_up[u] > t) {
		return;
	}
	ll need = 1;
	for (auto &e : g[u]) {
		if (e.v != p) {
			if (e.len + max_depth[e.v] > t) {
				++ctr;
				need += path_len[e.v];
			}
		}
	}
	if (ctr <= 2 and need <= k) {
		check = true;
	}
}