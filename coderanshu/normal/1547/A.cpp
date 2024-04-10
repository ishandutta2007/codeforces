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
    pii a,b,c;
    cin >> a.F >> a.S;
    cin >> b.F >> b.S;
    cin >> c.F >> c.S;
    if(a.F != b.F && a.S != b.S)
    {
        cout << abs(a.F - b.F) + abs(a.S - b.S) << "\n";
        return 0;
    }
    if(a.F != b.F)
    {
        if(c.F >= min(a.F,b.F) && c.F <= max(a.F,b.F) && c.S == a.S)
            cout << abs(a.F - b.F) + 2 << "\n";
        else
            cout << abs(a.F - b.F) << "\n";
    }
    else
    {
        if(c.S >= min(a.S,b.S) && c.S <= max(a.S,b.S) && c.F == a.F)
            cout << abs(a.S - b.S) + 2 << "\n";
        else
            cout << abs(a.S - b.S) << "\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}