#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll int 
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
#define ld long double

const long double PI = acos(-1);

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
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N=1000005;
ll n,k;
const int LOGN=21;
vector<int> v[N];
int dep[N],par[N][LOGN];
bitset<N> taken;

void dfs(ll s,ll p)
{
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1,par[j][0]=s;
            dfs(j,s);
        }
    }
}
void sparseMatrix(ll n)
{
    for(ll i=1;i<LOGN;++i)
        for(ll j=1;j<=n;++j)
                par[j][i]=par[par[j][i-1]][i-1];
}
ll lca(ll u,ll v)
{
    if(dep[u]>dep[v])swap(u,v);
    ll df=dep[v]-dep[u];
    for(ll i=0;i<LOGN;++i)
        if(df&(1<<i))v=par[v][i];
    if(u==v)return u;
    for (ll i=LOGN-1; i>=0; i--) 
    {
        if(par[u][i]!=par[v][i]) 
        { 
            u=par[u][i]; 
            v=par[v][i];
        } 
    }
    return par[u][0]; 
}
ll pl(ll a,ll b)
{
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void solve(int vv,int &cur)
{
	if(taken[vv])
		return ;
	int ver=vv;
	for(int i=LOGN-1;i>=0;--i)
	{
		if(!taken[par[vv][i]])
			vv=par[vv][i];
	}
	vv=par[vv][0];
	int x=dep[ver]-dep[vv];
	if(cur+x>n-k)
		return ;
	cur+=x;
	while(ver!=vv)
	{
		taken[ver]=1;
		ver=par[ver][0];
	}
}
int _runtimeTerror_()
{
	
	cin>>n>>k;
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs(n,-1);
	sparseMatrix(n);
	taken[0]=1;
	taken[n]=1;
	int cur=1;
	while(cur<n-k)
	{
		for(int i=n-1;i>=1;--i)
			solve(i,cur);
	}
	for(int i=1;i<=n;++i)
		if(!taken[i])
			cout<<i<<" ";
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