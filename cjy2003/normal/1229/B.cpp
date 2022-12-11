#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1000000007;
long long gcd(long long a,long long b)
{
	if(!b)return a;
	if(!a)return b;
	return gcd(b,a%b);
}
int n,dep[100010],ans;
long long w[100010];
vector<int>E[100010];
vector<pair<int,long long> >p[100010];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	p[v].push_back(make_pair(dep[v],w[v]));
	long long res=w[v],now;
	int last=dep[v];
	for(auto x:p[fa])
	{
		now=gcd(res,x.second);
		if(now!=res)
		{
			ans=(ans+res*(last-x.first))%mod;
			res=now;
			p[v].push_back(make_pair(x.first,res));
			last=x.first;
		}
	}
//	printf("%d:\n",v);
//	for(auto x:p[v])printf("%d %lld\n",x.first,x.second);
//	printf("\n");
	ans=(ans+res*last)%mod;
//	printf("%lld\n",ans);
	for(auto u:E[v])if(u!=fa)dfs(u,v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&w[i]);
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}