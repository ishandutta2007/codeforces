#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=524288;
const int M=1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
struct edge{
	int v,w;
};
vector<edge> g[N];
int n,m,Q,u,v,w,i,vis[N],t,au[N],at[N],j,tmp[N];
long long d[N];
vector<int> p[N];
struct str{
	long long s;
	int x;
};
bool operator <(str a,str b)
{
	return a.s>b.s;
}
priority_queue<str> q;
void Dij()
{
	q.push((str){0,1});
	memset(vis,0,sizeof(vis));
	for(i=2;i<=n;++i)
		d[i]=10000000000000000ll;
	while(!q.empty())
	{
		str t=q.top();
		q.pop();
		if(vis[t.x]==1)
			continue;
		vis[t.x]=1;
		for(auto j:g[t.x])
			if(d[j.v]>d[t.x]+j.w)
			{
				d[j.v]=d[t.x]+j.w;
				q.push((str){d[j.v],j.v});
			}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&Q);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back((edge){v,w});
		au[i]=u;
		at[i]=g[u].size()-1;
	}
	Dij();
	while(Q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d",&u);
			if(d[u]>=10000000000000000ll)
				puts("-1");
			else
				printf("%lld\n",d[u]);
		}
		else
		{
			scanf("%d",&m);
			for(i=1;i<=m;++i)
			{
				scanf("%d",&u);
				++g[au[u]][at[u]].w;
			}
			for(i=0;i<=m;++i)
				p[i].clear();
			p[0].push_back(1);
			tmp[1]=0;
			for(i=2;i<=n;++i)
				tmp[i]=10000000;
			memset(vis,0,sizeof(vis));
			for(i=0;i<=m;++i)
				for(j=0;j<p[i].size();++j)
					if(vis[p[i][j]]==0)
					{
						vis[p[i][j]]=1;
						for(auto k:g[p[i][j]])
							if(k.w+i-d[k.v]+d[p[i][j]]<=m&&tmp[k.v]>k.w+i-d[k.v]+d[p[i][j]])
							{
								tmp[k.v]=k.w+i-d[k.v]+d[p[i][j]];
								p[tmp[k.v]].push_back(k.v);
							}
					}
			for(i=1;i<=n;++i)
				d[i]+=tmp[i];
		}
	}
}