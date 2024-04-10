//Jump and Jump..

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

int n, ans, par[MAXN];
bool vis[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1, int de = 1){
	vis[v] = 1;
	ans = max(ans, de);
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de + 1);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int p;	cin >> p;
		par[i] = p;
		if (~p)
			adj[p-1].push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (par[i] == -1)
			dfs(i);
	cout << ans << endl;
	return 0;
}