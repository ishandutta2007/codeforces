#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
vector<int>	adj[MAXN];
bool vis[MAXN], fl;

void dfs(int v, int p = -1){
	if (vis[v]){
		fl = 0;
		return;
	}
	vis[v] = 1;
	for (int u:adj[v])
		if (u != p)
			dfs(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			fl = 1;
			dfs(i);
			if (fl)	ans++;
		}
	cout << ans << "\n";
	return	0;
}