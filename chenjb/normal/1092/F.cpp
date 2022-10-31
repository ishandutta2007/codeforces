#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int n;
vector<int> g[210000];
int dep[210000];
long long f[210000],sum[210000],w[210000];
long long ff,tsum,ans=-2147483647;
void dfs(int x,int pre)
{
	sum[x]=w[x];
	for(auto p:g[x])
		if (p!=pre)
		{
			dep[p]=dep[x]+1;
			dfs(p,x);
			sum[x]+=sum[p];
		}
}
void fuck(int x,int pre)
{
	ans=max(ans,f[x]);
	for(auto p:g[x])
		if (p!=pre)
		{
			f[p]=f[x]+tsum-2*sum[p];
			fuck(p,x);
		}
}
int main()
{
	cin>>n;
	tsum=0;
	rep(i,n){ scanf("%lld",&w[i]); tsum+=w[i]; g[i].clear();}
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	rep(i,n)f[1]+=1ll*w[i]*dep[i];
	fuck(1,0);
	cout<<ans<<endl;
}