#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, g, cnt[MAXN], comp[MAXN];
bool vis[MAXN], del[MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cnt[g]++;
	comp[v] = g;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i])	dfs(i), g++;
	cin >> m;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		if (comp[a] == comp[b])
			del[comp[a]] = 1;
	}

	int ans = 0;
	for (int i = 0; i < g; i++)
		if (!del[i])
			ans = max(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}