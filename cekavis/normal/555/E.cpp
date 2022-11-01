#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, q, id, cnt, dfn[N], low[N], f[N], a[N], b[N], c[N], bl[N];
vector<int> e[N], w[N], E[N];
vector<pair<int,int>> s;
void add(vector<int> *e, int x, int y){ e[x].push_back(y), e[y].push_back(x);}
void dfs2(int u){
	bl[u]=id;
	for(int v:e[u]) if(v && !bl[v]) dfs2(v);
}
void dfs(int u, int fa=0){
	dfn[u]=low[u]=++cnt;
	for(int &v:e[u]) if(v!=fa){
		if(!dfn[v]){
			dfs(v, u), low[u]=min(low[u], low[v]);
			if(low[v]==dfn[v]) s.emplace_back(u, v), v=0;
		}
		else low[u]=min(low[u], dfn[v]);
	}
	else v=fa=0;
	if(low[u]==dfn[u]) ++id, dfs2(u);
}
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
void dfs3(int u, int fa=0){
	for(int v:E[u]) if(v!=fa)
		dfs3(v, u), f[v]=u, a[u]+=a[v], b[u]+=b[v], c[u]+=c[v];
	for(int v:w[u]) if(v!=f[v]) ++c[find(v)];
	if(a[u]>c[u] && b[u]>c[u]) puts("No"), exit(0);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	int x, y;
	for(int i=1; i<=m; ++i) scanf("%d%d", &x, &y), add(e, x, y);
	for(int i=1; i<=n; ++i) if(!dfn[i]) dfs(i);
	for(int i=1; i<=id; ++i) f[i]=i;
	for(auto i:s) add(E, x=bl[i.first], y=bl[i.second]), f[find(x)]=find(y);
	for(int i=1; i<=q; ++i){
		scanf("%d%d", &x, &y);
		if((x=bl[x])!=(y=bl[y])) ++a[x], ++b[y], add(w, x, y);
		if(find(x)!=find(y)) return puts("No"), 0;
	}
	for(int i=1; i<=id; ++i) f[i]=i;
	for(int i=1; i<=id; ++i) if(i==f[i]) dfs3(i);
	return puts("Yes"), 0;
}