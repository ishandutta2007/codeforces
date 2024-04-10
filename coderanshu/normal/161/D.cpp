#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
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
const int N=50005;
set<int> v[N];
ll ctree[N],sub[N];
ll cntoftr,k;
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
ll ans=0;
int dis[600],temp[600];
void dfs3(ll s,ll p,ll dep)
{
    if(dep<=k)
    {
        ans+=dis[k-dep];
        ++temp[dep];
    }
    if(dep==k)++ans;
    for(auto j:v[s])
        if(j!=p)
            dfs3(j,s,dep+1);
}
void decompose(ll s,ll p)
{
    cntoftr=0;
    dfs1(s,s);
    ll centroid=dfs2(s,s);
    //if(p==-1)p=centroid;
    //ctree[centroid]=p;
    for(int j:v[centroid])
    {
        for(int i=0;i<=500;++i)
            temp[i]=0;
        v[j].erase(centroid);
        dfs3(j,-1,1);
        for(int i=1;i<=500;++i)
            dis[i]+=temp[i];
    }
    for(int i=1;i<=500;++i)
        dis[i]=0;
    for(ll j:v[centroid])
        decompose(j,centroid);
    v[centroid].clear();
}

int _runtimeTerror_()
{
    ll n;
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].insert(y),v[y].insert(x);
    }
    decompose(1,-1);
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