#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, cc, depth[MAXN], col[MAXN];
short vis[MAXN];
vector<int>	adj[MAXN], sadj[MAXN];

void dfs(int v, int de = 0){
	if (vis[v]){
		if (vis[v] == 2)	return;
		cc = max(cc, abs(de - depth[v]));
		return;
	}
	
	vis[v] = 1;
	depth[v] = de;
	for (int u:adj[v])
		dfs(u, de + 1);
	for (int u:sadj[v])
		dfs(u, de - 1);
	vis[v] = 2;
}

bool go(int v, int c, int ans){
	if (vis[v]){
		if (c != col[v])	return	true;
		return	false;
	}
	vis[v] = 1;
	col[v] = c;
	for (int u:adj[v])
		if (go(u, (c + 1) % ans, ans))	return true;
	for (int u:sadj[v])
		if (go(u, (c + ans - 1) % ans, ans))	return	true;
	return	false;	
}

bool check(int ans){
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (vis[i] == 0 && go(i, 0, ans))	return	false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		sadj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (vis[i] == 0)	dfs(i);
	if (cc == 0){
		cout << n << "\n";
		return	0;	
	}
	
	for (int i = cc; i; i--)
		if (cc % i == 0 && check(i)){
			cout << i << "\n";
			return	0;
		}
	return	0;
}