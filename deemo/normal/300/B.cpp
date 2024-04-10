#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int MAX = 50;

int n, m;
vector<int>	adj[MAX];
vector<int>	ans[MAX];
vector<int>	sec[4];
int sz[MAX];
bool mark[MAX];
int cnt;

void dfs(int v, int col){
	if (mark[v])	return;
	mark[v] = 1;
	cnt++;
	ans[col].push_back(v);
	for (int u:adj[v])	dfs(u, col);
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int g = 0;
	for (int i = 0; i < n; i++){
		if (mark[i])	continue;
		cnt = 0;
		dfs(i, g);
		sz[g++] = cnt;
		if (cnt > 3){
			cout << -1 << endl;
			return 0;
		}
		sec[cnt % 3].push_back(g - 1);
	}

	for (int i = 0; i < sec[2].size(); i++){
		if (sec[1].empty()){
			cout << -1 << endl;
			return 0;
		}
		
		int x = sec[1].back(), y = sec[2][i];
		sec[1].pop_back();
		for (int u:ans[x])	ans[y].push_back(u);
		ans[x].clear();
	}
	if (sec[1].size() % 3){
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < sec[1].size(); i += 3){
		int y = sec[1][i];
		for (int j = i + 1; j < i + 3; j++){
			int x = sec[1][j];
			for (int u:ans[x])	ans[y].push_back(u);
			ans[x].clear();
		}
	}
	for (int i = 0; i < MAX; i++){
		if (ans[i].empty())	continue;
		for (int u:ans[i])	cout << u + 1 << " ";
		cout << endl;
	}

	return 0;
}