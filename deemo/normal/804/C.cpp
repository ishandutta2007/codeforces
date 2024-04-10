#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, m, col[MAXN], mark[MAXN], g;
vector<int> vec[MAXN], adj[MAXN];

void dfs(int v, int p = -1){
	g++;
	for (int x:vec[v])
		if (col[x])
			mark[col[x]] = g;

	int cur = 1;
	for (int x:vec[v])
		if (!col[x]){
			while (mark[cur] == g) cur++;
			col[x] = cur;
			mark[cur] = g;
		}

	for (int u:adj[v])
		if (u^p)
			dfs(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int mx = -1;
	for (int i = 0; i < n; i++){
		int t; cin >> t;
		mx = max(mx, t);
		vec[i].resize(t);
		for (int j = 0; j < t; j++)
			cin >> vec[i][j], vec[i][j]--;
	}
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << max(mx, 1) << "\n";
	for (int i = 0; i < n; i++)
		if (vec[i].size() == mx){
			dfs(i);
			break;
		}
	for (int i = 0; i < m; i++)
		cout << max(1, col[i]) << " ";
	cout << "\n";
	return 0;
}