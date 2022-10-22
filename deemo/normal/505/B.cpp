#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 200;

int n, m;
vector<pair<int, int>>	adj[MAXN];
bool vis[MAXN];

bool dfs(int v, int c, int des){
	if (vis[v])	return	false;
	if (v == des)	return	true;
	vis[v] = 1;
	for (pair<int, int>	e:adj[v])
		if (e.second == c)
			if (dfs(e.first, c, des))	return	true;
	return	false;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}	

	int q;	cin >> q;
	while (q--){
		int a, b;	cin >> a >> b;	a--, b--;
		int ans = 0;
		for (int i = 1; i <= m; i++){
			memset(vis, 0, sizeof(vis));
			if(dfs(a, i, b))	ans++;
		}
		cout << ans << endl;
	}
	return	0;
}