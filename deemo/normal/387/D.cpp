//No regrets..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 500 + 5;

int n, m, t[2][MAXN];
bool c[MAXN][MAXN], vis[MAXN];
vector<int>	adj[MAXN];

bool dfs(int v, int del){
	if (vis[v])
		return false;
	vis[v] = 1;
	for (int u:adj[v])
		if (u^del)
			if (t[1][u] == -1 || dfs(t[1][u], del)){
				t[1][u] = v;
				t[0][v] = u;
				return true;
			}
	return false;
}

int match(int del){
	memset(t, -1, sizeof(t));
	int ret = 0;
	bool changed = 1;
	while (changed){
		memset(vis, 0, sizeof(vis));
		changed = 0;
		for (int i = 0; i < n; i++)
			if (i ^ del && t[0][i] == -1 && dfs(i, del))
				changed = 1, ret++;
	}
	return n - 1 - ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b, a--, b--;
		c[a][b] = 1;
		adj[a].push_back(b);
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++){
		int ret = 0;
		for (int j = 0; j < n; j++)
			if (i ^ j)
				ret += int(!c[i][j]) + int(!c[j][i]);

		if (!c[i][i])
			ret++;
		int z = m - 2 * n + 1 + ret;

		int temp = match(i);
		ans = min(ans, ret + temp + z - (n-1 - temp));
	}
	cout << ans << "\n";
	return 0;
}