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

int _runtimeTerror_()
{
    int n,k,l;
    cin>>n>>k>>l;
    string s;
    cin>>s;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        a[i] = s[i-1] >= 'a' && s[i-1] <= 'z';
    auto solve = [&](vector<int> &a)
    {
        auto f = [&](int x)
        {
            vector<pii> dp(n+1,make_pair(1e9,1e9));
            dp[0] = {0,0};
            for(int i=1;i<=n;++i)
            {
                amin(dp[i],make_pair(dp[i-1].F + a[i],dp[i-1].S));
                amin(dp[i],make_pair(dp[max(i-l,0)].F+x,dp[max(i-l,0)].S+1));
            }
            return dp[n];
        };
        int lo = 0,hi = n+1,ans = -1,val = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            auto u = f(mid);
            if(u.S <= k)
                ans = mid, val = u.F, hi = mid-1;
            else
                lo = mid+1;
        }
        return val - ans * k;
    };
    int ans = 2e9;
    amin(ans,solve(a));
    for(int i=1;i<=n;++i)
        a[i] ^= 1;
    amin(ans,solve(a));
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