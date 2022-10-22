#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int n;
vector<int>	adj[MAXN];

bool vis[MAXN];
void dfs(int v){
	vis[v] = 1;
	for (int u:adj[v])
		if (!vis[u])
			dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int a = 0; a < n; a++){
		int b;	cin >> b, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i), ans++;
	cout << ans << "\n";
	return 0;
}