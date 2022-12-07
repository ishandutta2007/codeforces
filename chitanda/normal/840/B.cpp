#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, m, u[300100], v[300100];
vector<pair<int, int> > g[300100];
int d[300100], b[300100];
bool vis[300100];
vector<int> ans;

void dfs(int t){
	vis[t] = 1;
	for(auto e : g[t]){
		int v = e.fi, id = e.se;
		if(vis[v]) continue;
		dfs(v);
		if(d[v] != -1 && b[v] != d[v]) b[t] ^= 1, b[v] ^= 1, ans.pb(id);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", d + i);
	}
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", u + i, v + i);
		g[u[i]].pb(mkp(v[i], i));
		g[v[i]].pb(mkp(u[i], i));
	}
	bool flag = 1;
	for(int i = 1; i <= n; ++i)
		if(!vis[i] && d[i] == -1)
			dfs(i);
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			dfs(i);
			if(d[i] != -1 && b[1] != d[1])
				flag = 0;
		}
	if(flag){
		printf("%d\n", (int)ans.size());
		for(int v : ans) printf("%d\n", v);
	}else printf("-1\n");
	
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}