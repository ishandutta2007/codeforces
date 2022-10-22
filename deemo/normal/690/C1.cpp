#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, m, cnt;
vector<int>	adj[MAXN];
bool vis[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cnt++;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	if (cnt == n && m == n - 1)
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}