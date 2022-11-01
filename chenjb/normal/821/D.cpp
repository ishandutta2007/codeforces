#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#define LL long long
using namespace std;
int n,m,k;
map< pair<int,int> , int > dic;
vector< pair<int,int> > g[30010];
queue<int> q;
int d[30010],v[30010];
int st,ed;
pair<int,int> data[10010];
void init()
{
	cin>>n>>m>>k;
	dic.clear();
	for(int i=1;i<=n+m+k;i++)g[i].clear();
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&data[i].first,&data[i].second);
		int x=data[i].first; int y=data[i].second;
		if (x==1&&y==1)st=n+m+i;
		if (x==n&&y==m)ed=n+m+i;
		dic[make_pair(x,y)]=i;
		if (x>1)
		{
			g[n+m+i].push_back(make_pair(x-1,1));
			g[x-1].push_back(make_pair(n+m+i,0));
		}
		if (x<n)
		{
			g[n+m+i].push_back(make_pair(x+1,1));
			g[x+1].push_back(make_pair(n+m+i,0));
		}
		if (y>1)
		{
			g[n+m+i].push_back(make_pair(n+y-1,1));
			g[n+y-1].push_back(make_pair(n+m+i,0));
		}
		if (y<m)
		{
			g[n+m+i].push_back(make_pair(n+y+1,1));
			g[n+y+1].push_back(make_pair(n+m+i,0));
		}
		g[n+m+i].push_back(make_pair(x,1));
		g[x].push_back(make_pair(n+m+i,0));
		g[n+m+i].push_back(make_pair(n+y,1));
		g[n+y].push_back(make_pair(n+m+i,0));
	}
	for(int i=1;i<=k;i++)
	{
		int x=data[i].first; int y=data[i].second;
		if (dic[make_pair(x-1,y)])g[n+m+i].push_back(make_pair(n+m+dic[make_pair(x-1,y)],0));
		if (dic[make_pair(x+1,y)])g[n+m+i].push_back(make_pair(n+m+dic[make_pair(x+1,y)],0));
		if (dic[make_pair(x,y-1)])g[n+m+i].push_back(make_pair(n+m+dic[make_pair(x,y-1)],0));
		if (dic[make_pair(x,y+1)])g[n+m+i].push_back(make_pair(n+m+dic[make_pair(x,y+1)],0));
	}
	if (!dic[make_pair(n,m)])
	{
		k++;
		g[n].push_back(make_pair(n+m+k,0));
		g[n+m].push_back(make_pair(n+m+k,0));
		ed=n+m+k;
	}

	/*for(int i=1;i<=n+m+k;i++)
		for(int j=1;j<g[i].size();j++)
			cout<<i<<"-->"<<g[i][j].first<<"==="<<g[i][j].second<<endl;
	cout<<st<<endl;
	cout<<ed<<endl;
	*/
}
void spfa()
{
	for(int i=1;i<=n+m+k;i++)d[i]=2047483647;
	for(int i=1;i<=n+m+k;i++)v[i]=0;
	v[st]=1;
	d[st]=0;
	while (!q.empty())q.pop();
	q.push(st);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		v[x]=0;
		int cnt=g[x].size();
		for(int i=0;i<cnt;i++)
		if (d[x]+g[x][i].second<d[g[x][i].first])
		{
			d[g[x][i].first]=d[x]+g[x][i].second;
			if (!v[g[x][i].first])
			{
				v[g[x][i].first]=1;
				q.push(g[x][i].first);
			}
		}
	}
	if (d[ed]==2047483647)cout<<-1<<endl; else cout<<d[ed]<<endl;
}
int main()
{
	init();
	spfa();
	return 0;
}