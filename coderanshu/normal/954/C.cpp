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
	ll n;
	cin>>n;
	ll a[n],i;
	ll r=-1,c=-1;
	for(i=0;i<n;++i)
		cin>>a[i];
	ll prev=a[0];
	if(n==1)
	{
		cout<<"YES\n";
		cout<<a[0]<<" "<<1;return 0;
	}
	ll val=a[0];
	vector<pair<ll,ll>> check;
	for(i=1;i<n;++i)
	{
			setmax(val,a[i]);
			ll k=abs(a[i]-a[i-1]);
			if(k==0)
			{
				cout<<"NO\n";return 0;
			}
			if(k==1)
			{
				check.pb({a[i],a[i-1]});continue;
			}
			if(c==-1)
				c=k;
			else if(c!=k)
			{
				cout<<"NO\n";return 0;
			}
	}
	if(c==-1)
		c=val;
	for(auto j:check)
	{
		if(j.F/c+(j.F%c!=0) != j.S/c + (j.S%c!=0))
		{
			cout<<"NO\n";return 0;
		}
	}
	if(c<=1000000000)
	{
		r=val/c+(val%c!=0);
		if(r<=1000000000)
		{
			cout<<"YES\n"<<r<<" "<<c;
		}
		else cout<<"NO\n";
	}
	else cout<<"NO\n";
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