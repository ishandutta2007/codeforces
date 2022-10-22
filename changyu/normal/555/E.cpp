#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int N=2e5+3;
struct edge{int v,nxt;}g[1200003];
int n,m,mm,head[N+N+N],k,st[N],tp,c,q[N],p[N],dfn[N],low[N],x[N],y[N],w[N],f[N],fa[N];
inline void Insert(int u,int v){g[k]=(edge){v,head[u]};head[u]=k++;}
int Find(int k){return p[k]==k?k:p[k]=Find(p[k]);}
void Dfs(int u,int p){
	int v;
	dfn[u]=low[u]=++c;
	st[++tp]=u;
	for(int i=head[u];~i;i=g[i].nxt)if(i^p^1){
	  v=g[i].v;
	  if(!dfn[v]){
		Dfs(v,i);
		low[u]=std::min(low[u],low[v]);
	  }
	  else low[u]=std::min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	  for(int x=0;x!=u;)x=st[tp--],q[x]=u;
}
void Lca(int u){
	int v;
	dfn[u]=++c;
	for(int i=head[u+n];~i;i=g[i].nxt)if((v=g[i].v)!=fa[u])
	  fa[v]=u,Lca(v),p[v]=u;
	for(int i=head[u+n+n];~i;i=g[i].nxt)
	  v=g[i].v,w[v]=w[v]?Find(w[v]):u;
}
int Update(int u,int w,int c){
	if(dfn[u]<=dfn[w])return u;
	if((~f[u])&&(f[u]^c))exit(0*puts("No"));
	p[u]=Update(p[u],w,c),f[u]=c;
	return p[u];
}
signed main(){
	memset(head,-1,sizeof head);
	int u,v;
	scanf("%d%d%d",&n,&m,&mm);
	for(;m--;)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	for(u=1;u<=n;u++)if(!dfn[u])
	  Dfs(u,-1);
	for(u=1;u<=n;u++)
	  for(int i=head[u];~i;i=g[i].nxt)if(q[v=g[i].v]!=q[u])
		Insert(q[u]+n,q[v]);
	for(int j=1;j<=mm;j++){
	  scanf("%d%d",x+j,y+j);
	  x[j]=q[x[j]],y[j]=q[y[j]];
	  Insert(x[j]+n+n,j),Insert(y[j]+n+n,j);
	}
	for(u=1;u<=n;u++)p[u]=u,dfn[u]=0;
	c=0;
	for(u=1;u<=n;u++)if(!dfn[u])
	  Lca(u);
	for(int j=1;j<=mm;j++)if(Find(x[j])!=Find(y[j]))return 0*puts("No");
	for(u=1;u<=n;u++)p[u]=!fa[u]?u:fa[u],f[u]=-1;
	for(int j=1;j<=mm;j++){
	  u=x[j],v=y[j];
	  Update(x[j],w[j],0);
	  Update(y[j],w[j],1);
	}
	return 0*puts("Yes");
}