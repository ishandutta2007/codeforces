#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct bian{int nxt,to,w;}bi[400040];
int n,w[200020],head[200020],num;
inline void add(int from,int to,int l){bi[++num]=bian{head[from],to,l};head[from]=num;}
int all,siz[200020],maxs[200020],rt;
bool vis[200020];
void getrt(int v,int fa)
{
	siz[v]=1,maxs[v]=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa||vis[u])continue;
		getrt(u,v);
		siz[v]+=siz[u];
		if(siz[u]>maxs[v])maxs[v]=siz[u];
	}
	if(all-siz[v]>maxs[v])maxs[v]=all-siz[v];
	if(maxs[v]<maxs[rt])rt=v;
}
double sum,ans=1e25,sumd;
double d[200020],alld;
int p;
void getdata(int v,int fa,int dis)
{
	sumd+=1.5*w[v]*sqrt(dis);
	sum+=dis*sqrt(dis)*w[v];
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		getdata(u,v,dis+bi[i].w);
	}
}
int getsiz(int v,int fa)
{
	int ret=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa||vis[u])continue;
		ret+=getsiz(u,v);
	}
	return ret;
}
void solve(int v)
{
	vis[v]=1;
	sum=0;alld=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;sumd=0;
		getdata(u,v,bi[i].w);
		d[u]=sumd;
		alld+=sumd;
	}
	if(sum<ans)ans=sum,p=v;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(vis[u])continue;
		if(alld-2*d[u]<0)
		{
			all=getsiz(u,v);rt=0;
			getrt(u,v);solve(rt);
			return ;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	int x,y,l;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&l);
		add(x,y,l),add(y,x,l);
	}
	all=n;maxs[0]=0x3f3f3f3f;
	getrt(1,0);
	solve(rt);
	printf("%d %.12lf",p,ans);
	return 0;
}