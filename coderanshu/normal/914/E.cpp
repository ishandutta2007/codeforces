
#pragma GCC optimize("o3")
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
ll n;
const int N=200005,NN=20;
set<ll> v[N];
ll cnt[1<<NN];
ll ctree[N],sub[N];
ll cntoftr,ans[N];
char val[N];
void dfs1(ll s,ll p)
{
	++cntoftr;
	sub[s]=1;
	for(auto j:v[s])
		if(j!=p)
		{
			dfs1(j,s);
			sub[s]+=sub[j];
		}
}
ll dfs2(ll s,ll p)
{
	for(auto j:v[s])
		if(j!=p && sub[j]>cntoftr/2)
			return dfs2(j,s);
	return s;
}
vector<ll> ff,rm;
ll c;
ll dfs3(ll s,ll p,ll mask,bool fo)
{
	ff.pb(mask);
	rm.pb(mask);
	ll legend=(1<<(val[c]-'a'));
	ll msk=mask ^ legend;
	ll valu=0;
	if(popcount(msk)<=1 && fo)
		++valu;
	valu+=cnt[msk];
	for(int i=0;i<20;++i)
		valu+=cnt[msk^(1<<i)];
	for(auto j:v[s])
		if(j!=p)
			valu+=dfs3(j,s,mask^(1<<(val[j]-'a')),fo);
	ans[s]+=valu;
	return valu;
}
// ek baar seedha iterate kar lo aur ek baar ulta iterate kar lo and its over
void decompose(ll s,ll p)
{
	cntoftr=0;
	dfs1(s,s);
	ll centroid=dfs2(s,s);
	c=centroid;
	++ans[centroid];
	for(auto j:v[centroid])
	{
		v[j].erase(centroid);
		ll x=dfs3(j,-1,(1<<(val[j]-'a')),true);
		ans[centroid]+=x;
		for(auto k:ff)
			cnt[k]++;
		ff.clear();
	}
	for(auto k:rm)
		cnt[k]--;
	rm.clear();
	for(auto j=v[centroid].rbegin();j!=v[centroid].rend();++j)
	{
		ll x=dfs3(*j,-1,(1<<(val[*j]-'a')),false);
		for(auto k:ff)
			cnt[k]++;
		ff.clear();
	}
	for(auto k:rm)
		cnt[k]--;
	rm.clear();
	for(ll j:v[centroid])
	{
		decompose(j,centroid);
	}
	v[centroid].clear();
}
int _runtimeTerror_()
{
	cin>>n;
	for(int i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].insert(y);v[y].insert(x);
	}
	for(int i=1;i<=n;++i)
		cin>>val[i];
	decompose(1,-1);
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
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