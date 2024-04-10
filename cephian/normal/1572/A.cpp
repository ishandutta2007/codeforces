#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<int> dist;
vector<bool> here_now;
const int INF = 1e9;

int dfs(int v) {
	if(here_now[v])
		return INF;
	if(dist[v] == 0) {
		here_now[v] = true;
		dist[v] = 1;
		for(int a : G[v]) {
			int r = dfs(a);
			if(r == INF) return INF;
			dist[v] = max(dist[v], r+(a > v));
		}
		here_now[v] = false;
	}
	return dist[v];
}

int main() {	
	cout.sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		G = vector<vector<int>>(n);
		dist = vector<int>(n, 0);
		here_now = vector<bool>(n);

		for(int j = 0; j < n; ++j) {
			int k;
			cin >> k;
			for(int l = 0; l < k; ++l) {
				int a;
				cin >> a;
				G[j].push_back(a-1);
			}
		}
		int mx = 0;
		for(int j = 0; j < n; ++j) {
			mx = max(mx, dfs(j));
		}
		if(mx == INF)
			cout << "-1\n";
		else cout << mx << '\n';
	}
}