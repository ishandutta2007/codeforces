#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int NMAX = 300300;

vector<int> adj[NMAX];
int a[NMAX], par[NMAX];

ll n;

int len;
int flen;

int dfs(int u, int p) {
	par[u] = p;
	int tc = 0;
	for(auto& v : adj[u]) {
		if(v == p) continue;
		int t = dfs(v, u);
		tc = max(tc, t);
		if(t == -1) return -1;
	}
	if(tc && a[u] == 2) return -1;
	if(tc) a[u] = 1;
	if(a[u] == 1) tc = 1;
	return tc;
}

int lca;

int dfs2(int u, int p) {
	int tc = 0;
	for(auto& v : adj[u]) {
		if(v == p) continue;
		int t = dfs2(v, u);
		if(!tc) tc = t;
		else if(t && tc) {
			lca = u;
			//cerr << "lca is " << u << endl;
		}
	}
	if(a[u] == 2) {
		lca = u;
		//cerr << " lca is " << u << endl;
		tc = 1;
	}
	return tc;
}

int b[NMAX];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int s;
	int bc = 0;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		if(a[i] == 1) s = i;
		if(a[i] == 2) b[bc++] = i;
	}
	for(int i=0;i<n-1;++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(dfs(s, 0) == -1) {
		cout << 0 << endl;
		return 0;
	}
	dfs2(s, 0);
	int len = 0;
	for(int i=lca;;i = par[i]) {
		if(a[i] == 1) break;
		++len;
	}
	cout << len << endl;
	return 0;
}