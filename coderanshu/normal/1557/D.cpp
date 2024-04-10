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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    multiset<int> open;

    vector<pii> v;
    for(int i=0;i<m;++i)
    {
        int seg,l,r;
        cin >> seg >> l >> r;
        v.push_back({l,seg});
        v.push_back({r + 1, -seg});
    }
    sort(all(v));
    for(auto [x,seg]:v)
    {
        if(seg < 0)
        {
            open.erase(open.find(-seg));
            continue;
        }
        auto it = open.upper_bound(seg);
        if(it != open.end())
            g[*it].push_back(seg);
        it = open.lower_bound(seg);
        if(it != open.begin())
        {
            --it;
            g[seg].push_back(*it);
        }
        open.insert(seg);
    }
    vector<int> dp(n+1,-n), par(n+1);
    par[1] = 0;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        dp[i] = 1;
        par[i] = 0;
        for(auto &j:g[i])
        {
            if(dp[j] + 1 > dp[i])
                par[i] = j,dp[i] = dp[j] + 1;
        }
        amax(ans, dp[i]);
    }
    set<int> dont_want;
    for(int i=1;i<=n;++i)
        dont_want.insert(i);
    for(int i=n;i>=1;--i)
    {
        if(ans == dp[i])
        {
            while(i)
            {
                dont_want.erase(i);
                i = par[i];
            }
            break;
        }
    }
    cout << sz(dont_want) << "\n";
    for(auto &j:dont_want)
        cout << j << " ";
    cout << "\n";
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