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
#define INF 2000000000000000000
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
const int N=100005;
ll h[N],p[N];
int _runtimeTerror_()
{
	ll n,a,r,m;
	cin>>n>>a>>r>>m;
	ll sum=0;
	for(int i=0;i<n;++i)
	{
		cin>>h[i];
		sum+=h[i];
	}
	sort(h,h+n);
	p[0]=h[0];
	for(int i=1;i<n;++i)
		p[i]=h[i]+p[i-1];
	ll val=min(m,a+r);
	ll avg=sum/n;
	ll ans=INF;
	for(int i=0;i<n-1;++i)
	{
		ll lo=h[i],hi=h[i+1];
		ll x=p[i],y=p[n-1]-p[i];
		ll ff=n-i-1,gg=i+1;
		ll xx=min(hi,avg+1);ll yy=max(lo,avg);
		amax(xx,lo);amin(yy,hi);
		ll va;
		va=xx;		
		ll v=min(va*gg-x,y-va*ff);
		amax(v,0);
		v*=val;
		ll mm=va*gg-x,km=y-va*ff;
		if(mm>km)
			v+=(mm-km)*a;
		else v+=(km-mm)*r;
		amin(ans,v);
		va=yy;
		v=min(va*gg-x,y-va*ff);
		amax(v,0);
		v*=val;
		mm=va*gg-x,km=y-va*ff;
		if(mm>km)
			v+=(mm-km)*a;
		else v+=(km-mm)*r;
		amin(ans,v);
		va=lo;
		v=min(va*gg-x,y-va*ff);
		amax(v,0);
		v*=val;
		mm=va*gg-x,km=y-va*ff;
		if(mm>km)
			v+=(mm-km)*a;
		else v+=(km-mm)*r;
		amin(ans,v);
		va=hi;
		v=min(va*gg-x,y-va*ff);
		amax(v,0);
		v*=val;
		mm=va*gg-x,km=y-va*ff;
		if(mm>km)
			v+=(mm-km)*a;
		else v+=(km-mm)*r;
		amin(ans,v);
	}
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
	cerr<<"\n"<<_time_;
	return 0;
}