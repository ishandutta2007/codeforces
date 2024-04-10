#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

int n, m, k, sec[MAXN], sz;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v, int p = -1){
	vis[v] = 1;
	sec[sz++] = v;
	for (int u:adj[v])
		if (!vis[u])
			dfs(u, v);
	if (~p)
		sec[sz++] = p;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	int cur = 0;
	int temp = (n+n+k-1)/k;
	while (k--){
		int t = min(sz-cur, temp);
		if (t == 0){
			cout << "1 1\n";
			continue;
		}
		cout << t << " ";
		for (int i = cur; i < cur+t; i++)
			cout << sec[i]+1 << " ";
		cout << "\n";
		cur += t;
	}
	return 0;
}