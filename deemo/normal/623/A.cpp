#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 500 + 4;

int n, m, cn, cnt, g, tp[MAXN];
bool vis[MAXN], mark[MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	tp[v] = g;
	cnt++;
	vis[v] = 1;
	for (int u:adj[v]){
		if (mark[u])	continue;
		cn++;
		if (!vis[u])	dfs(u);
	}
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
		if ((int)adj[i].size() == n - 1)	mark[i] = 1;
	for (int i = 0; i < n; i++)
		if (!mark[i] && !vis[i]){
			g++;
			cn = cnt = 0;
			dfs(i);
			if (cnt * (cnt - 1)/ 2 != cn/2){
				cout << "No\n";
				return	0;
			}
		}
	if (g > 2){
		cout << "No\n";
		return	0;
	}
	cout << "Yes\n";
	for (int i = 0; i < n; i++)
		if (mark[i])
			cout << "b";
		else if (tp[i] == 1)	cout << "a";
		else	cout << "c";
	cout << "\n";
	return	0;
}