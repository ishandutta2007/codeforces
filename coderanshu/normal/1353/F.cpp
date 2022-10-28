#include<bits/stdc++.h>
using namespace std ;

#define M 				1000000007
#define MM 				998244353 
#define ll 				long long 
#define pb 				push_back
#define mem0(a) 		memset(a,0,sizeof(a))
#define mem1(a) 		memset(a,-1,sizeof(a))
#define memf(a) 		memset(a,false,sizeof(a))
#define all(v) 			v.begin(),v.end()
#define sz(a) 			(ll)a.size()
#define F 				first
#define S 				second
#define INF 			2000000000000000000
#define endl 			"\n"
#define _time_ 			1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) 	__builtin_popcountll(x)
#define pll 			pair<ll,ll> 
#define ld 				long double
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

const int N=105;
ll a[N][N];
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			cin>>a[i][j];
			a[i][j]-=i+j;
		}
	vector<pair<ll,pll>> v;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			v.pb({a[i][j],{i,j}});
	sort(all(v));
	ll ans=INF;
	for(auto k:v)
	{
		ll dp[n+2][m+2],dp2[n+2][m+2];
		dp[0][0]=a[0][0];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(i==0 && j==0)continue;
				dp[i][j]=INF;
				if(i>0) amin(dp[i][j],dp[i-1][j]+a[i][j]);
				if(j>0)amin(dp[i][j],dp[i][j-1]+a[i][j]);
			}
		dp2[n-1][m-1]=a[n-1][m-1];
		for(int i=n-1;i>=0;--i)
			for(int j=m-1;j>=0;--j)
			{
				if(i==n-1 && j==m-1)continue;
				dp2[i][j]=INF;
				if(i<n-1)amin(dp2[i][j],dp2[i+1][j]+a[i][j]);
				if(j<m-1)amin(dp2[i][j],dp2[i][j+1]+a[i][j]);
			}
		ll x=dp[k.S.F][k.S.S];
		ll y=dp2[k.S.F][k.S.S];
		amin(ans,x+y-a[k.S.F][k.S.S]-k.F*(n+m-1));
		a[k.S.F][k.S.S]=INF+100;
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
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}