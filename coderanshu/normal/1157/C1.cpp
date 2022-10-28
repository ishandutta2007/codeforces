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
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
	ll a[n],i;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
	}
	ll fp=0,lp=n-1;
	ll ans=0;
	string ff="";
	ll prev=-1;
	while(fp<=lp)
	{
		if(a[fp]<a[lp])
		{
			if(a[fp]>prev)
			{
				prev=a[fp];
				++ans;++fp;
				ff+="L";
			}
			else if(a[lp]>prev)
			{
				prev=a[lp];
				++ans,--lp;
				ff+="R";
			}
			else break;
		}
		else if(a[fp]>a[lp])
		{
			if(a[lp]>prev)
			{
				prev=a[lp];
				++ans;--lp;
				ff+="R";
			}
			else if(a[fp]>prev)
			{
				prev=a[fp];
				++ans,++fp;
				ff+="L";
			}
			else break;
		}
		else if(a[lp]==a[fp])
		{
			if(a[lp]<=prev)
				break;
			vector<ll> v;
			v.pb(a[fp]);
			char c='L';
			for(i=fp+1;i<=lp;++i)
			{
				if(a[i]>v.back())
					v.pb(a[i]);
				else break;
			}
			ll val=sz(v);
			v.clear();
			v.pb(a[lp]);
			for(i=lp-1;i>=fp;--i)
			{
				if(a[i]>v.back())
					v.pb(a[i]);
				else break;
			}
			if(sz(v)>val)
				c='R';
			val=max(val,sz(v));
			ans+=val;
			while(val--)
				ff.pb(c);
			break;
		}
	}
	cout<<ans<<endl<<ff;
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