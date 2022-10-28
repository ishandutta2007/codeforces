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
#define INF 2000000000000000000
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
template<typename T, typename U> static inline void setmin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void setmax(T &x, U y){ if(x<y) x=y; }
int _runtimeTerror_()
{
	ll n,T;
	cin>>n>>T;
	long double ans=0;
	vector<pair<ll,ll>> pos,neg,op;
	ll a[n],t[n],i;
	for(i=0;i<n;++i)
		cin>>a[i];
	ll val1=0,val2=0,sum1=0,sum2=0;
	for(i=0;i<n;++i)
	{
		cin>>t[i];
		if(t[i]==T)
			ans+=a[i];
		else if(t[i]<T)
		{
			pos.pb({T-t[i],a[i]});
			val1+=(T-t[i])*a[i];
			sum1+=a[i];
		}
		else
		{ 
			neg.pb({t[i]-T,a[i]});
			val2+=(t[i]-T)*a[i];
			sum2+=a[i];
		}
	}
	long double ob;
	if(val1<=val2)
	{
		ob=val1;
		ans+=sum1;
		op=neg;
	}
	else
	{
		ans+=sum2;
		ob=val2;
		op=pos;
	}
	sort(all(op));
	for(auto j:op)
	{
		ans+=min(ob/j.F,(long double)j.S);
		ob-=min(ob/j.F,(long double)j.S)*j.F;
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
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