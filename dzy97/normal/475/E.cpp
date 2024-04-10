#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N = 2e3 + 10, M = 4.05e6 + 10;
int h[N], g[N], p[M], n1[M], ee, low[N], dfn[N], dfntot, vis[N], n, m, st[N], top, id[N], tot, sz[N], ans, dp[N], ok[N];
pair<int,int> e[M];
void ae(int *A, int x, int y){
	p[ee] = y; n1[ee] = A[x]; A[x] = ee ++;
}
void tarjan(int u, int fa){
	vis[u] = 1;
	low[u] = dfn[u] = ++ dfntot;
	st[++ top] = u;
	for(int i = h[u];~i;i = n1[i]) if(p[i] != fa){
		if(!vis[p[i]]) tarjan(p[i], u), low[u] = min(low[u], low[p[i]]); else low[u] = min(low[u], dfn[p[i]]);
		if(low[p[i]] > dfn[u]){
			++ tot;
			while(st[top] != p[i]) id[st[top --]] = tot, sz[tot] ++;
			id[st[top --]] = tot;
			sz[tot] ++;
		}
	}
}
void dfs(int u, int fa){
	dp[u] = sz[u];
	for(int i = g[u];~i;i = n1[i]) if(p[i] != fa){
		dfs(p[i], u);
		dp[u] += dp[p[i]];
	}
}
int main(){
//	freopen("data.in", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof(h));
	memset(g, -1, sizeof(g));
	int x, y;
	for(int i = 1;i <= m;i ++) scanf("%d%d", &x, &y), ae(h, x, y), ae(h, y, x);
	for(int i = 1;i <= n;i ++) if(!vis[i]) tarjan(i, 0);
	++ tot;
	while(top) id[st[top --]] = tot, sz[tot] ++;
	for(int i = 1;i <= n;i ++) for(int j = h[i];~j;j = n1[j]) if(id[i] != id[p[j]]) ae(g, id[i], id[p[j]]);
	for(int i = 1;i <= tot;i ++) ans += sz[i] * (sz[i] - 1);
	int ret = 0;
	for(int i = 1;i <= tot;i ++){
		int tmp = 0;
		dfs(i, 0);
		for(int j = 1;j <= tot;j ++) tmp += (dp[j] - sz[j]) * sz[j];
		for(int j = 0;j <= n;j ++) ok[j] = 0;
		ok[0] = 1;
		for(int k = g[i];~k;k = n1[k])
			for(int j = n;j >= dp[p[k]];j --)
				ok[j] |= ok[j - dp[p[k]]];
		int mx = 0;
		for(int j = 0;j <= n;j ++) if(ok[j]) mx = max(mx, j * (n - sz[i] - j));
		ret = max(ret, tmp + mx);
	}
	printf("%d\n", n + ans + ret);
	return 0;
}