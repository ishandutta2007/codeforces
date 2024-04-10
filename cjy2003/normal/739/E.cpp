#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
queue<int>q;
const int S=2001,T=2002,SP=2003,SU=2004;
const double eps=1e-7;
struct bian
{
	double w;
	int to,nxt,f;
}bi[50050];
int n,a,b,head[2020],num=1,depth[2020],cur[2020];
double ans,p[2020],u[2020],dis[2020];
bool bj[2020];
void add(int from,int to,int f,double w)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].f=f;
	bi[num].w=w;
}
bool spfa()
{
	for(int i=1;i<=2004;++i)dis[i]=-1e15,cur[i]=head[i];
	dis[S]=0;
	q.push(S);bj[S]=1;
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();bj[x]=0;
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].f)
			{
				y=bi[i].to;
				if(dis[x]+bi[i].w>dis[y]+eps)
				{
					dis[y]=dis[x]+bi[i].w;depth[y]=depth[x]+1;
					if(!bj[y])bj[y]=1,q.push(y);
				}
			}
	}
	return dis[T]>0;
}
int dfs(int v,int last)
{
	if(v==T)
	{
		ans+=dis[T]*last;
		return last;	
	}
	int now=0,u;
	for(int i=cur[v];i;i=bi[i].nxt,cur[v]=i)
		if(bi[i].f)
		{
			u=bi[i].to;
			if(dis[u]>dis[v]+bi[i].w+eps||depth[u]!=depth[v]+1)continue;
			int dmin=dfs(u,min(last,bi[i].f));	
			bi[i].f-=dmin;
			bi[i^1].f+=dmin;
			now+=dmin;
			last-=dmin;
			if(!last)return now;
		}
	return now;
}
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	add(S,SP,a,0);add(SP,S,0,0);
	add(S,SU,b,0);add(SU,S,0,0);
	for(int i=1;i<=n;++i)scanf("%lf",&p[i]),add(SP,i,1,p[i]),add(i,SP,0,-p[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&u[i]),add(SU,i,1,u[i]),add(i,SU,0,-u[i]);
	for(int i=1;i<=n;++i)add(i,T,1,0),add(T,i,0,0),add(i,T,1,-u[i]*p[i]),add(T,i,0,u[i]*p[i]);
	while(spfa())
	{
		while(dfs(S,0x7fffffff));
	}
	printf("%lf",ans);
	return 0;
}