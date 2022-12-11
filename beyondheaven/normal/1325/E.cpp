#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MaxN 100123
#define MaxM 1000123
const int N=1000000;
int n,ans=0x3f3f3f3f;
int minp[MaxM];
inline void Sieve()
{
	static int prime[MaxN],cnt;
	static bool vis[MaxM];
	for(int i=2;i<=N;++i)
	{
		if(!vis[i])
		{
			prime[++cnt]=i;
			minp[i]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=N;++j)
		{
			vis[i*prime[j]]=1;
			minp[i*prime[j]]=std::min(minp[i],prime[j]);
			if(i%prime[j]==0)break;
		}
	}
}
struct Edge{int v,next;}edge[MaxN<<1];
int head[MaxM],num_edge=1;
inline void add_edge(int u,int v)
{
	#ifdef Dubug
	printf("add_edge(%d,%d);\n",u,v);
	#endif
	edge[++num_edge].v=v;
	edge[num_edge].next=head[u];
	head[u]=num_edge;
}
inline bool Extend(int x)
{
	if(x==1)return true;
	int p1,p2,c1=0,c2=0;
	for(p1=minp[x];x%p1==0;x/=p1,++c1);
	if(x==1&&c1%2==0)return true;
	else if(x==1)
	{
		add_edge(1,p1);add_edge(p1,1);
		return false;
	}
	else
	{
		for(p2=minp[x];x%p2==0;x/=p2,++c2);
		if(c1%2==0&&c2%2==0)return true;
		else
		{
			add_edge((c1%2==0?1:p1),(c2%2==0?1:p2));
			add_edge((c2%2==0?1:p2),(c1%2==0?1:p1));
		}
	}
	return false;
}
int dep[MaxM];
inline void Bfs(int s)
{
	memset(dep,-1,sizeof(dep));
	std::queue<int>q,qf;
	q.push(s);qf.push(0);dep[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		int f=qf.front();qf.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if(i==(f^1))continue;
			if(dep[v]!=-1)ans=std::min(ans,dep[u]+dep[v]+1);
			else
			{
				dep[v]=dep[u]+1;
				q.push(v);qf.push(i);
			}
		}
	}
}
int a[MaxN];
int main()
{
	Sieve();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	if(Extend(a[i])){puts("1");return 0;}
	for(int i=1;i<=1000;++i)
	if(minp[i]==i||i==1)Bfs(i);
	printf("%d\n",(ans==0x3f3f3f3f?-1:ans));
	return 0;
}