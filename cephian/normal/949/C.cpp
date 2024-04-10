#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
vector<int> G[N];
vector<int> R[N];
int color[N];

int dfs_hit[N] = {};
vector<int> order;
vector<int> checkme;

set<int> all_ccs;

void dfs(int v, int lab) {
	dfs_hit[v] = lab;
	for(int u : G[v]) {
		if(dfs_hit[u] == 0) {
			dfs(u, lab);
		}
	}
	order.push_back(v);
}

int id[N] = {};
map<int, int> id_count;

void dfs2(int v, int lab) {
	all_ccs.insert(lab);
	id[v] = lab;
	++id_count[lab];
	for(int u : R[v]) {
		if(id[u] != 0) continue;
		dfs2(u, lab);
	}
}


int main() {
	int n, m, h;
	cin >> n >> m >> h;
	for(int i = 1; i <= n; ++i)
		cin >> color[i];

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if(color[v] == ((color[u]+1)%h)) {
			G[u].push_back(v);
		}
		if(color[u] == (color[v]+1)%h)
			G[v].push_back(u);
	}
	for(int v = 1; v <= n; ++v) {
		for(auto u : G[v]) {
			R[u].push_back(v);
		}
	}

	for(int i = 1; i <= n; ++i) {
		if(dfs_hit[i]) continue;
		dfs(i, i);
	}

	for(int i = order.size()-1; i >= 0; --i) {
		if(id[order[i]] == 0)
			dfs2(order[i], i+1);
	}

	for(int v = 1; v <= n; ++v) {
		for(int u : G[v]) {
			if(id[v] != id[u])
				all_ccs.erase(id[v]);
		}
	}

	int mn = *all_ccs.begin();
	for(int cc : all_ccs) {
		if(id_count[mn] > id_count[cc])
			mn = cc;
	}
	cout << id_count[mn] << "\n";
	for(int i = 1; i <= n; ++i)
		if(id[i] == mn)
			cout << i << " ";
	cout << "\n";
}