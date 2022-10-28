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

ll n,m,k;
struct node{
    int s,t,d;
    ll w;
}a[100005];
const int N=100005;
vector<pair<int,int>> add[N],sub[N];
pair<ll,ll> val[N];
ll dp[N][202];
ll getans(ll pos,ll m)
{
    if(pos==n+1)
        return 0;
    if(dp[pos][m]!=-1)
        return dp[pos][m];
    ll ans=INF;
    if(m>0)
    {
        amin(ans,getans(val[pos].S+1,m)+val[pos].F);
        amin(ans,getans(pos+1,m-1));
    }
    else
    {
        amin(ans,getans(val[pos].S+1,0)+val[pos].F);
    }
    return dp[pos][m]=ans;
}
int _runtimeTerror_()
{
    mem1(dp);
    cin>>n>>m>>k;
    ll i,j;
    for(i=0;i<k;++i)
    {
        cin>>a[i].s>>a[i].t>>a[i].d>>a[i].w;
        add[a[i].s].pb({a[i].w,a[i].d});
        sub[a[i].t+1].pb({a[i].w,a[i].d});
    }
    multiset<pair<int,int>> s;
    for(i=1;i<=n;++i)
    {
        for(auto j:add[i])
            s.insert(j);
        for(auto j:sub[i])
            s.erase(s.find(j));
        if(s.empty())
            val[i].F=0,val[i].S=i;
        else
        {
            val[i]=*s.rbegin();
        }
    }
    cout<<getans(1,m);    
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
// dp + greedy + sorting .. nice but easy one