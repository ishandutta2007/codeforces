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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == 0 and c == 0) {
        cout << "0\n";
    }
    else if(a == 0 or c == 0) {
        cout << "1\n";
    }
    else {
        int g = __gcd(a, b);
        a /= g, b /= g;
        g = __gcd(c, d);
        c /= g, d /= g;
        if(a == c and b == d) {
            cout << "0\n";
        }
        else if((a % c == 0 and d % b == 0) or  (c % a == 0 and b % d == 0)) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}