#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int g[505][505];

struct dsu {
	vector<int> uf;

	int id(int u) {
		//cout << u << " to " <<uf[u] << endl;
		return (uf[u]==u) ? u : uf[u]=id(uf[u]);
	}

	void merge(int u, int v) {
		u = id(u), v = id(v);
		if(u != v)
			uf[u] = v;
	}

	void init(int n) { 
		uf.resize(n);
		for(int i = 0; i < n; ++i)
			uf[i] = i;
	}
	dsu(int n) {init(n);}
};

const int N = 1e5+5;
int c[N];
int from[N];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	dsu U(n);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j) {
			if(i == j)
				g[i][j] = 0;
			else
				g[i][j] = 1e9+10;
		}
		cin >> c[i];
	}
	// see where from
	int acc = 0;
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < c[i]; ++j) {
			from[acc+j] = i;
		}
		acc += c[i];
	}
	// read, merge, make graph
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		//cout << "merging " << u << " and " << v << " with " << w << endl;
		--u, --v;
		if(w == 0) {
			U.merge(u, v);
		}
		u = from[u];
		v = from[v];
		g[u][v] = min(g[u][v], w);
		g[v][u] = g[u][v];
	}
	// check CCs
	acc = 0;
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < c[i]; ++j) {
			if(U.id(acc+j) != U.id(acc)) {
				cout << "No\n";
				return 0;
			}
		}
		acc += c[i];
	}
	// floyd warshall
	for(int l = 0; l < k; ++l) {
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < k; ++j) {
				g[i][j] = min(g[i][j], g[i][l] + g[l][j]);
			}
		}
	}
	// print ans;
	cout << "Yes\n";
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < k; ++j) {
			if(g[i][j] > 1e9)
				cout << "-1 ";
			else
				cout << g[i][j] << ' ';
		}
		cout << '\n';
	}

}