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
    vector<string> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    if(a[0][0] == '1') {
        cout << "-1\n";
        return 0;
    }
    vector<array<int, 4>> ans;
    for(int i=0;i<n;++i) {
        for(int j=m-1;j>=1;--j) {
            if(a[i][j] == '1') {
                ans.push_back({i + 1, j, i + 1, j + 1});
            }
        }
    }
    for(int i=n-1;i>=0;--i) {
        if(a[i][0] == '1') {
            ans.push_back({i, 1, i + 1, 1});
        }
    }
    cout << sz(ans) << "\n";
    for(auto &[i, j, k, l]:ans) {
        cout << i << " " << j << " " << k << " " << l << "\n";
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