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
    int lo = 0,hi = m + 2, ans = 0;

    function<bool(int)> can = [&](int x)
    {
        int val = 0, cur = 0;
        for(int i=29;i>=0;--i)
        {
            if(n & (1 << i))
                val += (1 << i);
            else if(cur + (1 << i) <= x)
                val += (1 << i), cur += (1 << i);
        }
        return val > m;
    };

    while(lo <= hi) 
    {
        int mid = (lo + hi)/2;
        if(can(mid))
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans << "\n";
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}