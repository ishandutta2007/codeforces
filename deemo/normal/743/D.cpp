#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

int n, val[MAXN];
ll ans = -INF, sm[MAXN], mx[MAXN], pu[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	sm[v] = val[v];
	mx[v] = pu[v] = -INF;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v), sm[v] += sm[u], mx[v] = max(mx[v], mx[u]);
	mx[v] = max(mx[v], sm[v]);
	ll maxi = -INF;
	for (int u:adj[v])
		if (u^p){
			pu[u] = max(pu[u], maxi);
			maxi = max(maxi, mx[u]);
		}
	reverse(adj[v].begin(), adj[v].end());
	maxi = -INF;
	for (int u:adj[v])
		if (u^p){
			pu[u] = max(pu[u], maxi);
			maxi = max(maxi, mx[u]);
		}
}

void dfs2(int v, int p = -1){
	if (~p){
		pu[v] = max(pu[v], pu[p]);
		ans = max(ans, pu[v] + sm[v]);
	}
	for (int u:adj[v])
		if (u^p)
			dfs2(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> val[i];
	for (int i = 0; i < n - 1; i++){int a, b;	cin >> a >> b, a--, b--;adj[a].push_back(b), adj[b].push_back(a);}
	dfs(0);
	dfs2(0);
	if (ans < -1e16)
		cout << "Impossible\n";
	else
		cout << ans << endl;
	return 0;
}