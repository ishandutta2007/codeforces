#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
vector<pii>g[300004];
int f[300004];
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
bool vis[300004];
int par[20][300004],lg[300004],d[300004],dep[300004];
int n,q,cnt,L[300004],R[300004];
int u[500004],v[500004],w[500004];
bool ans[500004];
void dfs(int x){
	vis[x]=1;
	L[x]=++cnt;
	for(int i=1;i<=lg[dep[x]];i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto y:g[x])if(y.fi!=par[0][x])
		d[y.fi]=d[x]^y.se,dep[y.fi]=dep[x]+1,par[0][y.fi]=x,dfs(y.fi);
	R[x]=++cnt;
}
int lca(int u,int v){
	if(dep[v]<dep[u])swap(u,v);
	while(dep[u]!=dep[v])v=par[lg[dep[v]-dep[u]]][v];
	if(u==v)return u;
	for(int i=lg[dep[u]];~i;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
	return par[0][u];
}
int bit[600004];
void upd(int id,int x){
	for(;id<=n+n;id+=(id&-id))bit[id]+=x;
}
int qry(int id){
	int res=0;
	for(;id;id-=(id&-id))res+=bit[id];
	return res;
}
void upd(int x){
	upd(L[x],1),upd(R[x],-1);
}
int ask(int x){
	return qry(L[x]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		int U=F(u[i]),V=F(v[i]);
		if(U!=V)ans[i]=1,f[U]=V,g[u[i]].push_back(mkp(v[i],w[i])),g[v[i]].push_back(mkp(u[i],w[i]));
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=q;i++)if(!ans[i]){
		int U=u[i],V=v[i],L=lca(U,V);
		if(ask(U)+ask(V)-ask(L)*2==0&&(d[U]^d[V]^w[i])==1){
			ans[i]=1;
			while(U!=L)upd(U),U=par[0][U];
			while(V!=L)upd(V),V=par[0][V];
		}
	}
	for(int i=1;i<=q;i++)puts(ans[i]?"YES":"NO");
}