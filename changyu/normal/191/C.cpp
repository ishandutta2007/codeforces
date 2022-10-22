#include<cstdio>
int read(){
	int a=0;char c=getchar();
	while(c<48||c>57)c=getchar();while(c>47&&c<58)a=a*10+c-48,c=getchar();
	return a;
}
const int N=1e5+1;
struct edge{int v,nxt;}g[N*2];
int n,m,d[N],head[N],k,q[N],l,r,p[N][18],lg[N],xd,b[N],ans[N],x[N],y[N];
int Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
int lca(int u,int v){
	if(d[u]<d[v])u^=v,v^=u,u^=v;
	for(int i=d[u]-d[v],k=0;i;i>>=1,k++)
	  if(i&1)u=p[u][k];
	if(u==v)return u;
	for(int i=lg[d[u]];~i;i--)
	  if(p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
	return p[u][0];
}
int dfs(int u){
	int v;
	ans[u]=b[u];
	for(int i=head[u],t;i;i=g[i].nxt)if(p[u][0]!=(v=g[i].v))
	  ans[u]+=dfs(v);
	return ans[u];
}
int main()
{
	int u,v;
	n=read();
	for(int i=1;i<n;i++)x[i]=u=read(),y[i]=v=read(),Insert(u,v),Insert(v,u);
	d[q[0]=1]=1;
	while(l<=r){
	  u=q[l++];
	  for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=p[u][0])
		q[++r]=v,p[v][0]=u,d[v]=d[u]+1,xd=d[v];
	}
	for(int i=2;i<=xd;i++)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=lg[xd];j++)
	  for(int i=1;i<=n;i++)
		p[i][j]=p[p[i][j-1]][j-1];
	m=read();
	while(m--)
	  b[u=read()]++,b[v=read()]++,u=lca(u,v),b[u]-=2;
	dfs(1);
	for(int i=1;i<n;i++){
	  if(d[x[i]]<d[y[i]])x[i]^=y[i],y[i]^=x[i],x[i]^=y[i];
	  printf("%d ",ans[x[i]]);
	}return 0;
}