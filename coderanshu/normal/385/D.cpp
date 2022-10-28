#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)	memset(a,0,sizeof(a))
#define mem1(a)	memset(a,-1,sizeof(a))
#define memf(a)	memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const long double PI = acos(-1);

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

const int N=20;
ld dp[1<<N];
struct node{
	ll x,y,a;
};
node a[N+2];
ld getans(ld prev,node a)
{
	complex<ld> c(prev-a.x,-a.y);
	ld angle = PI/180.0*a.a;
	complex<ld> d(cos(angle),sin(angle));
	c*=d;
	if(c.imag()>=0)
		return (ld)INF;
	c/=-c.imag();
	c*=a.y;
	return c.real()+a.x;
}
int _runtimeTerror_()
{
	ll n,l,r;
	cin>>n>>l>>r;
	for(int i=0;i<n;++i)
		cin>>a[i].x>>a[i].y>>a[i].a;
	int x=(1<<n);
	for(int i=0;i<x;++i)
		dp[i]=l;
	for(int mask=0;mask<x-1;++mask)
	{
		for(int j=0;j<n;++j)
		{
			if(mask&(1<<j))continue;
			amax(dp[mask|(1<<j)],getans(dp[mask],a[j]));
		}
	}
	amin(dp[x-1],r);
	cout<<fixed<<setprecision(10)<<dp[x-1]-l<<endl;
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