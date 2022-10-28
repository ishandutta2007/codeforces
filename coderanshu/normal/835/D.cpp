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

const int N = 5005;

int dp[N][N];

int _runtimeTerror_()
{
    string s;
    cin>>s;
    s = "#"+s;
    int n = sz(s)-1;
    for(int i=1;i<=n;++i)
    {
        dp[i][i] = 1;
    }
    for(int len=1;len<=n;++len)
    {
        for(int i=1;i<=n;++i)
        {
            if(i+len-1>n)
                break;
            int r = i+len-1;
            if(s[i] == s[r] && (i+1 > r-1 || dp[i+1][r-1]))
            {
                int half = len/2;
                dp[i][r] = dp[i][i+half-1]+1;
            }
        }
    }
    vector<int> ans(n+2);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(dp[i][j])
            {
                ++ans[1],--ans[dp[i][j]+1];
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        ans[i] += ans[i-1];
        cout<<ans[i]<<" ";
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