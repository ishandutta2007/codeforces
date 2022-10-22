#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, c;
vector<int>	adj[MAXN], child[MAXN], ans;
bool prt[MAXN], vis[MAXN];

void cnt(int v){
	vis[v] = 1;
	if (prt[v])	c++;
	for (int u:adj[v])
		if (!vis[u]){
			child[v].push_back(u);
			cnt(u);
		}
}

void dfs(int v, int p = -1){
	ans.push_back(v);
	prt[v] = !prt[v];
	for (int u:child[v])
		dfs(u, v);
	
	if (prt[v]){
		if (p != -1){
			ans.push_back(p);
			ans.push_back(v);
			ans.push_back(p);
		}
		else{
			int u = child[v][0];
			ans.push_back(u);
			ans.push_back(v);
			ans.push_back(u);
		}
	}
	else if (p != -1){
		ans.push_back(p);
		prt[p] = !prt[p];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)	cin >> prt[i];
	
	int ind = -1;
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			c = 0;
			cnt(i);
			if (c){
				if (ind != -1){
					cout << -1 << endl;
					return	0;
				}
				else	ind = i;
			}
		}

	if (ind == -1){
		cout << 0 << endl;
		return	0;
	}
		
	dfs(ind);
	cout << ans.size() << "\n";
	for (int v:ans)
		cout << v + 1 << " ";
	cout << "\n";
	return	0;
}