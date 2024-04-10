#include<bits/stdc++.h>
const int N=1e5+3;
struct edge{int v,nxt;}g[N+N];
int n,deg[N],head[N],k,dep[N],mn,mx,rt;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs0(int u,int fa){
	int v;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  dep[v]=dep[u]^1,Dfs0(v,u);
	if(deg[u]==1&&dep[u])mn=3;
}
void Dfs1(int u,int fa){
	int v,c=0;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  Dfs1(v,u);
	  c+=deg[v]==1;
	}
	if(c>1)mx-=c-1;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u),++deg[u],++deg[v];
	for(u=1;u<=n;u++)if(deg[u]==1){rt=u;break;}
	mn=1;
	Dfs0(rt,0);
	for(u=1;u<=n;u++)if(deg[u]>1){rt=u;break;}
	mx=n-1;
	Dfs1(rt,0);
	printf("%d %d\n",mn,mx);
	return 0;
}