#include<bits/stdc++.h>

using namespace std;

const int MAXN =2e5 + 10;

int n, ans, col[MAXN], st[MAXN], par[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p = -1){
	par[v] = p;
	if (p == -1)
		col[v] = 0;
	else{
		while (1){
			if (col[p] != st[p] && (par[p]==-1||col[par[p]]!=st[p])) break;
			st[p]++;
		}
		col[v] = st[p]++;
	}
	for (int u:adj[v])
		if (u^p)
			dfs(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b,a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) ans = max(ans, (int)adj[i].size());
	cout << ans + 1 << "\n";
	dfs(0);
	
	for (int i = 0; i < n; i++) cout << col[i]+1 << " ";
	cout << "\n";
	return 0;
}