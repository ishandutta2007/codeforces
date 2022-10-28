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
map<string,ll> st[N];
vector<ll> v[N],vec[N];
vector<pair<ll,ll>> query[N];
ll n,dep[N],sub[N],ans[N];
string s[N];
void pre(ll s,ll p)
{
	for(auto j:v[s])
		if(j!=p)
		{
			dep[j]=dep[s]+1;
			pre(j,s);
			sub[s]+=sub[j];
		}
	++sub[s];
}
inline void add(ll v)
{
	st[dep[v]][s[v]]++;
}
inline void del(ll v)
{
	if(st[dep[v]][s[v]]==1)
		st[dep[v]].erase(s[v]);
	else --st[dep[v]][s[v]];
}
void dfs(ll s,ll p,ll bors)
{
	ll bc=-1,mx=-1;
	for(auto j:v[s])
		if(j!=p)
			if(sub[j]>mx)
				mx=sub[j],bc=j;

	for(auto j:v[s])
		if(j!=p && j!=bc)
			dfs(j,s,0);
	if(bc!=-1)
	{
		dfs(bc,s,1);
		swap(vec[s],vec[bc]);
	}
	vec[s].pb(s);
	add(s);
	for(auto j:v[s])
		if(j!=p && j!=bc)
			for(auto k:vec[j])
				add(k),vec[s].pb(k);
	for(auto j:query[s])
		ans[j.S]=sz(st[min(n+2,dep[s]+j.F)]);
	if(!bors)
		for(auto j:vec[s])
			del(j);
}
int _runtimeTerror_()
{
	ll m;
	cin>>n;
	ll i;
	vector<ll> root;
	for(i=1;i<=n;++i)
	{
		cin>>s[i];
		ll x;
		cin>>x;
		if(x)
			v[x].pb(i),v[i].pb(x);
		else root.pb(i);
	}
	cin>>m;
	for(i=1;i<=m;++i)
	{
		ll v,k;
		cin>>v>>k;
		query[v].pb({k,i});
	}
	for(auto j:root)
	{
		pre(j,-1);
		dfs(j,-1,0);
	}
	for(i=1;i<=m;++i)
		cout<<ans[i]<<endl;
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