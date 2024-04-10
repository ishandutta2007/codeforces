#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, k, col[MAXN], cc[MAXN], cnt, mx;
short vis[MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	mx = max(mx, ++cc[col[v]]);
	cnt++;
	for (int u:adj[v])
		dfs(u);
}

void clear(int v){
	if (vis[v] == 2)	return;
	vis[v] = 2;
	cc[col[v]] = 0;
	for (int u:adj[v])
		clear(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)	cin >> col[i];
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			cnt = 0;
			mx = 0;
			dfs(i);
			clear(i);
			ans += cnt - mx;
		}
	cout << ans << "\n";
	return 0;
}