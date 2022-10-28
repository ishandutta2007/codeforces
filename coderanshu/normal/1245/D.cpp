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

const int N=2005;
vector<ll> v[N];
bool vis[N];
ll c[N],k[N],x[N],y[N],p[N],r[N],ans=0;
struct edge{
	ll x,y,w;
};
vector<edge> mst;
ll parent(ll i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
void merge(ll x,ll y)
{
	x=parent(x);
	y=parent(y);
	if(r[x]>r[y])p[y]=x;
	else p[x]=y;
	if(r[x]==r[y])++r[y];
}
int _runtimeTerror_()
{
	ll n;
	cin>>n;
	ll i,j;
	for(i=0;i<=n;++i)
		r[i]=0,p[i]=i;
	for(i=0;i<n;++i)
		cin>>x[i]>>y[i];
	for(i=0;i<n;++i)cin>>c[i];
	for(i=0;i<n;++i)cin>>k[i];

	edge ee;
	for(i=1;i<=n;++i)
	{
		ee.x=0,ee.y=i,ee.w=c[i-1];
		mst.pb(ee);
	}
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			ee.x=i+1,ee.y=j+1,ee.w=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
			mst.pb(ee);
		}
	}
	sort(all(mst),[&](edge a,edge b){return a.w<b.w;});
	vector<ll> pows;vector<pair<ll,ll>> conec;
	for(auto j:mst)
	{
		if(parent(j.x)!=parent(j.y))
		{
			merge(j.x,j.y),ans+=j.w;
			if(j.x==0 || j.y==0)
			{
				if(j.x==0)pows.pb(j.y);
				else pows.pb(j.x);
			}
			else
			{
				conec.pb({j.x,j.y});
			}
		}
	}
	cout<<ans<<endl;
	cout<<sz(pows)<<endl;
	for(auto j:pows)cout<<j<<" ";
		cout<<endl;
		cout<<sz(conec)<<endl;
	for(auto j:conec)
		cout<<j.F<<" "<<j.S<<endl;
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