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

const int N=150005;
vector<ll> v[N];
ll n,sub[N],dep[N],in[N],out[N],par[N];
ll cur=1;
void dfs(ll s=1,ll p=-1)
{
	in[s]=cur++;
	sub[s]=1;
	for(auto j:v[s])
		if(j!=p)
		{
			par[j]=s;
			dep[j]=dep[s]+1;
			dfs(j,s);
			sub[s]+=sub[j];
		}
	out[s]=cur-1;
}
template<typename T>
class fenwick {
public:
	T a[N],bit[N]{};
	void build(ll st,ll en)
	{
		for(ll i=st;i<=en;++i)
		{
			for(ll j=i;j<=en;j+=j&-j)
			{
				bit[j]+=a[i];
				bit[j]+=MM;
				bit[j]%=MM;
			}
		}
	}
	void update(ll st,ll en,ll in,T val)
	{
		for(ll j=in;j<=en;j+=j&-j)
		{
			bit[j]+=val;
			bit[j]+=MM;
			bit[j]%=MM;
		}
	}
	T get(ll r)
	{
		T x{};
		while(r>0)
		{
			x+=bit[r];
			x%=MM;
			r-=r&-r;
		}
		return x;
	}
	T query(ll l,ll r)
	{
		return get(r)-get(l-1);
	}
};
ll val[N],idx[N];
vector<ll> heavy;
const int SQ=400;
ll pre[SQ+2][N];
void pro(ll s,ll p,ll vv,ll id)
{
	pre[id][s]=vv;
	for(auto j:v[s])
		if(j!=p)
			pro(j,s,vv,id);
}
int _runtimeTerror_()
{
	ll q;
	cin>>n>>q;
	ll inv_n=power(n,MM-2,MM);
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	for(int i=1;i<=n;++i)
	{
		if(sz(v[i])>=SQ)
		{
			idx[i]=sz(heavy);
			heavy.pb(i);
		}
	}
	dfs();
	for(auto j:heavy)
	{
		for(auto k:v[j])
			if(k!=par[j])
				pro(k,j,sub[k],idx[j]);
	}
	fenwick<ll> fenw;
	fenw.build(1,n);
	for(int i=0;i<q;++i)
	{
		ll tt,vv,d;
		cin>>tt>>vv;
		if(tt==1)
		{
			cin>>d;
			val[vv]+=d;
			val[vv]%=MM;
			ll x=sub[vv];
			ll y=d*inv_n%MM*x%MM;
			ll yy=d*inv_n%MM*(n-x)%MM;
			//fenw.update(1,n,in[v],yy);///////
			//fenw.update(1,n,out[v]+1,-yy);//////
			fenw.update(1,n,1,y);/////
			fenw.update(1,n,in[vv],-y);/////
			fenw.update(1,n,out[vv]+1,y);///////
			if(sz(v[vv])<SQ)
			{
				for(auto j:v[vv])
					if(j!=par[vv])
						fenw.update(1,n,in[j],d*inv_n%MM*(n-sub[j])%MM),
						fenw.update(1,n,out[j]+1,(-d*inv_n%MM*(n-sub[j])%MM+MM)%MM);
			}
		}
		else
		{
			ll ans=0;
			ans+=val[vv];
			ans+=fenw.get(in[vv]);
			ans%=MM;
			for(auto j:heavy)
			{
				if(pre[idx[j]][vv]==0)continue;
				ans+=val[j]*inv_n%MM*(n-pre[idx[j]][vv]%MM);
				ans%=MM;
			}
			cout<<ans<<endl;
		}
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