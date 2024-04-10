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


const int N = 55;

ll cnt[N][2*N];
// n length pe daalna hai delta is k -> cnt[n][k]

ll ncr[N][N];

const int sh = 52, hs = 50*50;

ll dp[N][4*N*N][2],fac[N];

int _runtimeTerror_()
{
    int n,mod;
    cin >> n >> mod;

    if(mod == 1) {
        cout << "0\n";     
        return 0;
    }

    for(int i=0;i<=n;++i)
        ncr[i][0] = 1 % mod;

    fac[0] = 1 % mod;
    for(int i=1;i<=n;++i)
    {
        fac[i] = fac[i-1] * i % mod;
        for(int j=1;j<=n;++j)
        {
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            ncr[i][j] %= mod;
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=i-1;++j)
        {
            for(int k=0;k<=i-1;++k)
            {
                ++cnt[i][(j-k+sh)];
                cnt[i][(j-k+sh)] %= mod;
            }
        }
    }

    int mx = n * (n - 1)/2;
    // cout << ncr[5][6] << "\n";
    dp[0][0][0] = 1;
    for(int i=0;i<n;++i)
    {
        int len = n-i;
        dp[i+1][0][0] = dp[i][0][0] * len % mod;
        for(int j=-len;j<0;++j)
            dp[i+1][j+hs][1] += cnt[len][j+sh] * dp[i][0][0];
        for(int k=-mx;k<=mx;++k)
        {
            for(int l=-len;l<=len;++l)
            {
                if(k + l >= -mx && k + l <= mx)
                {
                    dp[i+1][k+l+hs][1] += dp[i][k+hs][1] * cnt[len][l+sh] % mod;
                    dp[i+1][k+l+hs][1] %= mod;
                }
            }
        }
    }

    ll ans = 0;

    for(int i=1;i<=mx;++i)
        ans = (ans + dp[n][i+hs][1]) % mod;
    cout << ans << "\n";

    // for(int i=0;i<=n-1;++i)
    // {
    //     int len = n - i;
    //     for(int j=1;j<=len;++j)
    //         for(int k=-len*(len-1)/2;k<=len*(len-1)/2;++k)
    //             dp[j][k+hs] = 0;
    //     for(int j=-len;j<0;++j)
    //         dp[1][j+hs] = cnt[len][j+sh];
    //     for(int j=1;j<len;++j)
    //     {
    //         int rem = len - j;
    //         assert(cnt[rem][rem+sh] == 0);
    //         for(int k=-len*(len-1)/2;k<=len*(len-1)/2;++k)
    //         {
    //             for(int l=-rem;l<=rem;++l)
    //             {
    //                 if(k + l >= -len*(len-1)/2 && k + l <= len * (len - 1)/2)
    //                 {
    //                     dp[j+1][k+l+hs] += dp[j][k+hs] * cnt[rem][l+sh] % mod;
    //                     dp[j+1][k+l+hs] %= mod;
    //                 }
    //             }
    //         }
    //     }
    //     for(int j=1;j<=len*(len-1)/2;++j)
    //     {
    //         ans += ncr[n][i] * fac[i] % mod * 1ll * dp[len][j+hs] % mod;
    //         ans %= mod;
    //     }
    //     // cout << ans << "\n";
    // }
    assert(ans < mod);
    // cout << ans << "\n";
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