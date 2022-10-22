#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
bool vis[MAXN], fail, c[MAXN];
vector<int>	adj[MAXN], vec, sec;

void dfs(int v, bool col = 0){
	if (vis[v]){
		if (col != c[v])	
			fail = 1;
		return;
	}
	vis[v] = 1;
	c[v] = col;
	if (col)
		vec.push_back(v + 1);
	else
		sec.push_back(v + 1);
	for (int u:adj[v])
		dfs(u, !col);
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
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			dfs(i);
			if (fail){
				cout << "-1\n";
				return 0;
			}
		}
	cout << vec.size() << "\n";
	for (int u:vec)
		cout << u << " ";
	cout << "\n";
	cout << sec.size() << "\n";
	for (int u:sec)
		cout << u << " ";
	cout << "\n";
	return 0;	
}