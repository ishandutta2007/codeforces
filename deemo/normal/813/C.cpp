#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, x, depth[MAXN], par[MAXN];
vector<int> adj[MAXN];

void plant(int v, int p=-1, int de = 0){
	depth[v] = de;
	par[v] = p;
	for (int u:adj[v])
		if (u^p)
			plant(u, v, de+1);
}

int ans = 0;
void dfs(int v){
	ans = max(ans, depth[v]);
	for (int u:adj[v])
		if (u^par[v])
			dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x, x--;
	for (int i = 0; i < n -1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	plant(0);
	int v = x, c = 0;
	while (++c < depth[par[v]]) v = par[v];
	dfs(v);
	cout << ans+ans << endl;
	return 0;
}