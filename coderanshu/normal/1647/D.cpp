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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int x, d;
    cin >> x >> d;
    int rem = x;
    int cnt = 0;
    auto prime = [&](int x) {
        for(int i=2;i*i<=x;++i) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    };
    while(rem % d == 0) {
        rem /= d;
        ++cnt;
    }
    if(cnt == 1) {
        cout << "NO\n";
        return 0;
    }
    if(!prime(rem)) {
        cout << "YES\n";
        return 0;
    }
    if(prime(d)) {
        cout << "NO\n";
        return 0;
    }
    if(cnt == 2) {
        cout << "NO\n";
        return 0;
    }
    if(cnt >= 4) {
        cout << "YES\n";
        return 0;
    }
    if(d == rem * 1ll * rem) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
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