#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, q, cnt, a[N], b[N], f[N], p[N], s[N], fa[N], dep[N], siz[N], dfn[N], top[N], stk[N], c[N*4];
vector<int> e[N], E[N];
void dfs1(int u){
	siz[u]=1;
	for(int v:e[u]) if(v!=fa[u])
		fa[v]=u, dep[v]=dep[u]+1, dfs1(v), siz[u]+=siz[v];
}
void dfs2(int u){
	dfn[u]=++cnt;
	int w=0;
	for(int v:e[u]) if(v!=fa[u] && siz[v]>siz[w]) w=v;
	if(w) top[w]=top[u], dfs2(w);
	for(int v:e[u]) if(v!=fa[u] && v!=w) top[v]=v, dfs2(v);
}
bool cmp(int x, int y){ return dfn[x]<dfn[y];}
int lca(int x, int y){
	while(top[x]!=top[y])
		if(dep[top[x]]>dep[top[y]]) x=fa[top[x]]; else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
bool calc(int a, int b, int c, int d){
	int x=(c+s[d]-1)/s[d]-(a+s[b]-1)/s[b];
	return x>0 || (!x && b<d);
}
void dfs3(int u){
	for(int v:E[u]){
		dfs3(v);
		if(p[v] && (!p[u] || calc(f[v]+dep[v]-dep[u], p[v], f[u], p[u])))
			p[u]=p[v], f[u]=f[v]+dep[v]-dep[u];
	}
}
void dfs4(int u){
	for(int v:E[u]){
		if(p[u] && (!p[v] || calc(f[u]+dep[v]-dep[u], p[u], f[v], p[v])))
			p[v]=p[u], f[v]=f[u]+dep[v]-dep[u];
		dfs4(v);
	}
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	dfs1(1), top[1]=1, dfs2(1);
	scanf("%d", &q);
	while(q--){
		int k, m, x, y;
		scanf("%d%d", &k, &m);
		for(int i=1; i<=k; ++i) scanf("%d%d", a+i, s+i), c[i]=a[i], p[a[i]]=i;
		for(int i=1; i<=m; ++i) scanf("%d", b+i), c[i+k]=b[i];
		y=x=k+m, sort(c+1, c+x+1, cmp);
		int t=1;
		stk[1]=1;
		for(int i=1; i<=x; ++i){
			int u=lca(stk[t], c[i]);
			c[++y]=u;
			while(t>1 && dep[stk[t-1]]>=dep[u])
				E[stk[t-1]].push_back(stk[t]), --t;
			if(stk[t]==u) --t;
			if(dep[stk[t]]>dep[u]) E[u].push_back(stk[t]), --t;
			stk[++t]=u;
			if(u!=c[i]) stk[++t]=c[i];
		}
		while(t>1) E[stk[t-1]].push_back(stk[t]), --t;
		dfs3(1), dfs4(1);
		for(int i=1; i<=m; ++i) printf("%d%c", p[b[i]], " \n"[i==m]);
		for(int i=1; i<=y; ++i) p[c[i]]=f[c[i]]=0, E[c[i]].clear();
	}
	return 0;
}