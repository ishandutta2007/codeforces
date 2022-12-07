#define LL long long
#define PII pair<int,int>
#include <bits/stdc++.h>

using namespace std;

const int N=1<<19;

map<LL,int> mp;
LL x[N],dis[N];
vector<PII> g[N],f[N];
int T,n,cnt,tot,u,v,w,bit[N],res[N];

void dfs(int u,int fa)
{
	f[cnt+1].push_back(PII(u,-1));
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].first,w=g[u][i].second;
		if(v!=fa)
		{
			dis[v]=dis[u]+w;
			dfs(v,u);
		}
	}
	f[++cnt].push_back(PII(u,1));
}

void Init()
{
	cnt=0,tot=0,mp.clear();
	memset(res,0,sizeof(res));

	for(int i=0;i<=n;i++)
		g[i].clear(),f[i].clear();
}

void update(int x)
{
	for(;x<N;x+=x&-x)
		bit[x]++;
}

int query(int x)
{
	int res=0;
	for(;x;x-=x&-x)
		res+=bit[x];
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	for(T=1;T--;)
	{
		cin>>n,Init();
		for(int i=1;i<=n;i++)
			scanf("%lld",x+i);
	
		for(int i=1;i<n;i++)
		{
			u = i + 1;
			scanf("%d%d",&v,&w);
			g[u].push_back(PII(v,w));
			g[v].push_back(PII(u,w));
		}
		dfs(1,1);

		for(int i=1;i<=n;i++)
			mp[dis[i]-x[i]]=0;
		for(auto it=mp.begin();it!=mp.end();it++)
			it->second=++tot;

		for(int i=1;i<=n;i++)
			for(int j=0;j<f[i].size();j++)
			{
				int u=f[i][j].first,p=f[i][j].second;
				auto it=mp.lower_bound(dis[u]+1); it--;
				res[u]+=query(it->second)*p;

				if(p==1) update(mp[dis[u]-x[u]]);
			}
		
		for(int i=1;i<=n;i++)
			printf("%d%c",res[i]," \n"[i==n]);
	}
}