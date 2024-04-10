#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int n, m;
vector<int>	adj[MAXN], _adj[MAXN], vec[MAXN];

void addEdge(int u, int v){adj[u].push_back(v), _adj[v].push_back(u);}

void addClause(int x, int y){
	addEdge(x^1, y);
	addEdge(y^1, x);
}

bool vis[MAXN+10];
int sec[MAXN+10], sz, comp[MAXN+10], g;

void dfs(int v){
	vis[v] = 1;
	for (int u:adj[v])
		if (!vis[u])
			dfs(u);
	sec[sz++] = v;
}

void kosaraju(int v){
	vis[v] = 1;
	comp[v] = g;
	for (int u:_adj[v])
		if (!vis[u])
			kosaraju(u);
}

bool col[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> col[i], col[i] = !col[i];
	for (int i = 0; i < m; i++){
		int ln;	cin >> ln;
		while (ln--){
			int v;	cin >> v, v--;
			vec[v].push_back(i);
		}
	}
	for (int i = 0; i < n; i++){
		int u = vec[i][0], v = vec[i][1];
		if (col[i])
			addClause(u<<1, v<<1), addClause(u<<1^1, v<<1^1);
		else
			addClause(u<<1^1, v<<1), addClause(u<<1, v<<1^1);

	}
	
	for (int v = 0; v < (m<<1); v++)
		if (!vis[v])
			dfs(v);
	memset(vis, 0, sizeof(vis));
	for (int i = sz-1; ~i; i--)
		if (!vis[sec[i]]){
			kosaraju(sec[i]);
			g++;
		}

	for (int v = 0; v < m; v++)
		if (comp[v<<1] == comp[v<<1^1]){
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}