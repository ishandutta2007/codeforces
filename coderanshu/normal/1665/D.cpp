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
    ll cur = 2, m1 = 0, m2 = 1;
    for(int i=1;i<=30;++i) {
        if(m1 < m2) {
            swap(m1, m2);
        }
        cout << "? " << cur - m1 << " " << 2 * cur - m1 << "\n" << flush;
        ll g;
        cin >> g;
        if(g % cur == 0) {
            if(i == 30) {
                cout << "! " << m1 << "\n" << flush;
                return 0;
            }
            m2 = m1 + cur;
        }
        else {
            if(i == 30) {
                cout << "! " << m2 << "\n" << flush;
                return 0;
            }
            swap(m1, m2);
            m2 = m1 + cur;
        }
        cur *= 2;
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