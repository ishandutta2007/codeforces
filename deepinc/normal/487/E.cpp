#include<bits/stdc++.h>
using namespace std;
const int $=2e5+5,inf=1e9;
int n,m,Q,dfn[$],low[$],t,st[$],tp,N,sz[$],son[$],dep[$],id[$],w[$],Id[$],v[$<<2],f[$],top[$];
vector<int>E[$],T[$]; multiset<int>S[$]; char O[9];
#define pb push_back
void dfs(int p){
	dfn[p]=low[p]=++t; st[++tp]=p;
	for(int y:E[p])if(!dfn[y]){
		dfs(y); low[p]=min(low[p],low[y]);
		if(low[y]>=dfn[p]){
			T[p].pb(++N); f[N]=p;
			while(st[tp+1]^y)f[st[tp]]=N,S[N].insert(w[st[tp]]),T[N].pb(st[tp--]);
		}
	}else low[p]=min(low[p],dfn[y]);
}
void Dfs(int p){
	sz[p]=1; dep[p]=dep[f[p]]+1;
	for(int y:T[p])Dfs(y),sz[p]+=sz[y],sz[son[p]]<sz[y]&&(son[p]=y);
}
void DFS(int p,int tp){
	id[p]=++t; Id[t]=p; top[p]=tp;
	if(son[p])DFS(son[p],tp);
	for(int y:T[p])if(!id[y])DFS(y,y);
}
#define lc p<<1
#define rc lc|1
#define md (L+R>>1)
void build(int l,int r,int p=1,int L=1,int R=N){
	if(L==R){v[p]=Id[L]<=n?w[Id[L]]:*S[Id[L]].begin();return;}
	if(l<=md)build(l,r,lc,L,md); if(r>md)build(l,r,rc,md+1,R); v[p]=min(v[lc],v[rc]);
}
int ask(int l,int r,int p=1,int L=1,int R=N){
	if(l<=L&&R<=r)return v[p];
	return min(l<=md?ask(l,r,lc,L,md):inf,r>md?ask(l,r,rc,md+1,R):inf);
}
int Ask(int a,int b,int W=1e9){
	while(top[a]!=top[b]){if(dep[top[a]]<dep[top[b]])swap(a,b);W=min(W,ask(id[top[a]],id[a]));a=f[top[a]];}
	if(dep[a]>dep[b])swap(a,b); W=min(W,ask(id[a],id[b]));
	return min(W,a>n?w[f[a]]:inf);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q); N=n;
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1,a,b;i<=m;++i)scanf("%d%d",&a,&b),E[a].pb(b),E[b].pb(a);
	dfs(1); Dfs(1); t=0; DFS(1,1); build(1,N);
	for(int _=1,a,b;_<=Q;++_){
		scanf("%s%d%d",O,&a,&b);
		if(*O=='A')printf("%d\n",Ask(a,b));
		else{
			if(a^1)S[f[a]].erase(S[f[a]].find(w[a])),S[f[a]].insert(b),build(id[f[a]],id[f[a]]);
			w[a]=b; build(id[a],id[a]);
		}
	}
}