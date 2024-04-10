//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a,b,c,q,A[100005],B[100005],FA[100005],fa[100005],g[50],dis[50][100005],cnt,ans[100005],DIS[100005];
vector<pair<int,int> > to[100005],ask[100005];
bool in[100005];
queue<int> dl;
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
void dfs(int now)
{
	for(int i=0;i<(int)to[now].size();++i)
	{
		if(FA[to[now][i].second])
		{
			if(FA[now]!=to[now][i].second)
			{
				g[++cnt]=now;
			}
			continue;
		}
		FA[to[now][i].second]=now;
		DIS[to[now][i].second]=DIS[now]+to[now][i].first;
		dfs(to[now][i].second);
	}
}
void spfa(int now)
{
	fill(dis[now]+1,dis[now]+1+n,INF);
	dis[now][g[now]]=0;
	in[g[now]]=true;
	dl.push(g[now]);
	while(!dl.empty())
	{
		int u=dl.front();
		in[u]=false;
		dl.pop();
		for(int i=0;i<(int)to[u].size();++i)
		{
			if(dis[now][to[u][i].second]>dis[now][u]+to[u][i].first)
			{
				dis[now][to[u][i].second]=dis[now][u]+to[u][i].first;
				if(!in[to[u][i].second])
				{
					in[to[u][i].second]=true;
					dl.push(to[u][i].second);
				}
			}
		}
	}
}
void Tarjan(int now)
{
	in[now]=true;
	for(int i=0;i<(int)ask[now].size();++i)
	{
		if(in[ask[now][i].second])
		{
			ans[ask[now][i].first]=DIS[ask[now][i].second]+DIS[now]-DIS[find(ask[now][i].second)]*2;
		}
	}
	for(int i=0;i<(int)to[now].size();++i)
	{
		if(FA[to[now][i].second]==now)
		{
			Tarjan(to[now][i].second);
			fa[find(to[now][i].second)]=find(now);
		}
	}
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
    	cin>>a>>b>>c;
    	to[a].push_back(make_pair(c,b));
    	to[b].push_back(make_pair(c,a));
	}
	FA[1]=-1;
	dfs(1);
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>A[i]>>B[i];
		ask[A[i]].push_back(make_pair(i,B[i]));
		ask[B[i]].push_back(make_pair(i,A[i]));
	}
	for(int i=1;i<=cnt;++i)
	{
		spfa(i);
	}
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
	}
	Tarjan(1);
	for(int i=1;i<=q;++i)
	{
		for(int j=1;j<=cnt;++j)
		{
			ans[i]=min(ans[i],dis[j][A[i]]+dis[j][B[i]]);
		}
		cout<<ans[i]<<endl;
	}
    return 0;
}