#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
ll val[200005],depth[200005],sum=0,ans=0;
vector<ll> v[200005];
pair<ll,ll> p[200005];
bool vis[200005];
void dfs(ll s)
{
	vis[s]=true;
	p[s].S=val[s];
	p[s].F=depth[s]*val[s];
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			depth[j]=depth[s]+1;
			dfs(j);
			p[s].F+=p[j].F;
			p[s].S+=p[j].S;
		}
	}
}
void dfs2(ll s)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			p[j].F=p[s].F+sum-2*p[j].S;
			ans=max(ans,p[j].F);
			dfs2(j);
		}
	}
}
int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>val[i];
		sum+=val[i];
	}
	for(i=0;i<n-1;++i)
	{
		ll x,y;cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	depth[1]=0;
	dfs(1);
	//for(i=1;i<=n;++i)cout<<p[i].S<<endl;
	ans=p[1].F;
	memf(vis);
	dfs2(1);
	cout<<ans<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}