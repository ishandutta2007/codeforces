#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;

int n, m, k, tt[MAXN];
vector<int>	adj[MAXN];
int cv, ce;
bool vis[MAXN];

void dfs(int v){
	vis[v] = 1;
	cv++;
	ce += adj[v].size();
	for (int u:adj[v])
		if (!vis[u])
			dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)	cin >> tt[i], tt[i]--;
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll ans = 0;
	int mx = 0;
	for (int i = 0; i < k; i++){
		cv = ce = 0;
		dfs(tt[i]);
		ce >>= 1;
		ans += 1ll * cv * (cv-1)/2 - ce;
		mx = max(mx, cv);
	}
	for (int v = 0; v < n; v++)
		if (!vis[v]){
			cv = ce = 0;
			dfs(v);
			ce >>= 1;
			ans += 1ll * cv * (cv-1)/2 - ce;
			ans += 1ll * mx * cv;
			mx += cv;
		}
	cout << ans << "\n";
	return 0;
}