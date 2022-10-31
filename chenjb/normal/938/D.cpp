#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
vector<pair<int,long long>> g[200010];
int n,m;
long long f[200010];
bool vis[200010];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		long long w;
		scanf("%d%d%lld",&x,&y,&w);
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	for(int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		f[i]=x;
		q.push({x,i});
	}
	for(;!q.empty();)
	{
		auto u=q.top();q.pop();
		if(vis[u.second])
		{
			continue;
		}
		vis[u.second]=1;
		for(auto i:g[u.second])
		{
			if(f[i.first]>u.first+i.second*2)
			{
				f[i.first]=u.first+i.second*2;
				q.push({f[i.first],i.first});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld%c",f[i],i==n?'\n':' ');
	}
	return 0;
}