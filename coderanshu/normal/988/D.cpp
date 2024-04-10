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
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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
	ll n;
	cin>>n;
	vector<ll> ans;
	ll a[n],i;
	set<ll> s;
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	for(i=0;i<n;++i)
	{
		ll k=1;
		if(sz(ans)==3)break;
		for(;k<=2e9;k*=2)
		{
			if(sz(ans)==3)break;
			if(s.count(a[i]+k) && s.count(a[i]-k))
			{
				cout<<3<<endl;
				cout<<a[i]-k<<" "<<a[i]<<" "<<a[i]+k;
				return 0;
			}
			if(s.count(a[i]+k))
			{
				if(sz(ans)==2)continue;
				ans.pb(a[i]);ans.pb(a[i]+k);
			}
			if(s.count(a[i]-k))
			{
				if(sz(ans)==2)continue;
				ans.pb(a[i]);ans.pb(a[i]-k);
			}
		}
	}
	if(ans.empty())
		ans.pb(a[0]);
	cout<<sz(ans)<<endl;
	for(auto j:ans)
		cout<<j<<" ";
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
	cerr<<"\n"<<_time_;
	return 0;
}