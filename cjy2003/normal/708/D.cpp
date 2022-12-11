#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int S=101,T=102,inf=0x3f3f3f3f;
struct bian
{
	int nxt,to,f,w;
}bi[10010];
int n,m,head[110],num=1,d[110],dep[110];
long long ans,dis[110];
bool in[110];
inline void add(int from,int to,int f,int w){bi[++num]=bian{head[from],to,f,w};head[from]=num;}
inline void ADD(int x,int y,int f,int w){add(x,y,f,w),add(y,x,0,-w);}
bool spfa()
{
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(S);dis[S]=0;in[S]=1;
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();in[x]=0;
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(bi[i].f&&dis[x]+bi[i].w<dis[y])
			{
				dis[y]=dis[x]+bi[i].w;
				dep[y]=dep[x]+1;
				if(!in[y])q.push(y),in[y]=1;
			}
		}
	}
	return dis[T]!=0x3f3f3f3f3f3f3f3f;
}
int dfs(int v,int last)
{
	if(v==T)
	{
		ans+=last*dis[v];
		return last;
	}
	int now=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(bi[i].f&&dis[u]==dis[v]+bi[i].w&&dep[u]==dep[v]+1)
		{
			int dmin=dfs(u,min(bi[i].f,last));
			last-=dmin,now+=dmin;
			bi[i].f-=dmin,bi[i^1].f+=dmin;
			if(!last)break;
		}
	}
	return now;
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y,f,c;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d %d",&x,&y,&c,&f);
		d[y]+=f;d[x]-=f;
		if(f>c)
		{
			ans+=f-c;
			ADD(x,y,inf,2);
			ADD(y,x,f-c,0);
			ADD(y,x,c,1);
		}
		else
		{
			ADD(x,y,c-f,1);
			ADD(x,y,inf,2);
			ADD(y,x,f,1);
		}
	}
	for(int i=1;i<=n;++i)
		if(d[i]>0)ADD(S,i,d[i],0);
		else ADD(i,T,-d[i],0);
	ADD(n,1,inf,0);
	while(spfa())
		while(dfs(S,0x3f3f3f3f));
	printf("%lld",ans);
	return 0;
}