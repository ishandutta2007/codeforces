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

vector<int> d[200005];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    const int N = 200000;
    vector<int> dp(N+1,-1e8),cnt(N+1);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        ++cnt[x];
    }
    int ans = 1;
    for(int i=1;i<=N;++i)
    {
        amax(dp[i],cnt[i]);
        for(int j:d[i])
            amax(dp[i],cnt[i]+dp[j]);
        amax(ans,dp[i]);
    }
    cout<<n-ans<<"\n";
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
    for(int i=1;i<=200000;++i)
    {
        for(int j=2*i;j<=200000;j+=i)
            d[j].pb(i);
    }
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}