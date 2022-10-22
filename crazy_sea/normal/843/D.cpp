#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+10;
struct edge{
	int next,to,w;
}e[N];
int first[N],len;
const ll inf=2e13;
ll dis[N];
int de[N],x,y,z,n,m,vis[N],a[N];
vector<int>v[N];
void add(int a,int b,int c)
{
	e[++len]=edge{first[a],b,c};
	first[a]=len;
}
struct node{
	int id;
	ll dis;
	bool operator <(node a)const
	{
		return dis>a.dis;
	}
};
priority_queue<node>q;
void dijkstra()
{
	for(int i=0;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	q.push((node){1,0});
	while(!q.empty())
	{
		x=q.top().id;q.pop();
		for(int i=first[x];i;i=e[i].next)
		{
			y=e[i].to;
			if(dis[y]>dis[x]+e[i].w)
				dis[y]=dis[x]+e[i].w,q.push((node){y,dis[y]});
		}
	}
}
void update(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(int i=first[x];i;i=e[i].next)
	{
		if(de[x]+e[i].w>=n) continue;
		y=e[i].to;
		if(de[y]>de[x]+e[i].w)
			de[y]=de[x]+e[i].w,v[de[y]].push_back(y);
	}
}
void work()
{
	for(int i=0;i<=n;i++) vis[i]=0,v[i].clear();
	for(int i=2;i<=n;i++) de[i]=n+1;
	v[0].push_back(1);
	for(int i=0;i<n;i++)
		for(int j=0;j<(int)v[i].size();j++)
			update(v[i][j]);
	for(int i=2;i<=n;i++) dis[i]+=de[i];
}
void update()
{
	for(int x=1;x<=n;x++)
		for(int i=first[x];i;i=e[i].next)
			e[i].w=a[i]-(dis[e[i].to]-dis[x]);
}
int Q,op;
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&x,&y,&a[i]),add(x,y,a[i]);
	dijkstra();
	update();
	while(Q--)
	{
		scanf("%d",&op);
		if(op==2)
		{
			scanf("%d",&m);
			for(int i=1;i<=m;i++)
				scanf("%d",&x),e[x].w++,a[x]++;
			work(),update();
		}
		else scanf("%d",&x),printf("%lld\n",dis[x]>=inf?-1:dis[x]);
	}
}