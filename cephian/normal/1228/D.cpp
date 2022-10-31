#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e5+5;
vector<int> G[N];
int mark[N] = {};
ll sz[4] = {};

void dfs(int v, int m) {
	mark[v] = m;
	++sz[m];
	for(int u : G[v]) {
		if(mark[u] == m) {
			cout << "-1\n";
			exit(0);
		} else if(mark[u] == 0) {
			dfs(u, 5-m);
		}
	}
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	mark[1] = 1;
	sz[1] = 1;
	for(int u = 2; u <= n; ++u) {
		bool con = false;
		for(auto v : G[u])
			if(v == 1)
				con = true;
		if(con == false) {
			mark[u] = 1;
			++sz[1];
		}
	}
	for(int u = 2; u <= n; ++u) {
		if(mark[u] == 0) {
			dfs(u, 2);
		}
	}

	// check fullness
	ll sd = sz[1]*sz[2] + sz[2]*sz[3] + sz[3]*sz[1];
	if(sd != m || sz[2] == 0 || sz[3] == 0) {
		cout << "-1\n";
		exit(0);
	}
	for(int u = 1; u <= n; ++u) {
		for(int v : G[u]) {
			if(mark[u] == mark[v]) {
				cout << "-1\n";
				exit(0);
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << mark[i] << ' ';
	cout << '\n';
}