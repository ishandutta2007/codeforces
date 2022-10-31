#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct edge {
	int to, id;
	ll weight;
};

const int N = 3e5+5;
vector<edge> G[N];

vector<pair<int,int>> T[N];

ll dist[N];
ll id[N];
int n, m, k;
set<int> ans;

void dfs(int v, int p) {
	for(auto ed : T[v]) {
		if(ed.first == p) continue;
		dfs(ed.first, v);
		if(m-(int)ans.size() > k)
			ans.insert(ed.second);
	}
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		G[u].push_back({v, i, w});
		G[v].push_back({u, i, w});
	}

	set<pair<ll, int>> Q;
	fill(dist, dist+N, 1LL<<60);
	dist[1] = 0;
	Q.emplace(0, 1);

	set<int> used_ids;

	while(!Q.empty()) {
		ll w;
		int v;
		tie(w, v) = *Q.begin();
		Q.erase(Q.begin());
		for(auto ed : G[v]) {
			if(w + ed.weight < dist[ed.to]) {
				Q.erase(make_pair(dist[ed.to], ed.to));
				dist[ed.to] = w + ed.weight;
				Q.emplace(dist[ed.to], ed.to);
				id[ed.to] = ed.id;
			}
		}
	}

	for(int i = 2; i <= n; ++i) {
		used_ids.insert(id[i]);
	}

	for(int v = 1; v <= n; ++v) {
		for(auto& e : G[v]) {
			if(used_ids.count(e.id)) {
				T[v].emplace_back(e.to, e.id);
			} else {
				if(v < e.to) ans.insert(e.id);
			}
		}
	}
	dfs(1,1);
	cout << m-(int)ans.size() << "\n";
	for(int i = 1; i <= m; ++i) {
		if(!ans.count(i)) cout << i << " ";
	}
	cout << "\n";
}