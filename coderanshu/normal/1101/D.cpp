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
#define pll pair<ll,ll> 

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
#define runSieve
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=300000)
{
	int k=sqrt(n);
	memf(notPrime);
	notPrime[1]=true;
	for(int i=2;i<=k;++i)
	{
		if(!notPrime[i])
		{
			for(int k=i*i;k<=n;k+=i)
			{
				notPrime[k]=true;
				divPrime[k]=i;
			}
		}
	}
}
const int N=200005;
map<int,int> dp[N];
vector<int> v[N];
int a[N],n,dep[N];
int ans=0;
void dfs(int s=1,int p=-1)
{
	int k=a[s];
	while(k!=1 && notPrime[k])
	{
		int z=divPrime[k];
		dp[s][z]=dep[s];
		while(k%z==0)k/=z;
	}
	if(k!=1)
		dp[s][k]=dep[s];
	map<int,vector<int>> val;
	for(auto j:v[s])
	{
		if(j!=p)
		{
			dep[j]=dep[s]+1;
			dfs(j,s);
			for(auto &k:dp[s])
			{
				if(!dp[j].count(k.F))continue;
				amax(k.S,dp[j][k.F]);
				val[k.F].pb(dp[j][k.F]);
			}
		}
	}
	for(auto &j:val)
	{
		if(sz(j.S)<2)continue;
		sort(all(j.S),greater<int>());
		amax(ans,j.S[0]+j.S[1]-2*dep[s]+1);
	}
	val.clear();
	for(auto j:dp[s])
		amax(ans,j.S-dep[s]+1);
}
int _runtimeTerror_()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs();
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
// gcd always decreases bc