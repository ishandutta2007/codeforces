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

int _runtimeTerror_()
{
	ll n,i;string s;
	cin>>n>>s;
	vector<pair<ll,ll>> v;
	for(i=0;i<n;++i)
	{
		if(s[i]=='G')
		{
			ll j=i;
			while(i<n && s[i]=='G')++i;
			v.pb({j,i-1});
		}
	}
	if(sz(v)==0)
	{
		cout<<0;return 0;
	}
	ll kk=sz(v);
	if(kk==1)
	{
		cout<<v[0].S-v[0].F+1;return 0;
	}
	ll ans=0;
	for(i=0;i<kk-1;++i)
	{
		ans=max(ans,v[i].S-v[i].F+1);
		if(v[i+1].F-v[i].S==2)
		{
			if(sz(v)>2)
			{
				ans=max(ans,v[i+1].S-v[i].F+1);
			}
			else
				ans=max(ans,v[i+1].S-v[i].F);
		}
		if(sz(v)>1)
			ans=max(ans,v[i].S-v[i].F+2);
	}
	ans=max(ans,v[kk-1].S-v[kk-1].F+2);
	cout<<ans;
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