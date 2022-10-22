#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];

ld ans = 0;
/*void dfs(int v, int p = -1, ld pr = 1){
	int t = adj[v].size()-int(p != -1);
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, pr/t);
	if (~p)
		ans += pr;
}*/

ld dfs(int v, int p = -1){
	int t = adj[v].size()-int(p != -1);
	ld ret = 0;
	for (int u:adj[v])
		if (u^p)
			ret += (1 + dfs(u, v))/ t;

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//dfs(0);
	cout << fixed << setprecision(12);
	//cout << ans << "\n";
	cout << dfs(0) << "\n";
	return 0;
}