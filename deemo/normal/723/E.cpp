#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 3;
const int MAXE = MAXN * MAXN;

int n, m, from[MAXE], to[MAXE];
bool vis[MAXN], dl[MAXE];
vector<int>	adj[MAXN];

void del(int v, int e){
	if (from[e] ^ v)	swap(from[e], to[e]);
	int u = to[e];
	adj[v].erase(find(adj[v].begin(), adj[v].end(), e));
	adj[u].erase(find(adj[u].begin(), adj[u].end(), e));
}

bool go(int v, int p = -1){
	if (vis[v])	return false;
	vis[v] = 1;
	if ((int)adj[v].size() & 1 && p ^ -1)	return true;

	for (int e:adj[v]){
		int u = from[e]^to[e]^v;
		if (go(u, e)){
			del(v, e);
			return true;
		}
	}
	return false;
}

void dfs(int v){
	while (adj[v].size()){
		int e = adj[v].back();
		adj[v].pop_back();
		if (dl[e])	continue;
		dl[e] = 1;
		if (from[e] ^ v)	swap(from[e], to[e]);
		dfs(to[e]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			cin >> from[i] >> to[i], from[i]--, to[i]--;
			adj[from[i]].push_back(i);
			adj[to[i]].push_back(i);
		}
		int ans = n;
		for (int i = 0; i < n; i++)
			if ((int)adj[i].size() & 1)	ans--;

		{
			bool found = 1;
			while (found){
				found = 0;
				memset(vis, 0, sizeof(vis));
				for (int v = 0; v < n; v++)
					if ((int)adj[v].size() & 1){
						go(v);
						found = 1;
						break;
					}
			}
		}

		{
			memset(dl, 0, sizeof(dl));
			for (int v = 0; v < n; v++)
				if (adj[v].size())
					dfs(v);
		}
		
		cout << ans << "\n";
		for (int i = 0; i < m; i++)
			cout << from[i] + 1 << " " << to[i] + 1 << "\n";
	}
	return 0;
}