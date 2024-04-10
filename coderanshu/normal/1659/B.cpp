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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int f = 0;
    vector<int> ans(n, 0);
    for(int i=0;i<n;++i) {
        int cur = (s[i] - '0') ^ f;
        if(k == 0) {
            if(f) {
                s[i] ^= '1' ^ '0';
            }
            continue;
        }
        s[i] = '1';
        if(cur == 0) {
            if(k % 2 == 0) {
                --k;
                ++ans[i];
                f ^= 1;
            }
        }
        else {
            if(k % 2 == 1) {
                --k;
                ++ans[i];
                f ^= 1;
            }
        }
    }
    if(k & 1) {
        --k;
        ++ans.back();
        s.back() ^= '0' ^ '1';
    }
    ans[0] += k;
    cout << s << "\n";
    for(int i:ans) {
        cout << i << " ";
    }
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}