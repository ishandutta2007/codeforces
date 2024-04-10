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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

ll n,k;
const int N=1002;
ll dp[N][2][2][2*N];
ll solve(ll pos,ll comp,ll p1,ll p2)
{
	if(pos==n)
		return (comp==k);
	if(dp[pos][p1][p2][comp]!=-1)
		return dp[pos][p1][p2][comp];
	ll ans=0;
	if(p1==p2)
	{
		ans+=solve(pos+1,comp+1,p1^1,p2^1);
		ans+=solve(pos+1,comp+1,p1^1,p2);
		ans+=solve(pos+1,comp+1,p1,p2^1);
		ans+=solve(pos+1,comp,p1,p2);
	}
	else
	{
		ans+=solve(pos+1,comp,p1^1,p2);
		ans+=solve(pos+1,comp,p1,p2^1);
		ans+=solve(pos+1,comp+2,p1^1,p2^1);
		ans+=solve(pos+1,comp,p1,p2);
	}
	return dp[pos][p1][p2][comp]=ans%MM;
}
int _runtimeTerror_()
{
	mem1(dp);
	cin>>n>>k;
	ll print=0;
	print+=solve(1,2,0,1);
	print+=solve(1,2,1,0);
	print+=solve(1,1,0,0);
	print+=solve(1,1,1,1);
	cout<<print%MM;
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
// next answer depends upon only on number of compoonents achieved and current 2 colors of the column