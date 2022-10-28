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
ll n,m,d;
const int N=100005;
vector<ll> v[N];
bool vis[N];
ll val[N],dep[N],dp[N],ans=0;
void dfs(ll s=1)
{
	vis[s]=true;
	dp[s]=-1;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			//dep[j]=dep[s]+1;
			dfs(j);
			if(dp[j]>=0)
				amax(dp[s],dp[j]+1);
		}
	}
	if(val[s]==1)
		amax(dp[s],0);
}
void dfs2(ll s=1,ll pans=(val[1]==1?0:-1))
{
	if(dp[s]<=d)
		++ans;
	vis[s]=true;
	vector<ll> pre,post;
	pre.pb(-1);post.pb(-1);
	for(auto j:v[s])
	{
		if(!vis[j])
			pre.pb(max(pre.back(),dp[j]));
	}
	reverse(all(v[s]));
	for(auto j:v[s])
	{
		if(!vis[j])
			post.pb(max(post.back(),dp[j]));
	}
	reverse(all(v[s]));
	ll cur=1;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			ll valu=max({(pre[cur-1]==-1?-1:pre[cur-1]+2),(post[sz(pre)-1-cur]==-1?-1:post[sz(pre)-1-cur]+2)});
			amax(valu,pans==-1?-1:pans+1);
			amax(dp[j],valu);
			if(val[j]==1)
				amax(valu,0LL);
			dfs2(j,valu);
			++cur;
		}
	}
}
int _runtimeTerror_()
{
	ll i;
	cin>>n>>m>>d;
	while(m--)
	{
		ll x;
		cin>>x;
		val[x]=1;
	}
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs();
	memf(vis);
	dfs2();
	//for(i=1;i<=6;++i)
	//	cout<<dp[i]<<endl;
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