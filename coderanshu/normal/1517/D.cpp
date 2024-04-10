// Har Har Mahadev
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

const int N = 505;

int a[N][N],b[N][N];

ll dp[15][N][N];

int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m-1;++j)
            cin>>a[i][j];
    }
    for(int i=1;i<=n-1;++i)
    {
        for(int j=1;j<=m;++j)
            cin>>b[i][j];
    }
    if(k&1)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cout<<"-1 ";
            }
            cout<<"\n";
        }
        return 0;
    }
    for(int l=1;l<=12;++l)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                dp[l][i][j] = INF;
    for(int l=1;l<=k/2;++l)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(i-1>=1)
                {
                    amin(dp[l][i][j],b[i-1][j]*1ll*l);
                    amin(dp[l][i][j],b[i-1][j]+dp[l-1][i-1][j]);
                }
                if(j-1>=1)
                {
                    amin(dp[l][i][j],a[i][j-1]*1ll*l);
                    amin(dp[l][i][j],a[i][j-1] + dp[l-1][i][j-1]);
                }
                if(i+1<=n)
                {
                    amin(dp[l][i][j],b[i][j]*1ll*l);
                    amin(dp[l][i][j],b[i][j] + dp[l-1][i+1][j]);
                }
                if(j+1<=m)
                {
                    amin(dp[l][i][j],a[i][j]*1ll*l);
                    amin(dp[l][i][j],a[i][j] + dp[l-1][i][j+1]);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cout<<dp[k/2][i][j]*2<<" ";
        }
        cout<<"\n";
    }
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