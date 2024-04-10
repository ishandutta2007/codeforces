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
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=n;++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(i);
        v[y].push_back(i);
    }
    for(int i=1;i<=n;++i) {
        if(sz(v[i]) > 2) {
            cout << "NO\n";
            return 0;
        }
        if(sz(v[i]) == 2) {
            g[v[i][0]].push_back(v[i][1]);
            g[v[i][1]].push_back(v[i][0]);
        }
    }
    vector<int> col(n + 1, -1);

    function<bool(int)> dfs = [&](int u) {
        vector<int> q = {u};
        col[u] = 0;
        for(int i=0;i<sz(q);++i) {
            int u = q[i];
            for(auto &j:g[u]) {
                if(col[j] == -1) {
                    col[j] = 1 - col[u];
                    q.push_back(j);
                }
                else if(col[j] == col[u]) {
                    return false;
                }
            }
        }
        return true;
    };
    for(int i=1;i<=n;++i) {
        if(col[i] == -1) {
            if(!dfs(i)) {
                cout << "NO\n";
                return 0;
            }
        }
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