#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int LOG = 20;

int n, val[MAXN], a[MAXN];
ll cc = 0;
vector<int> adj[MAXN];

void plant(int v, int w, int p = -1, int cur = 0){
	cur ^= val[v]>>w&1;
	a[v] = cur;
	for (int u:adj[v])
		if (u^p)
			plant(u, w, v, cur);
}

int d0[MAXN], d1[MAXN];
void dfs(int v, int w, int p = -1){
	d0[v] = d1[v] = 0;
	if (val[v]>>w&1) cc++;
	if (a[v])
		d1[v]++;
	else
		d0[v]++;

	for (int u:adj[v])
		if (u^p){
			dfs(u, w, v);
			if (val[v]>>w&1)
				cc += 1ll*d1[u]*d1[v]+1ll*d0[u]*d0[v];
			else
				cc += 1ll*d1[u]*d0[v]+1ll*d0[u]*d1[v];
			d1[v] += d1[u];
			d0[v] += d0[u];
		}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; for (int i = 0; i < n; i++) cin >> val[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll ans = 0;
	for (int w = 0; w < LOG; w++){
		cc = 0;
		plant(0, w);
		dfs(0, w);
		ans += cc*(1<<w);
	}
	cout << ans << "\n";
	return 0;
}