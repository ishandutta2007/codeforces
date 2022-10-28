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

const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

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

const int N = 405;

ll dp[N][N];

int _runtimeTerror_()
{
    int n,M;
    cin>>n>>M;
    vector<ll> pw(n+10,1),fac(n+10,1),fac_inv(n+10,1);
    for(int i=1;i<=n;++i)
    {
        pw[i] = (pw[i-1] * 2) % M;
        fac[i] = (fac[i-1] * i) % M;
        fac_inv[i] = (fac_inv[i-1] * power(i,M-2,M))%M;
    }
    dp[1][1] = 1;
    // i-> prefix j-> total length
    for(int i=2;i<=n;++i)
    {
        dp[i][i] = pw[i-1] * fac_inv[i] % M;
        for(int j=1;j<i;++j)
        {
            for(int k=1;k<=j;++k)
            {
                // last k suffix
                int l = i - k - 1;
                dp[i][j] += dp[l][j-k] * pw[k-1] % M * fac_inv[k] % M;
                dp[i][j] %= M;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        // cout<<dp[n][i]<<"\n";
        ans = (ans + dp[n][i] * fac[i] % M) % M;
    }
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