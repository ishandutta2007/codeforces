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
    int n;
    cin>>n;
    ll ans = 0;
    vector<pll> a(n);
    ll sum = 0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].S>>a[i].F;
        sum += a[i].S;
    }
    sort(all(a));
    ll cur = 0;
    debug(a);
    for(int i=0;i<sz(a);++i)
    {
        debug(cur);
        if(cur >= a[i].F)
        {
            ans += a[i].S;
            cur += a[i].S;
            continue;
        }
        if(i == sz(a) - 1)
        {
            if(a[i].S + cur <= a[i].F)
                ans += a[i].S * 2;
            else
            {
                ans += 2 * (a[i].F - cur);
                a[i].S -= (a[i].F - cur);
                ans += a[i].S;
            }
            // cur += a[i].S;
            break; 
        }
        ll want = a[i].F - cur;
        if(a.back().S > want)
        {
            a.back().S -= want;
            ans += 2 * want;
            cur += want;
            ans += a[i].S;
            cur += a[i].S;
        }
        else
        {
            ans += 2 * a.back().S;
            cur += a.back().S;
            --i;
            a.pop_back();
        }
        debug(ans);
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