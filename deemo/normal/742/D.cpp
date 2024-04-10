#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e3 + 5;

int n, m, mx, w[MAXN], val[MAXN];
int tw, tval;
vector<vector<pair<int, int>>>	sec;
vector<pair<int, int>>	vec;
bool vis[MAXN];
ll d[MAXN][MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	vis[v] = 1;
	vec.push_back({w[v], val[v]});
	tw += w[v], tval += val[v];

	for (int u:adj[v])
		if (!vis[u])
			dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> mx;
	for (int i = 0; i < n; i++)	cin >> w[i];
	for (int i = 0; i < n; i++)	cin >> val[i];
	while (m--){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			vec.clear();
			tw = tval = 0;
			dfs(i);
			vec.push_back({tw, tval});
			sec.push_back(vec);
		}
	memset(d, -10, sizeof(d));
	ll ans = 0;
	d[0][0] = 0;
	for (int i = 0; i < sec.size(); i++)
		for (auto x:sec[i]){
			for (int w = 0; w <= mx; w++){
				d[i + 1][w] = max(d[i + 1][w], d[i][w]);
				if (w >= x.F)
					d[i + 1][w] = max(d[i + 1][w], d[i][w-x.F] + x.S);
				ans = max(ans, d[i + 1][w]);
			}
		}
	cout << ans << endl;
	return 0;
}