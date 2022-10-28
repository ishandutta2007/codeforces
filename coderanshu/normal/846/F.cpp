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
#define popcount(x) __builtin_popcountll(x)
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

const int N=1000005;
ll a[N];
vector<ll> v[N];
int _runtimeTerror_()
{
	ll n,i,j;
	cin>>n;
	for(i=1;i<=1000000;++i)
		v[i].pb(-1);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
		v[a[i]].pb(i);
	}
	for(i=1;i<=1000000;++i)
		v[i].pb(n);
	ll ans=0;
	for(i=1;i<=1000000;++i)
	{
		ll val=n*n;
		ll x=sz(v[i]);
		for(j=1;j<x;++j)
			val-=(v[i][j]-v[i][j-1]-1)*(v[i][j]-v[i][j-1]-1);
		ans+=val;
	}
	cout<<fixed<<setprecision(10);
	cout<<(long double)ans/(n*n);
	return 0;
}
// reverse analogy ki ye number kisme as a distinct aa raha hai
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