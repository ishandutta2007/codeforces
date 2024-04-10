#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, k;
vector<int> adj[MAXN];

void fail(){
	cout << "No\n";
	exit(0);
}

int par[MAXN], depth[MAXN];
void dfs(int v, int p = -1, int de = 0){
	par[v] = p;
	depth[v] = de;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int v = 0; v < n; v++)
		if ((int)adj[v].size() == 2)
			fail();

	dfs(0);
	int v = max_element(depth, depth+n) - depth;
	dfs(v);
	v = max_element(depth, depth+n) - depth;
	if (depth[v]&1) fail();
	int temp = depth[v]/2;
	int d = temp;
	while (temp--) v = par[v];
	
	dfs(v);
	for (int u = 0; u < n; u++)
		if (u^v){
			if ((int)adj[u].size() != 1 && (int)adj[u].size() < 4) fail();
			if ((int)adj[u].size() == 1 && depth[u] != d) fail();
		}
	if (d != k) fail();

	cout << "Yes\n";
	return 0;
}