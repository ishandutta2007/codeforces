#include <bits/stdc++.h>
using namespace std;

#define N 100010
int p[N * 2], n1[N * 2], h[N], ee, n, m, dfn[N], low[N], dfntot, st[N], top, vis[N], is[N], scc, cnt[N], sc[N];

int fa[N], ok[N];

int gf(int x){
	return (x == fa[x]) ? x : (fa[x] = gf(fa[x]));
}

void ae(int x, int y){
	p[ee] = y; n1[ee] = h[x]; h[x] = ee ++;
}

void dfs(int u){
	st[++ top] = u;
	vis[u] = is[u] = 1;
	dfn[u] = low[u] = ++ dfntot;
	for(int i = h[u];~i;i = n1[i]){
		if(!vis[p[i]]) dfs(p[i]), low[u] = min(low[u], low[p[i]]);
		else if(is[p[i]]) low[u] = min(low[u], dfn[p[i]]);
	}
	if(dfn[u] == low[u]){
		++ scc;
		int v;
		do{
			v = st[top];
			cnt[scc] ++;
			is[v] = 0;
			sc[v] = scc;
			top --;
		}while(u != v);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	int x, y;
	memset(h, -1, sizeof(h));
	for(int i = 1;i <= m;i ++){
		scanf("%d%d", &x, &y);
		ae(x, y);
	}
	for(int i = 1;i <= n;i ++) if(!vis[i]) dfs(i);
	for(int i = 1;i <= scc;i ++) ok[i] = cnt[i] != 1;
	for(int i = 1;i <= n;i ++) fa[i] = i;
	for(int i = 1;i <= n;i ++)
		for(int j = h[i];~j;j = n1[j]){
			if(sc[i] != sc[p[j]]){
				int x = sc[i], y = sc[p[j]];
				if(gf(x) == gf(y)) continue;
				ok[gf(x)] |= ok[gf(y)];
				fa[gf(y)] = gf(x);
			}
		}
	int ans = n;
	for(int i = 1;i <= scc;i ++){
		if(!vis[gf(i)]) continue;
		ans -= ok[gf(i)] ^ 1;
		vis[gf(i)] = 0;
	}
	cout << ans << endl;
	return 0;
}