#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
#define MN 750
#define MX 10000000
#define MV 1500
#define ME 300000
#define S MV+1
#define T MV+2
#define INF 0x7FFFFFFF
namespace flow
{
struct edge{int nx,t,w;}e[ME*2+5];
int h[MV+5],en=1,d[MV+5],c[MV+5],q[MV+5],qn;
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,0};h[y]=en;
}
bool bfs()
{
	int i,j;memset(d,0,sizeof(d));
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
		e[i].w-=k;e[i^1].w+=k;u+=k;
		if(u==r)return u;
	}
	return d[x]=0,u;
}
}
char s[MX+5];
int tn,c[MX+5][2],f[MX+5],q[MX+5],qn,t[MX+5],z[MX+5],zn,v[MX+5];
bitset<MN+5> b[MN+5],bb;
int main()
{
	int n,i,j,x,y,ans;
	scanf("%d",&n);ans=n;
	for(i=1;i<=n;++i)
	{
		scanf("%s",s);
		for(j=x=0;s[j];z[++zn]=x=c[x][s[j++]-'a'],v[zn]=i)
			if(!c[x][s[j]-'a'])c[x][s[j]-'a']=++tn;
		t[x]=i;
	}
	for(i=0;i<2;++i)if(c[0][i])q[++qn]=c[0][i];
	for(i=1;i<=qn;++i)for(j=0;j<2;++j)if(c[q[i]][j])
	{
		for(x=f[q[i]];x&&!c[x][j];x=f[x]);
		f[c[q[i]][j]]=c[x][j];
		if(!t[c[q[i]][j]])t[c[q[i]][j]]=t[c[x][j]];
		q[++qn]=c[q[i]][j];
	}
	for(i=1;i<=zn;++i)b[v[i]][t[z[i]]]=b[v[i]][t[f[z[i]]]]=1;
	for(x=1;x<=n;++x)for(i=1;i<=n;++i)if(b[i][x])b[i]|=b[x];
	using namespace flow;
	for(i=1;i<=n;++i)
	{
		ins(S,i,1);ins(i+n,T,1);
		for(j=1;j<=n;++j)if(i!=j&&b[i][j])ins(i,j+n,1);
	}
	while(bfs())ans-=dfs(S,INF);
	printf("%d\n",ans);
	for(bfs(),i=1;i<=n;++i)if(d[i]&&!d[i+n])printf("%d ",i);
}