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
const int N=100002;
vector<ll> v[N];
ll ans[N];
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;++i)
	{
		ll ss,rr;
		cin>>ss>>rr;
		v[ss].pb(rr);
	}
	for(ll i=1;i<=m;++i)
	{
		if(v[i].empty())continue;
		ll sum=0;
		sort(all(v[i]),greater<ll>());
		for(ll j=0;j<sz(v[i]);++j)
		{
			sum+=v[i][j];
			if(sum<0)break;
			ans[j+1]+=sum;
		}	
	}
	ll print=0;
	for(ll i=1;i<=n;++i)
	{
		print=max(print,ans[i]);
	}
	cout<<print<<endl;
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