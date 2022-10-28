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
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=m;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    vector<int> vis(n + 1, 0), cur(n + 1, 0);
    vector<int> un;
    function<void(int, int)> dfs = [&](int u, int p) {
        if(vis[u]) {
            vector<int> a, b;
            int f = p;
            a.push_back(u);
            while(f != s) {
                a.push_back(f);
                f = vis[f];
            }
            a.push_back(s);
            f = u;
            while(f != s) {
                b.push_back(f);
                f = vis[f];
            }
            b.push_back(s);
            reverse(all(a)), reverse(all(b));
            cout << "Possible\n";
            cout << sz(a) << "\n";
            for(auto i:a) {
                cout << i << " ";
            }
            cout << "\n";
            cout << sz(b) << "\n";
            for(auto i:b) {
                cout << i << " ";
            }
            cout << "\n";
            exit(0);
        }
        vis[u] = p;
        cur[u] = 1;
        un.push_back(u);
        for(auto &j:g[u]) {
            if(!cur[j] && j != s) {
                dfs(j, u);
            }
        }
    };
    vis[s] = s;
    for(auto &j:g[s]) {
        dfs(j, s);
        for(auto j:un) {
            cur[j] = 0;
        }
        un.clear();
    }
    cout << "Impossible\n";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}