#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 5000
#define MV 10000
#define ME 20000
#define S MV+1
#define T MV+2
#define INF 0x7FFFFFFF
struct edge{int nx,t,w;}e[ME*2+5];
int n,m,x[MN+5],y[MN+5];
int h[MV+5],en,d[MV+5],q[MV+5],qn,c[MV+5];
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,0};h[y]=en;
}
bool bfs()
{
	int i,j;
	memset(d,0,sizeof(d));
	for(d[q[i=qn=0]=S]=1;i<=qn;++i)for(j=c[q[i]]=h[q[i]];j;j=e[j].nx)
		if(e[j].w&&!d[e[j].t])d[q[++qn]=e[j].t]=d[q[i]]+1;
	return d[T];
}
int dfs(int x,int r)
{
	if(x==T)return r;
	int k,u=0;
	for(int&i=c[x];i;i=e[i].nx)if(e[i].w&&d[e[i].t]==d[x]+1)
	{
		k=dfs(e[i].t,min(e[i].w,r-u));
		u+=k;e[i].w-=k;e[i^1].w+=k;
		if(u==r)return u;
	}
	return d[x]=0,u;
}
bool solve(int z)
{
	int i,s=0;
	memset(h,0,sizeof(h));en=1;
	for(i=1;i<=m;++i)ins(S,i,1),ins(i,x[i]+m,1),ins(i,y[i]+m,1);
	for(i=1;i<=n;++i)ins(i+m,T,z);
	while(bfs())s+=dfs(S,INF);
	return s==m;
}
int main()
{
	int i,j,l,r,mid,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&x[i],&y[i]);
	for(l=0,r=n;l<=r;)
		if(solve(mid=l+r>>1))ans=mid,r=mid-1;
		else l=mid+1;
	printf("%d\n",ans);
	solve(ans);
	for(i=1;i<=m;++i)for(j=h[i];j;j=e[j].nx)if(!e[j].w)printf("%d %d\n",e[j].t-m,x[i]^y[i]^(e[j].t-m));
}