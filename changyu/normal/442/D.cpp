#include<cstdio>
#include<cstring>
#define max(a,b)((a)>(b)?(a):(b))
const int N=1e6+3;
struct edge{int v,nxt;}g[N];
int n,fa[N],head[N],k,f[N],col[N],t,mx[N],mx1[N],w[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
inline void Add(int u){
	f[u]=1;
	int v=u;u=fa[u];
	for(;u;u=fa[u],v=fa[v]){
	  int tmp;
	  if(f[v]>mx[u])mx1[u]=mx[u],mx[u]=f[v],w[u]=v;
	  else mx1[u]=max(mx1[u],f[v]);
	  tmp=f[u];
	  if(u==1)f[u]=mx[u];
	  else if(~mx1[u])f[u]=max(mx1[u]+1,f[w[u]]);
	  else f[u]=f[w[u]];
	  if(tmp==f[u])break;
	}
}
int main(){
	int v;
	memset(mx,-1,sizeof mx);memset(mx1,-1,sizeof mx1);
	scanf("%d",&n);n++;
	for(v=2;v<=n;v++)
	  scanf("%d",&fa[v]),Insert(fa[v],v),
	  Add(v),printf("%d ",f[1]);
	return 0;
}