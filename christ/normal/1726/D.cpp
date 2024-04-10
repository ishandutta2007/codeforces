#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5;
vector<array<int,2>> adj[MN];
bool vis[MN];
bool took[MN];
int par[MN];
void dfs (int cur) {
	vis[cur] = true;
	for (auto [i,id] : adj[cur]) if (!vis[i]) {
		took[id] = true;
		dfs(i);
	}
}
void chk (int cur) {
	vis[cur] = true;
	for (auto [i,id] : adj[cur]) if (!vis[i] && took[id]) {
		par[i] = cur;
		chk(i);
	}
}
void solve() {
	int n,m; scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = false;
	for (int i = 0; i < m; i++) took[i] = false;
	vector<array<int,2>> edges(m);
	int _id = 0;
	for (auto &[u,v] : edges) {
		scanf ("%d %d",&u,&v);
		int c = _id++;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	dfs(1);
	int cnt = 0;
	set<int> st;
	int gU = -1, gV = -1, id = -1;
	for (int i = 0; i < m; i++) if (!took[i]) {
		cnt++;
		auto &[u,v] = edges[i];
		st.insert(u); st.insert(v);
		gU = u; gV = v; id = i;
	}
	if ((int)st.size() == 3 && cnt == 3) {
		for (int i = 1; i <= n; i++) vis[i] = false, par[i] = -1;
		chk(gU);
		assert(par[gV] != gU);
		assert(par[gV] != -1);
		assert(took[id] == false);
		took[id] = true;
		bool got = false;
		for (int j = 0; j < m; j++) {
			auto [u,v] = edges[j];
			if ((u == gV && v == par[gV]) || (u == par[gV] && v == gV)) {
				assert(took[j] == true);
				took[j] = false;
				got = true;
				break;
			}
		}
		assert(got);
	}
	for (int i = 0; i < m; i++) printf ("%d",(int)took[i]);
	printf ("\n");
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}