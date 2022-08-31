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

const int N = 1e6 + 10, C = (1 << 20) + 10;

vector<int> g[N];
vector<pii> tmp, have[C];
bool seen[N];
int par[N];

void setup(int n, vector<int>& c, int mask);
void dfs(int u);
void dfs2(int u, int id, vector<int>& c);
int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> c(2 * n);
	for (auto& i : c) {
		cin >> i;
	}
	int lo = 1, hi = 20;
	while (lo <= hi) {
		int mid = (lo + hi) / 2, mask = (1 << mid) - 1;
		setup(n, c, mask);
		int cur = -1, id = -1, sz = 0;
		bool ok = true;
		for (int i = 0; i < 2 * n; ++i) {
			if (tmp[i].first == cur) {
				++sz;
				g[id].pb(tmp[i].second);
				g[tmp[i].second].pb(id);
			} else {
				ok &= (sz % 2 == 0);
				sz = 1;
				id = tmp[i].second;
				cur = tmp[i].first;
			}
		}
		ok &= (sz % 2 == 0);
		dfs(0);
		for (int i = 0; i < 2 * n; ++i) {
			ok &= seen[i];
		}
		if (ok) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << (lo - 1) << '\n';
	int mask = (1 << (lo - 1)) - 1;
	setup(n, c, mask);
	vector<int> partner(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		// cout << tmp[i].second + 1 << ' ' << tmp[i ^ 1].second + 1 << endl;
		partner[tmp[i].second] = tmp[i ^ 1].second;
		g[tmp[i].second].pb(tmp[i ^ 1].second);
		c[i] &= mask;
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (!seen[i]) {
			dfs2(i, i, c);
		}
	}
	for (int col = 0; col < C; ++col) {
		while (have[col].size() >= 2) {
			auto t1 = have[col].back(); have[col].pop_back();
			auto t2 = have[col].back(); have[col].pop_back();
			int id1 = t1.first, id2 = t2.first;
			// cout << "HERE " << id1 + 1 << ' ' << id2 + 1 << endl;
			id1 = get_root(id1);
			id2 = get_root(id2);
			if (id1 == id2) {
				have[col].pb({id1, t1.second});
				continue;
			}
			merge(id1, id2);
			int u1 = t1.second, v1 = partner[u1];
			int u2 = t2.second, v2 = partner[u2];
			partner[u1] = u2;
			partner[u2] = u1;
			partner[v1] = v2;
			partner[v2] = v1;
			have[col].pb({get_root(id1), u1});
		}
	}
	int s = 0;
	for (int i = 0; i < n; ++i) {
		cout << (s + 1) << ' ' << ((s ^ 1) + 1) << ' ';
		s = partner[s ^ 1];
	}
}

void setup(int n, vector<int>& c, int mask) {
	tmp.resize(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		g[i].clear();
		g[i].pb(i ^ 1);
		seen[i] = false;
		tmp[i] = {c[i] & mask, i};
		// cout << (i + 1) << ' ' << (c[i] & mask) << endl;
	}
	// cout << "DONE" << endl;
	sort(tmp.begin(), tmp.end());
}

void dfs(int u) {
	seen[u] = true;
	for (auto& v : g[u]) {
		if (!seen[v]) {
			dfs(v);
		}
	}
}

void dfs2(int u, int id, vector<int>& c) {
	seen[u] = true;
	par[u] = id;
	if (have[c[u]].empty() or have[c[u]].back().first != id) {
		have[c[u]].pb({id, u});
	}
	for (auto& v : g[u]) {
		if (!seen[v]) {
			dfs2(v, id, c);
		}
	}
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
	if (u != v) {
		par[v] = u;
	}
}