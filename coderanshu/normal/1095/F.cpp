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

const int  N=200005;
ll val[N],ed[N],p[N],r[N];
void in(ll n)
{
	for (ll i=1 ;i<=n ;++i)
		p[i]=i,r[i]=0;
}
ll parent(ll i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
ll ans=0;
void merge(ll x,ll y)
{
	x=parent(x);
	y=parent(y);
	if(r[x]>r[y])
		p[y]=x;
	else p[x]=y;
	if(r[x]==r[y])++r[y];
}
int _runtimeTerror_()
{
	ll n,m,i;
	cin>>n>>m;
	in(n);
	for(i=1;i<=n;++i)
		cin>>val[i],ed[i]=i;
	sort(ed+1,ed+n+1,[&](ll a,ll b){return val[a]<val[b];});
	vector<pair<ll,pair<ll,ll>>> edge;
	for(i=2;i<=n;++i)
		edge.pb({val[ed[i]]+val[ed[1]],{ed[i],ed[1]}});
	for(i=0;i<m;++i)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		edge.pb({w,{x,y}});
	}
	sort(all(edge));
	for(auto j:edge)
	{
		if(parent(j.S.F)!=parent(j.S.S))
		{
			ans+=j.F;
			merge(j.S.F,j.S.S);
		}
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