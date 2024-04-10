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
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 10005;

ll dp[2][N];

ll p[N],s[N];

int _runtimeTerror_()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<=n;++i)
        dp[0][i] = INF;
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=n;++i)
        cin>>s[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
            dp[i&1][j] = INF;
        for(int j=0;j<=n;++j)
        {
            if(j)
                amin(dp[i&1][j],s[i] + dp[(i-1)&1][j-1]);
            amin(dp[i&1][j],p[i] + dp[(i-1)&1][j] + j*1ll*c);
        }   
    }
    ll ans = INF;
    for(int i=0;i<=n;++i)
        amin(ans,dp[n&1][i]);
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