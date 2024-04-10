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

#define double long double

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<double> p(n);
    for(int i=0;i<n;++i)
        cin>>p[i];
    vector<double> dp(1<<n,0),ans(n,0);
    dp[0] = 0;
    for(int i=0;i<(1<<n);++i)
    {
        double sum = 0;
        for(int j=0;j<n;++j)
            if(i&(1<<j))
                sum += p[j];
        if(abs(sum - 1) > 1e-8)
            dp[i] += 1.0*sum/(1-sum);
        if(popcount(i) & 1)
            dp[i] = -dp[i];
    }
    for(int j=0;j<n;++j)
        for(int i=0;i<(1<<n);++i)
            if(i&(1<<j))
                dp[i] += dp[i^(1<<j)];

    for(int i=1;i<(1<<n);++i)
    {
        if(popcount(i) >= k)
            continue;
        if(popcount(i) & 1)
            dp[i] = -dp[i];
        for(int j=0;j<n;++j)
            if((i&(1<<j)) == 0 && abs(p[j]) > 1e-10)
                ans[j] += dp[i] * p[j];
    }
    cout<<fixed<<setprecision(13);
    for(int i=0;i<n;++i)
        cout<<ans[i]+p[i]<<" ";
    cout<<"\n";
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
// hhhhhhhhhhhh quite confusing inclusion exclusion