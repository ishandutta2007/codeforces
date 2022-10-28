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
    cin >> n;
    vector<int> a(2*n+1);
    int g = 0;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        g = __gcd(g,a[i]);
    }
    for(int i=n+1;i<=2*n;++i)
        a[i] = a[i-n];
    vector<vector<int>> dp(21,vector<int>(2*n+1));
    vector<int> logn(2*n+1,0);
    for(int i=2;i<=2*n;++i)
        logn[i] = logn[i/2] + 1;
    for(int i=0;i<21;++i)
    {
        for(int j=1;j<=2*n;++j)
        {
            if(i == 0)
                dp[i][j] = a[j];
            else if(j + (1<<i) <= 2*n+1)
                dp[i][j] = __gcd(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
        }
    }
    auto get = [&](int l,int r)
    {
        int x = logn[r-l+1];
        return __gcd(dp[x][l],dp[x][r-(1<<x)+1]);
    };
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        int lo = i,hi = 2*n,val = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(get(i,mid) <= g)
                val = mid,hi = mid-1;
            else
                lo = mid+1;
        }
        amax(ans, val - i);
    }
    cout << ans << "\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}