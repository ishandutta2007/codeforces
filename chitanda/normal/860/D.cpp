#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200005;
int n, m;
bool vis[maxn], inq[maxn];
vector<int> g[maxn], f[maxn];

void dfs(int t, int fa){
	inq[t] = 1;
	vis[t] = 1;
	for(int v : g[t]){
		if(v == fa) continue;
		if(vis[v]){
			if(inq[v]) f[t].pb(v);
			continue;
		}
		dfs(v, t);
		if(f[v].size() & 1)
			f[v].pb(t);
		else
			f[t].pb(v);
	}
	inq[t] = 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		static int u, v;
		scanf("%d%d", &u, &v);
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) dfs(i, 0);
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += f[i].size() / 2;
	printf("%d\n", ans);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j + 1 < f[i].size(); j += 2)
			printf("%d %d %d\n", f[i][j], i, f[i][j + 1]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}