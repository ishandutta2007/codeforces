#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, x[MAXN], y[MAXN], col[MAXN];
vector<int>	adj[MAXN];
bool vis[MAXN];

void dfs(int v, int cl=1){
	vis[v] = 1;
	col[v] = cl;
	for (int u:adj[v])
		if (!vis[u])
			dfs(u, 3-cl);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i], x[i]--, y[i]--;
		adj[x[i]].push_back(y[i]);
		adj[y[i]].push_back(x[i]);
	}
	for (int i = 0; i < n<<1; i+=2)
		adj[i].push_back(i+1), adj[i+1].push_back(i);
	for (int i = 0; i < n<<1; i++)	
		if (!vis[i])	dfs(i);
	for (int i = 0; i < n; i++)
		cout << col[x[i]] << " " << col[y[i]] << "\n";
	return 0;
}