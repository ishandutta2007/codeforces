#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    ld x = pow(n*(n-1)/2,3);
    ld ans = 0;
    vector<ll> cnt(1e4,0);
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
            ++cnt[abs(a[i]-a[j])];
    }
    // for(int i=0;i<=10;++i)
        // cout<<cnt[i]<<" ";
    vector<ll> can(1e5,0);
    for(int i=0;i<=5000;++i)
        for(int j=0;j<=5000;++j)
            can[i+j] += cnt[i] * 1ll * cnt[j];
    for(int i=1;i<1e5;++i)
        can[i] += can[i-1];
    for(int i=1;i<=5000;++i)
    {
        ans += cnt[i] * (can[i-1]);
    }
    ans /= x;
    cout<<fixed<<setprecision(10);
    cout<<ans<<"\n";
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
    return 0;
}