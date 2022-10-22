#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, col[MAXN], cnt[MAXN], sz[MAXN], mn[MAXN], mx[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	mn[v] = mx[v] = col[v];
	sz[v] = 1;
	bool fail = 0;
	for (int u:adj[v])
		if (u^p){
			dfs(u, v);
			mx[v] = max(mx[v], mx[u]);
			mn[v] = min(mn[v], mn[u]);
			fail |= mn[u] != mx[u];
			sz[v] += sz[u];
		}

	if (!fail){
		if (~p){
			int cc = 0;
			for (int u:adj[v])
				if (u^p && mn[u] == col[p])
					cc += sz[u];
	
			cc += int(col[v] == col[p]);
			cc += n - sz[v];
			fail |= cc != cnt[col[p]];
		}
		
		if (!fail){
			cout << "YES\n";
			cout << v+1 << "\n";
			exit(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)	cin >> col[i], cnt[col[i]]++;
	dfs(0);
	cout << "NO\n";
	return 0;
}