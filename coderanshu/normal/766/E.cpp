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
set<ll> v[N];
ll n,a[N];
ll ans=0,ans2=0;
ll cnt[N][21],ff[21];
ll ctree[N],sub[N];
ll cntoftr;
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
void dfs3(ll s,ll p)
{
	sub[s]=1;
	for(int i=0;i<=20;++i)
		cnt[s][i]=0;
	for(auto j:v[s])
	{
		if(j!=p)
		{
			dfs3(j,s);
			sub[s]+=sub[j];
			for(int i=0;i<=20;++i)
				cnt[s][i]+=cnt[j][i];
		}
	}
	for(int i=0;i<=20;++i)
	{
		if(a[s]&(1LL<<i))
			cnt[s][i]=sub[s]-cnt[s][i];
		else continue;
	}
}
ll tot=0;
void dfs4(ll s,ll p,ll Xor)
{
	Xor^=a[s];
	for(int i=0;i<=20;++i)
	{
		if(Xor&(1LL<<i))
			ans+=(tot-ff[i])*power(2,i);
		else ans+=ff[i]*power(2,i);
	}
	for(auto j:v[s])
	{
		if(j!=p)
		{
			dfs4(j,s,Xor);
		}
	}
}
void decompose(ll s,ll p)
{
	cntoftr=0;
	dfs1(s,s);
	ll maaki=dfs2(s,s);
	if(p==-1)p=maaki;
	ctree[maaki]=p;
	dfs3(maaki,-1);
	for(int i=0;i<=20;++i)
		ans2+=cnt[maaki][i]*power(2,i);
	for(ll j:v[maaki])
	{
		for(int i=0;i<=20;++i)
		{
			if(a[maaki]&(1LL<<i))
				ff[i]=cnt[maaki][i]-(sub[j]-cnt[j][i]);
			else ff[i]=cnt[maaki][i]-cnt[j][i];
		}
		tot=cntoftr-sub[j];
		dfs4(j,maaki,0);
	}
	for(ll j:v[maaki])
	{
		v[j].erase(maaki);
		decompose(j,maaki);
	}
	v[maaki].clear();
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
		v[x].insert(y);v[y].insert(x);
	}
	decompose(1,-1);
	ll ans3=0;
	for(int i=1;i<=n;++i)
		ans3+=a[i];
	ans2-=ans3;
	ans-=ans2;
	ans/=2;
	ans+=ans2+ans3;
	cout<<ans<<endl;
	return 0;
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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