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

const int N=500002;
vector<pair<ll,ll>> v[N];
bitset<N> vis;
ll dp[N][2],k;
void dfs(ll s)
{
	vis[s]=1;
	ll ans=0;
	vector<ll> operate;
	for(auto j:v[s])
	{
		if(!vis[j.F])
		{
			dfs(j.F);
			operate.pb(dp[j.F][0]+j.S-dp[j.F][1]);
			ans+=dp[j.F][1];
		}
	}
	dp[s][0]=dp[s][1]=ans;
	if(operate.empty())
		return ;
	ll tt,val=min(k,sz(operate));
	sort(all(operate));
	reverse(all(operate));
	for(tt=0;tt<val;++tt)
	{
		if(operate[tt]>=0)
			dp[s][1]+=operate[tt];
		else break;
	}
	val=min(sz(operate),k-1);
	for(tt=0;tt<val;++tt)
	{
		if(operate[tt]>=0)
			dp[s][0]+=operate[tt];
		else break;
	}
}
int _runtimeTerror_()
{
	ll n;
	cin>>n>>k;
	for(ll i=1;i<=n;++i)
	{
		vis[i]=0;
		v[i].clear();
	}
	for(ll i=0;i<n-1;++i)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	dfs(1);
	cout<<dp[1][1]<<endl;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}