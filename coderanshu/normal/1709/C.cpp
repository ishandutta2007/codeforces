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
    string s;
    cin >> s;
    int n = sz(s);
    int op = 0, cl = 0;
    for(auto &j:s) {
        op += j == '(';
        cl += j == ')';
    }
    op = n / 2 - op, cl = n / 2 - cl;
    if(op == 0 || cl == 0) {
        cout << "YES\n";
        return 0;
    }
    int last_op = -1, first_cl = n + 100;
    for(int i=0;i<n;++i) {
        if(s[i] == '?') {
            if(op > 0) {
                --op;
                s[i] = '(';
                last_op = i;
            }
            else {
                --cl;
                s[i] = ')';
                amin(first_cl, i);
            }
        }
    }
    swap(s[last_op], s[first_cl]);
    int cnt = 0;
    for(auto &j:s) {
        cnt += j == '(';
        cnt -= j == ')';
        if(cnt < 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
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