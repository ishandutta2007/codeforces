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

const int N = 2e5 + 10, LOG = log2(N) + 2, inf = 1e9 + 42;

struct state {
	int turn, dist, id;
	bool operator<(const state& o) const {
		return tie(turn, id) < tie(o.turn, o.id);
	}
};

vector<int> g[N];
int ent[N], ext[N], depth[N], up[N][LOG], ntime = 0;

void dfs(int u, int p);
bool is_ancestor(int anc, int u);
int lca(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	vector<int> id(n + 1, -1);
	int q; cin >> q;
	while (q--) {
		int k, m;
		cin >> k >> m;
		vector<pii> vir(k);
		for (auto& p : vir) {
			cin >> p.first >> p.second;
		}
		vector<int> imp(m);
		for (auto& u : imp) {
			cin >> u;
		}
		vector<int> useful = imp;
		for (auto& p : vir) {
			useful.pb(p.first);
		}
		sort(useful.begin(), useful.end(), [&] (int u, int v) {
			return ent[u] < ent[v];
		});
		useful.erase(unique(useful.begin(), useful.end()), useful.end());
		int sz = useful.size();
		for (int i = 0; i < sz - 1; ++i) {
			useful.pb(lca(useful[i], useful[i + 1]));
		}
		sort(useful.begin(), useful.end(), [&] (int u, int v) {
			return tie(ent[u], u) < tie(ent[v], v);
		});
		useful.erase(unique(useful.begin(), useful.end()), useful.end());
		sz = useful.size();
		for (int i = 0; i < sz; ++i) {
			id[useful[i]] = i;
		}
		vector<vector<pii>> tree(sz);
		stack<int> stk; stk.push(0);
		for (int i = 1; i < sz; ++i) {
			while (!is_ancestor(useful[stk.top()], useful[i])) {
				stk.pop();
			}
			tree[stk.top()].pb({i, depth[useful[i]] - depth[useful[stk.top()]]});
			stk.push(i);
		}
		vector<state> dp(sz, {inf, inf, inf});
		for (int i = 0; i < k; ++i) {
			auto& p = vir[i];
			dp[id[p.first]] = {0, 0, i};
		}
		for (int i = sz - 1; i >= 0; --i) {
			for (auto& e : tree[i]) {
				int j = e.first, wt = e.second;
				if (dp[j].id != inf) {
					int spd = vir[dp[j].id].second;
					auto cand = dp[j];
					cand.dist += wt;
					cand.turn = (cand.dist + spd - 1) / spd;
					dp[i] = min(dp[i], cand);
				}
			}
		}
		for (int i = 0; i < sz; ++i) {
			int spd = vir[dp[i].id].second;
			for (auto& e : tree[i]) {
				int j = e.first, wt = e.second;
				auto cand = dp[i];
				cand.dist += wt;
				cand.turn = (cand.dist + spd - 1) / spd;
				dp[j] = min(dp[j], cand);
			}
		}
		for (auto& u : imp) {
			cout << dp[id[u]].id + 1 << ' ';
		}
		cout << '\n';
	}
}

void dfs(int u, int p) {
	ent[u] = ntime++;
	depth[u] = depth[p] + 1;
	up[u][0] = p;
	for (int j = 1; j < LOG; ++j) {
		up[u][j] = up[up[u][j - 1]][j - 1];
	}
	for (auto& v : g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	ext[u] = ntime;
}

bool is_ancestor(int anc, int u) {
	return (!anc or (ent[anc] <= ent[u] and ext[u] <= ext[anc]));
}

int lca(int u, int v) {
	if (depth[u] >= depth[v]) {
		swap(u, v);
	}
	for (int j = LOG - 1; j >= 0; --j) {
		while (!is_ancestor(up[v][j], u)) {
			v = up[v][j];
		}
	}
	return up[v][0];
}