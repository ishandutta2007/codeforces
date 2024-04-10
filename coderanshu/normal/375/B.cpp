#pragma GCC optimize("o3")
#pragma GCC optimize("sse4")
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

const int N=5002;
char a[N][N];
ll cnt[N][N];
int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    }
    for(int i=0;i<n;++i)
        if(a[i][m-1]=='1')
            ++cnt[i][m-1];
    for(int j=m-2;j>=0;--j)
    {
        for(int i=0;i<n;++i)
        {
            if(a[i][j]=='1')
                cnt[i][j]=cnt[i][j+1]+1;
            else cnt[i][j]=0;
        }
    }
    ll ans=0;
    for(int j=0;j<m;++j)
    {
        vector<ll> v;
        for(int i=0;i<n;++i)
            v.pb(cnt[i][j]);
        sort(all(v));
        ll x=1;
        for(int i=n-1;i>=0;--i)
            amax(ans,v[i]*(x++));
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