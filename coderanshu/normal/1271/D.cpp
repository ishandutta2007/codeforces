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
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)

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

const int N=5005;
ll a[N],b[N],c[N],dp[N][N],val[N];
vector<ll> v[N];
ll n,m,k;
ll getans(ll pos,ll rem)
{
	if(pos==n)
		return 0;
	if(rem<a[pos])
		return -INF;
	if(dp[pos][rem]!=-1)
		return dp[pos][rem];
	rem+=b[pos];
	ll sum=0,cnt=0;
	ll ans=-INF;
	amax(ans,getans(pos+1,rem));
	for(auto j:v[pos+1])
	{
		sum+=j;
		++cnt;
		if(cnt>rem)
			break;
		amax(ans,getans(pos+1,rem-cnt)+sum);
	}
	return dp[pos][rem-b[pos]]=ans;
}
int _runtimeTerror_()
{
	mem1(dp);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;++i)
		val[i]=i;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		amax(val[y],x);
	}
	for(int i=1;i<=n;++i)
	{
		v[val[i]].pb(c[i-1]);
	}
	for(int i=1;i<=n;++i)
	{
		sort(all(v[i]),greater<ll>());
	}
	ll ans=getans(0,k);
	cout<<(ans>=0?ans:-1);
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