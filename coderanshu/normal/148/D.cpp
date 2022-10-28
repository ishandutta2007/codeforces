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

const int N = 1002;

double dp[N][N];

int _runtimeTerror_()
{
    int w,b;
    cin>>w>>b;
    for(int i=1;i<=w;++i)
        dp[i][0] = 1.0;
    for(int i=1;i<=w;++i)
    {
        for(int j=1;j<=b;++j)
        {
            dp[i][j] = 1.0*i/(i+j);
            if(j>1)
                dp[i][j] += 1.0*j/(i+j)*(j-1)/(i+j-1)*( (j>=3?1.0*(j-2)/(i+j-2)*dp[i][j-3]:0) + (1.0*i/(i+j-2)*dp[i-1][j-2]) ); 
        }
    }
    cout<<fixed<<setprecision(9);
    cout<<dp[w][b];
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