#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
bool vis[MAXN], block[MAXN];
vector<int>	adj[MAXN];

int dfs(int v = 0){
	vis[v] = 1;
	block[v] = 1;
	vector<int>	zz;
	for (int u:adj[v])
		if (!block[u]){
			int ind = -1;
			if (!vis[u])
				ind = dfs(u);
			if (ind == -1)
				zz.push_back(u);
			else
				cout << ind + 1 << " " << u + 1 << " " << v + 1 << "\n";
		}
	
	while (zz.size() > 1){
		cout << zz.back() + 1 << " " << v + 1 << " ";
		zz.pop_back();
		cout << zz.back() + 1 << "\n";
		zz.pop_back();
	}
	
	int ret = -1;
	if (zz.size() & 1)
		ret = zz.back(), zz.pop_back();
	block[v] = 0;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			int a, b;	cin >> a >> b, a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	{
		if (m&1){
			cout << "No solution\n";
			return 0;
		}
		dfs();
	}
	return 0;
}