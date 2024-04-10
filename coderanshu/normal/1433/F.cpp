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

const int N = 100;

ll dp[N][N][N];

ll a[N][N];

ll dp2[N][N],dp3[N][N];

int _runtimeTerror_()
{
    int n,m,K;
    cin>>n>>m>>K;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
            for(int k=0;k<=m;++k)
                for(int l=0;l<=K;++l)
                    dp[j][k][l] = -2e9;
        dp[0][0][0] = 0;
        for(int j=1;j<=m;++j)
        {
            for(int l=0;l<=m/2;++l)
            {
                for(int k=0;k<K;++k)
                {
                    dp[j][l][k] = dp[j-1][l][k];
                    if(l>0)
                    {
                        amax(dp[j][l][k],dp[j-1][l-1][k]);
                        int u = (k-a[i][j]%K+K)%K;
                        amax(dp[j][l][k],a[i][j] + dp[j-1][l-1][u]);
                    }
                }
            }
        }
        for(int j=0;j<K;++j)
            dp2[i][j] = dp[m][m/2][j];
    }
    for(int i=0;i<=n;++i)
        for(int j=0;j<=K;++j)
            dp3[i][j] = -2e9;
    dp3[0][0] =0;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<K;++j)
        {
            dp3[i][j] = dp3[i-1][j];
            for(int l=0;l<K;++l)
            {
                int u = ((j-l+K)%K + K)%K;
                amax(dp3[i][j],dp2[i][l] + dp3[i-1][u]);
            }
        }
    }
    assert(dp3[n][0]>=0);
    cout<<dp3[n][0]<<"\n";
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