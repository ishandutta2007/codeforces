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
    int p;
    cin >> p;
    int n = (1 << p);
    vector<vector<pii>> g(n + 1);
    vector<int> v_val(n + 1), e_val(n + 1);
    for(int i=0;i<n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, i}), g[y].push_back({x, i});
    }
    v_val[1] = (1 << p);
    int l = (1 << p) - 1, r = (1 << p) + (1 << p) - 1;

    cout << 1 << "\n";
    function<void(int, int, int)> dfs = [&](int s, int p, int flip) {
        for(auto &[j, k]:g[s]) {
            if(j == p) {
                continue;
            }
            v_val[j] = l;
            e_val[k] = r;
            if(flip) {
                swap(v_val[j], e_val[k]);
            }
            --l, --r;
            dfs(j, s, flip ^ 1);
        }
    };
    dfs(1, 0, 0);
    for(int i=1;i<=n;++i) {
        cout << v_val[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n-1;++i) {
        cout << e_val[i] << " ";
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