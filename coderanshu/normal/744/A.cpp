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
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	return (!e)?1:power(b*b%m,e/2,m)*(e&1?b:1)%m;
}
ll power( ll b, ll e)
{
	return (!e)?1:power(b*b,e/2)*(e&1?b:1);
}
vector<ll> v[1005];
bool vis[1005];
ll e,vtc;
void dfs(ll s)
{
	vis[s]=true;
	++vtc;
	e+=sz(v[s]);
	for(auto j:v[s])
	{
		if(!vis[j])
			dfs(j);
	}
} 
int _runtimeTerror_()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll c[k],i,ans=0;
	for(i=0;i<k;++i)cin>>c[i];
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	ll vert=-1;
	for(i=0;i<k;++i)
	{
		e=0,vtc=0;
		dfs(c[i]);
		e/=2;
		ans+=(vtc)*(vtc-1)/2-e;
		vert=max(vert,vtc);
	}
	vtc=0,e=0;
	for(i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			++vtc;
			e+=sz(v[i]);
		}
	}
	e/=2;
	ans+=vtc*(vtc-1)/2-e+vert*vtc;
	cout<<ans<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}