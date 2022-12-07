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

const int maxn = 100100;
int f[maxn][11][3];
int ff[11][3];
int sz[maxn];
int n, m;
int k, x;
vector<int> g[maxn];

inline void upd(int &a, int b){
	(a += b, a >= M) && (a -= M);
}

void dfs(int t, int fa = 0){
	sz[t] = 1;
	f[t][0][0] = k - 1;
	f[t][0][2] = m - k;
	f[t][1][1] = 1;
	for(int v : g[t]){
		if(v == fa) continue;
		dfs(v, t);
		memcpy(ff, f[t], sizeof(f[t]));
		memset(f[t], 0, sizeof(f[t]));
		
		for(int i = min(sz[t], x); i >= 0; --i)
			for(int j = min(sz[v], x - i); j >= 0; --j)
				f[t][i + j][0] = (f[t][i + j][0] + (ll)ff[i][0] * f[v][j][0] + (ll)ff[i][0] * f[v][j][1] + (ll)ff[i][0] * f[v][j][2]) % M;
		
		for(int i = min(sz[t], x); i >= 1; --i)
			for(int j = min(sz[v], x - i); j >= 0; --j)
				f[t][i + j][1] = (f[t][i + j][1] + (ll)ff[i][1] * f[v][j][0]) % M;

		for(int i = min(sz[t], x); i >= 0; --i)
			for(int j = min(sz[v], x - i); j >= 0; --j)
				f[t][i + j][2] = (f[t][i + j][2] + (ll)ff[i][2] * f[v][j][0] + (ll)ff[i][2] * f[v][j][2]) % M;
		
		sz[t] += sz[v];
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++i){
		static int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	scanf("%d%d", &k, &x);
	dfs(1);
	int ans = 0;
	for(int i = 0; i <= x; ++i)
		for(int j = 0; j <= 2; ++j)
			upd(ans, f[1][i][j]);
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}