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

const int N = 2e5 + 10, B = 20, M = (1 << B) + 10;

vector<int> g[N];
int sz[N], par[N], ent[N], ext[N], at[N], nxt = 1;
int mask[N], rmask[N], cnt[M];
ll upd[N], upd_mask[M];

int dfs_sz(int u, int p);
void dfs_times(int u);
void dfs_solve(int u, bool keep);
void process(int v, int u);
void add(int v);
void dfs_pushup(int u);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		mask[i + 1] = (1 << (s[i] - 'a'));
	}
	dfs_sz(1, 0);
	dfs_times(1);
	dfs_solve(1, 0);
	dfs_pushup(1);
	for (int u = 1; u <= n; ++u) {
		cout << upd[u] << ' ';
	}
	cout << endl;
}

int dfs_sz(int u, int p) {
	if (p) {
		g[u].erase(find(g[u].begin(), g[u].end(), p));
	}
	par[u] = p;
	rmask[u] = mask[u] ^ rmask[p];
	sz[u] = 1;
	for (auto& v : g[u]) {
		sz[u] += dfs_sz(v, u);
		if (sz[v] > sz[g[u][0]]) {
			swap(v, g[u][0]);
		}
	}
	reverse(g[u].begin(), g[u].end());
	return sz[u];
}

void dfs_times(int u) {
	at[nxt] = u;
	ent[u] = nxt++;
	for (auto& v : g[u]) {
		dfs_times(v);
	}
	ext[u] = nxt;
}

void dfs_solve(int u, bool keep) {
	for (auto& v : g[u]) {
		dfs_solve(v, v == g[u].back());
	}
	for (auto& v : g[u]) {
		if (v != g[u].back()) {
			for (int t = ent[v]; t < ext[v]; ++t) {
				int w = at[t];
				process(w, u);
			}
			for (int t = ent[v]; t < ext[v]; ++t) {
				int w = at[t];
				add(w);
			}
		}
	}
	add(u);
	process(u, u);
	if (!keep) {
		for (int t = ent[u]; t < ext[u]; ++t) {
			int v = at[t];
			upd[v] += upd_mask[rmask[v]];
			--cnt[rmask[v]];
		}
		for (int t = ent[u]; t < ext[u]; ++t) {
			int v = at[t];
			upd_mask[rmask[v]] = 0;
		}
	}
}

void process(int v, int u) {
	int cur = rmask[v] ^ mask[u];
	upd[v] += cnt[cur];
	upd[u] -= cnt[cur];
	upd[par[u]] -= cnt[cur];
	++upd_mask[cur];
	for (int i = 0; i < B; ++i) {
		upd[v] += cnt[cur ^ (1 << i)];
		upd[u] -= cnt[cur ^ (1 << i)];
		upd[par[u]] -= cnt[cur ^ (1 << i)];
		++upd_mask[cur ^ (1 << i)];
	}
}

void add(int v) {
	int cur = rmask[v];
	upd[v] -= upd_mask[cur];
	++cnt[cur];
}

void dfs_pushup(int u) {
	for (auto& v : g[u]) {
		dfs_pushup(v);
		upd[u] += upd[v];
	}
}