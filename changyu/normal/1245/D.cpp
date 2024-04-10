#include<cstdio>
#define int long long 
const int N=2003,INF=4e18;
int g[N][N],n,c[N],d[N],x[N],y[N],fa[N],s,dis[N],used[N];
inline int Abs(int a){return a<0?-a:a;}
inline int Dis(int x,int y,int xx,int yy){return Abs(x-xx)+Abs(y-yy);}
signed main()
{
	int u,v;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i);
	for(int i=1;i<=n;i++)scanf("%lld",c+i);
	for(int i=1;i<=n;i++)scanf("%lld",d+i);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		g[i][j]=Dis(x[i],y[i],x[j],y[j])*(d[i]+d[j]);
	for(int i=1;i<=n;i++)
	  g[i][0]=g[0][i]=c[i],dis[i]=INF;
	dis[0]=0;
	for(int j=0;j<=n;j++){
	  u=-1;
	  for(v=0;v<=n;v++)if(!used[v]&&(u<0||dis[v]<dis[u]))u=v;
	  s+=dis[u],used[u]=1;
	  for(v=0;v<=n;v++)if(!used[v]&&dis[v]>g[u][v])dis[v]=g[u][v],fa[v]=u;
	}
	printf("%lld\n",s);
	s=0;
	for(int i=1;i<=n;i++)if(!fa[i])s++;
	printf("%lld\n",s);
	for(int i=1;i<=n;i++)if(!fa[i])printf("%lld ",i);puts("");
	printf("%lld\n",n-s);
	for(int i=1;i<=n;i++)if(fa[i])printf("%lld %lld\n",fa[i],i);
	return 0;
}