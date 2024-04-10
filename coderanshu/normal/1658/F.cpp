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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int one = count(all(s), '1');
    if(one * 1ll * m % n != 0) {
        cout << "-1\n";
        return 0;
    }
    one = one * 1ll * m / n;
    for(int i=0;i<m;++i) {
        one -= s[i] == '1';
    }
    if(one == 0) {
        cout << "1\n1 " << m << "\n";
        return 0;
    }
    for(int i=1;i<n;++i) {
        one += s[i - 1] == '1';
        one -= s[(i + m - 1) % n] == '1';
        if(one == 0) {
            if(i + m - 1 < n) {
                cout << 1 << "\n";
                cout << i + 1 << " " << i + m << "\n";
            }
            else {
                cout << 2 << "\n";
                cout << 1 << " " << (i + m - 1) % n + 1 << "\n";
                cout << i + 1 << " " << n << "\n";
            }
            return 0;
        }
    }
    assert(false);
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