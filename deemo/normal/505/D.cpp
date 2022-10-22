#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 20;

int n, m, comp[MAXN], g, ans, col[MAXN];
bool mark[MAXN], vis[MAXN], cd[MAXN];
vector<int>	adj[MAXN], uni[MAXN];

void dfs(int v){
	vis[v] = 1;
	comp[v] = g;
	for (int u:adj[v])
		if (!vis[u])	dfs(u);
}

void ts(int v){
	if (col[v]){
		if (col[v] == 2 || cd[comp[v]])	return;
		cd[comp[v]] = 1;
		ans++;
		return;
	}
	ans++;
	col[v] = 1;
	for (int u:uni[v])
		ts(u);
	col[v] = 2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		uni[a].push_back(b);

		mark[a] = mark[b] = 1;
	}
	for (int i = 0; i < n; i++)
		if (mark[i] && !vis[i])	dfs(i), g++;
	
	for (int i = 0; i < n; i++)
		if (mark[i] && col[i] == 0)	ts(i);
	ans -= g;
	cout << ans << endl;
	return	0;
}