//Only you are the life among the dead..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1e3 + 10;

int n, m;
bool vis[MAXN], col[MAXN];
int sec[MAXN];
int q[MAXN], d[MAXN];
vector<int>	adj[MAXN];

bool dfs(int v, bool c = 0){
	if (vis[v]){
		if (c != col[v])
			return	true;
		return	false;
	}
	vis[v] = 1;
	col[v] = c;
	for (int u:adj[v])
		if(dfs(u, !c))	return	true;
	return	false;
}	

int bfs(int v, bool tt = 1){
	int ret = 0;
	d[v] = 0;
	int h = 0, t = 0;
	q[t++] = v;
	while (h < t){
		v = q[h++];
		vis[v] = 1;
		ret = max(ret, d[v]);
		for (int u:adj[v])
			if (d[u] > d[v] + 1){
				d[u] = d[v] + 1;
				q[t++] = u;
			}
	}
	
	if (tt){
		for (int i = 0; i < t; i++)
			sec[i] = q[i];
		for (int i = 0; i < t; i++){
			for (int j = 0; j < t; j++)	d[sec[j]] = 1e9;
			ret = max(ret, bfs(sec[i], 0));
		}
	}
	return	ret;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i] && dfs(i)){
			cout << "-1\n";
			return	0;
		}

	int ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(d, 63, sizeof(d));
	for (int i = 0; i < n; i++)
		if (!vis[i])
			ans += bfs(i);
	cout << ans << "\n";
	return	0;
}