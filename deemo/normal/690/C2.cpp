#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, d[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1, int de = 0){
	d[v] = de;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de + 1);
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
	dfs(0);
	pair<int, int>	mx(0, 0);
	for (int i = 0; i < n; i++)
		mx = max(mx, {d[i], i});
	dfs(mx.second);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	cout << ans << endl;
	return 0;
}