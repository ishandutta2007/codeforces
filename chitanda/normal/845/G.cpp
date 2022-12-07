#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100100;
int n, m;
vector<int> cir;
vector<pair<int, int>> g[maxn];
int f[maxn];
bool vis[maxn], tag[maxn];

void dfs(int t, int fa){
	vis[t] = 1;
	for(auto e : g[t]){
		int v = e.fi, w = e.se;
		if(v == fa) continue;
		if(vis[v]) cir.pb(f[t] ^ f[v] ^ w);
		else{
			f[v] = f[t] ^ w;
			dfs(v, t);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		static int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mkp(v, w));
		g[v].pb(mkp(u, w));
	}
	dfs(1, 0);
	int ans = f[n];
	for(int i = 30; i >= 0; --i){
		int k = -1;
		for(int j = 0; j < cir.size(); ++j)
			if(!tag[j] && cir[j] >> i & 1) k = j;
		if(k == -1) continue;
		tag[k] = 1;
		for(int j = 0; j < cir.size(); ++j)
			if(!tag[j] && cir[j] >> i & 1)
				cir[j] ^= cir[k];
		
		if(ans >> i & 1)
			ans ^= cir[k];
	}
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}