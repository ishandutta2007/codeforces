#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,l[100005],r[100005],c[100005],cnt,cnt2,dis[100005],pre[100005];
struct eg
{
	int x,y,z,dis,re,id;
}e[100005];
vector<int> bi[100005];
set<int> all;
map<int,int> mp;
void edg(int x,int y,int z,int dis,int id)
{
	cnt2++;
	e[cnt2]={x,y,z,dis,cnt2+1,id};
	bi[x].push_back(cnt2);
	cnt2++;
	e[cnt2]={y,x,0,-dis,cnt2-1,0};
	bi[y].push_back(cnt2);
}
bool bfs(int s,int t)
{
	queue<int> q;
	q.push(s);
	for (i=1;i<=cnt+2;i++)
	{
		dis[i]=-1<<30;
		pre[i]=-1;
	}
	dis[s]=0;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (i=0;i<bi[x].size();i++)
		{
			if (e[bi[x][i]].z&&e[bi[x][i]].y!=s&&dis[e[bi[x][i]].y]<dis[x]+e[bi[x][i]].dis)
			{
				dis[e[bi[x][i]].y]=dis[x]+e[bi[x][i]].dis;
				pre[e[bi[x][i]].y]=bi[x][i];
				q.push(e[bi[x][i]].y);
			}
		}
	}
	if (pre[t]==-1) return 0;
	int mx=1<<30;
	for (i=t;i!=s;i=e[pre[i]].x)
	{
		mx=min(mx,e[pre[i]].z);
	}
	for (i=t;i!=s;i=e[pre[i]].x)
	{
		e[pre[i]].z-=mx;
		e[e[pre[i]].re].z+=mx;
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i]>>c[i];
		all.insert(l[i]);
		all.insert(l[i]+r[i]);
	}
	for (set<int>::iterator it=all.begin();it!=all.end();it++) mp[*it]=++cnt;
	for (i=1;i<cnt;i++) edg(i,i+1,1<<30,0,0);
	edg(cnt+1,1,m,0,0);edg(cnt,cnt+2,m,0,0);
	for (i=1;i<=n;i++)
	{
		edg(mp[l[i]],mp[l[i]+r[i]],1,c[i],i);
	}
	for (;bfs(cnt+1,cnt+2););
	for (i=1;i<=cnt2;i++)
	{
		if (!e[i].id) continue;
		if (e[e[i].re].z) cout<<1<<' '; else cout<<0<<' ';
	}
	return 0;
}