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

const int N = 10001,X = 102;

bitset<N> dp[X][X];

int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(dp[n][m][k]?"YES":"NO")<<"\n";
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
    dp[1][1][0] = 1;
    for(int i=1;i<=100;++i)
    {
        for(int j=1;j<=100;++j)
        {
            dp[i][j+1] |= (dp[i][j] << i);
            dp[i+1][j] |= (dp[i][j] << j);
        }
    }
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}