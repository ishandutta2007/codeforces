#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 20;
const int INF = 1e9 + 5;

int n, m, d[2][MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	if (adj[v].size() == 0){
		d[0][v] = d[1][v] = 1;
		m++;
		return;
	}

	d[0][v] = INF, d[1][v] = 0;
	for (int u:adj[v]){
		dfs(u);
		d[0][v] = min(d[0][v], d[1][u]);
		d[1][v] += d[0][u];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
	}
	dfs(0);
	cout << m - d[0][0] + 1 << " " << d[1][0] << "\n";
	return	0;
}