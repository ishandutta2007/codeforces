#include <bits/stdc++.h>

using namespace std; 

const int MaxN = 2e5 + 5; 

int n;
vector<int> adj[MaxN]; 

int col[MaxN]; 
int cnt[3]; 

void dfs(int u) {
	++cnt[col[u]]; 
	for (int v : adj[u]) if (!col[v]) {
		col[v] = 3 - col[u]; 
		dfs(v); 
	}
}
//
int main() {
	scanf("%d", &n); 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	
	col[1] = 1; 
	dfs(1); 

	cout << min(cnt[1] - 1, cnt[2] - 1) << '\n'; 
	
	return 0; 
}