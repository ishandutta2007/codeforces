#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define LL long long
#define M 800000
#define N 700
using namespace std;
const int inf=7000000;
int f[700][700];
int n,m,k,team,target;
int start[700];
bool v[700];
int match[700];
struct EDGE {int adj,w,next; } edge[M*2];
struct dat {int id,dist; dat(int id=0,int dist=0):id(id),dist(dist) {} };
struct cmp { bool operator () (const dat &a,const dat &b) {return a.dist>b.dist; } };
priority_queue <dat,vector<dat>,cmp> q;
int top,gh[N],dist[N][N];
void addedge(int x,int y,int w)
{
	edge[++top].adj=y;
	edge[top].w=w;
	edge[top].next=gh[x];
	gh[x]=top;
}
int dijkstra(int s)
{
	memset(v,0,sizeof(v));
	dist[s][s]=0;
	while (!q.empty())q.pop();
	q.push(dat(s,0));
	while (!q.empty())
	{
		dat x=q.top();
		q.pop();
		if (v[x.id])continue;
		v[x.id]=1;
		for(int p=gh[x.id];p;p=edge[p].next)
		{
			if (x.dist+edge[p].w<dist[s][edge[p].adj])
			{
				dist[s][edge[p].adj]=x.dist+edge[p].w;
				q.push(dat(edge[p].adj,dist[s][edge[p].adj]));
			}
		}
	}
}
bool dfs(int x)
{
	for(int p=gh[x];p;p=edge[p].next)
		if (!v[edge[p].adj])
		{
			v[edge[p].adj]=1;
			if (match[edge[p].adj]==0||dfs(match[edge[p].adj]))
			{
				match[edge[p].adj]=x;
				return 1;
			}
		}
	return 0;
}
bool judge(int x)
{
	top=0;
	for(int i=1;i<=team;i++)gh[i]=0;
	for(int i=1;i<=team;i++)
		for(int j=1;j<=n;j++)
			if (dist[start[i]][j]<=x)addedge(i,j,0);
	
	memset(match,0,sizeof(match));
	int ans=0;
	for(int i=1;i<=team;i++)
	{	
		memset(v,0,sizeof(v));
		if (dfs(i))ans++;
	}
	return ans>=target;
}
void work()
{
	int l=0;
	int r=6100000;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (judge(mid))r=mid;
		else l=mid+1;
	}
	if (judge(l))cout<<l<<endl;
	else cout<<-1<<endl;
}
int main()
{
	cin>>n>>m>>team>>target;
	for(int i=1;i<=team;i++)scanf("%d",&start[i]);
	memset(gh,0,sizeof(gh));
	top=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
	}
	memset(dist,63,sizeof(dist));
	for(int i=1;i<=team;i++)dijkstra(start[i]);
	work();	
	
}