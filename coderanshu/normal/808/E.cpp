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

const int N=100005;
struct node{
	ll val=0,tw=0,ow=0;
};
node dp[N*3];
vector<ll> v[4];
ll n,m;
int _runtimeTerror_()
{
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;++i)
	{
		ll num,cost;
		cin>>num>>cost;
		v[num].pb(cost);
	}
	for(i=1;i<=3;++i)
		sort(all(v[i]),greater<ll>());
	dp[0].val=0;dp[0].ow=dp[0].tw=-1;
	for(i=1;i<=300000;++i)
		dp[i].val=dp[i].ow=dp[i].tw=0;
	for(i=0;i<=300000;++i)
	{
		if(dp[i].ow<sz(v[1])-1)
		{
			if(dp[i].val+v[1][dp[i].ow+1]>dp[i+1].val)
			{
				dp[i+1].val=dp[i].val+v[1][dp[i].ow+1],dp[i+1].ow=dp[i].ow+1,dp[i+1].tw=dp[i].tw;
			}
		}
		if(dp[i].tw<sz(v[2])-1)
		{
			if(dp[i].val+v[2][dp[i].tw+1]>dp[i+2].val)
			{
				dp[i+2].val=dp[i].val+v[2][dp[i].tw+1],dp[i+2].tw=dp[i].tw+1,dp[i+2].ow=dp[i].ow;
			}	
		}
	}
	for(i=1;i<=300000;++i)
		amax(dp[i].val,dp[i-1].val);
	ll ans=-INF,sum=0;
	amax(ans,dp[m].val);
	for(auto j=0;j<sz(v[3]);++j)
	{
		sum+=v[3][j];
		if(m>=(j+1)*3)
			amax(ans,dp[m-(j+1)*3].val+sum);
		else break;
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