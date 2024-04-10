#include<bits/stdc++.h>
const int N=1e5+3,K=17;
struct edge{int v,nxt;}g[N+N];
int n,m,head[N],k,fa[N][K],dep[N],dfn[N],siz[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u){
	int v;
	dfn[u]=++k,siz[u]=1;
	for(int j=1;j<K;j++)fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa[u][0])
	  fa[v][0]=u,dep[v]=dep[u]+1,Dfs(v),siz[u]+=siz[v];
}
inline int Lca(int u,int v){
	if(dep[u]<dep[v])std::swap(u,v);
	for(int j=K-1;~j;j--)if(dep[fa[u][j]]>=dep[v])u=fa[u][j];
	if(u==v)return u;
	for(int j=K-1;~j;j--)if(fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return fa[u][0];
}
inline bool Subtree(int u,int v){
	return dfn[v]>=dfn[u]&&dfn[v]<dfn[u]+siz[u];
}
inline bool Onpath(int u,int v,int lca,int w){
	return!Subtree(w,fa[lca][0])&&(Subtree(w,u)||Subtree(w,v));
}
inline int Dis(int u,int v,int lca){return dep[u]+dep[v]-2*dep[lca];}
bool Cmp(const int&u,const int&v){return dfn[u]<dfn[v];}
int main(){
	int u,v,w,s,t,r,x,s0,s1,p[4],d0,d1,len;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	k=0,Dfs(1);
	scanf("%d",&m);
	for(;m--;){
	  scanf("%d%d%d%d%d",&u,&v,&s,&t,&x);
	  if(dfn[s]>dfn[t])std::swap(s,t);
	  w=Lca(u,v),r=Lca(s,t);
	  len=Dis(u,v,w)+1,d0=Dis(s,t,r);
	  s0=len-1+d0;
	  p[0]=u,p[1]=v,p[2]=s,p[3]=t;
	  std::sort(p,p+4,Cmp);
	  s1=Dis(p[0],p[1],Lca(p[0],p[1]))+Dis(p[1],p[2],Lca(p[1],p[2]))+Dis(p[2],p[3],Lca(p[2],p[3]))+Dis(p[3],p[0],Lca(p[3],p[0]))>>1;
	  if(Onpath(u,v,w,s)||Onpath(u,v,w,t)||Onpath(u,v,w,r)||Subtree(s,w)&&Subtree(w,t))
		d1=d0+len-(s0-s1)*2;
	  else
		d1=(s1-s0)*2+d0+len;
	  if((d0^d1)&1){
		if(~(d0^x)&1)puts(x>=d0?"yes":"no");
		else puts(x>=d1?"yes":"no");
	  }
	  else{
		d0=std::min(d0,d1);
		if((d0^x)&1)puts("no");
		else puts(x>=d0?"yes":"no");
	  }
	}return 0;
}