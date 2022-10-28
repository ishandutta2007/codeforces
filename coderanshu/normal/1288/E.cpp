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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;
const int N=300005;
ll n,m;
ll ans[N][2],a[N];
template<typename T>
class fenwick {
public:
	T a[N]{},bit[N]{};
	void build(ll st,ll en)
	{
		for(ll i=st;i<=en;++i)
		{
			for(ll j=i;j<=en;j+=j&-j)
				bit[j]+=a[i];
		}
	}
	void update(ll st,ll en,ll in,T val)
	{
		for(ll j=in;j<=en;j+=j&-j)
			bit[j]+=val;
	}
	T get(ll r)
	{
		T x{};
		while(r>0)
		{
			x+=bit[r];
			r-=r&-r;
		}
		return x;
	}
	T query(ll l,ll r)
	{
		return get(r)-get(l-1);
	}
};
vector<ll> v[300005];
int _runtimeTerror_()
{
	ll i;
	cin>>n>>m;
	fenwick<ll> fenw;
	//fenw.build(1,m);
	int lst[n+3];
	for(i=1;i<=n;++i)
		ans[i][0]=ans[i][1]=i;
	ordered_set<ll> s;
	mem1(lst);
	bool vis[n+2];
	memf(vis);
	for(i=1;i<=m;++i)
	{
		cin>>a[i];
		if(!vis[a[i]])
		{
			s.insert(a[i]);
			vis[a[i]]=true;
			amax(ans[a[i]][1],sz(s)-s.order_of_key(a[i])-1+a[i]);
		}
		v[a[i]].pb(i);
	}
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			s.insert(i);
			amax(ans[i][1],sz(s)-s.order_of_key(i)-1+i);
		}
	s.clear();
	vector<pair<int,int>> query[m+2]; 
	for(i=1;i<=n;++i)
	{
		if(v[i].empty()) continue;
		else
		{
			ans[i][0]=1;
			v[i].pb(m+1);
			for(ll j=1;j<sz(v[i]);++j)
				query[v[i][j]-1].pb({v[i][j-1]+1,i});
			v[i].clear();
		}
	}
	for(i=1;i<=m;++i)
	{
		if(lst[a[i]]!=-1)
			fenw.update(1,m,lst[a[i]],-1);
		lst[a[i]]=i;
		fenw.update(1,m,lst[a[i]],1);
		for(auto j:query[i])
		{
			amax(ans[j.S][1],fenw.query(j.F,i)+1);
		}
	}
	for(i=1;i<=n;++i)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
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