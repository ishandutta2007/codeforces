#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi G;
vvi E;
const int N = 1e5+5;
int col[N]={};

bool dfs(int v, int c) {
	if(col[v] != 0) {
		if(col[v] != c) return false;
		return true;
	}
	col[v] = c;
	for(int i = 0; i < G[v].size(); ++i) {
		int c2 = c^(E[v][i]==0);
		if(!dfs(G[v][i],c2))
			return false;
	}
	return true;
}

const ll M = 1e9+7;
int pw2(int b) {
	if(!b) return 1;
	if(b&1) return 2*pw2(b-1)%M;
	ll t = pw2(b/2);
	return t*t%M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	G = vvi(n);
	E = vvi(n);
	for(int i = 0; i < m; ++i) {
		int u,v,c;
		cin >> u >> v >> c;
		G[--u].push_back(--v);
		G[v].push_back(u);
		E[u].push_back(c);
		E[v].push_back(c);
	}
	int cc = 0;
	for(int i = 0; i < n; ++i) {
		if(col[i]!=0) continue;
		++cc;
		if(!dfs(i,cc*2)) {
			cout << "0\n";
			return 0;
		}
	}
	cout << pw2(cc-1) << "\n";
	return 0;
}