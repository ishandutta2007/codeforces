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

ll dp[N][N];

ll p[N],s[N];

ll a[N],b[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int j=1;j<=n;++j)
        cin>>b[j];
    for(int i=1;i<=n;++i)
        dp[i][i] = a[i] * b[i];
    for(int i=1;i<=n-1;++i)
        dp[i][i+1] = a[i] * b[i+1] + a[i+1] * b[i];
    for(int len=3;len<=n;++len)
    {
        for(int i=1;i<=n;++i)
        {
            int r = i + len - 1;
            if(r > n)
                break;
            dp[i][r] = a[i] * b[r] + b[i] * a[r] + dp[i+1][r-1];
        }
    }   
    for(int i=1;i<=n;++i)
    {
        p[i] += p[i-1];
        p[i] += a[i] * b[i];
    }
    for(int i=n;i>=1;--i)
        s[i] += s[i+1],s[i] += a[i] * b[i];
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            amax(ans,dp[i][j] + p[i-1] + s[j+1]);
        }
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