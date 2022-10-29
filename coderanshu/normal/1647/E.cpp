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
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<int> deg(n + 1, 0);
    for(int i=1;i<=n;++i) {
        cin >> p[i];
        ++deg[p[i]];
    }
    vector<int> a(n+1), mp(n+1, 0);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        if(a[i] <= n) {
            mp[a[i]] = i;
        }
    }
    int cnt = 0, f = -1;
    for(int i=1;i<=n;++i) {
        cnt += deg[i] == 0;
        if(deg[i] == 0) {
            f = a[i] - n;
        }
    }
    if(f < 0) {
        f = 0;
    }
    cnt = f / cnt;
    // cnt is the the number of moves made
    vector<int> ans(n+1);
    vector<vector<int>> nxt(n + 1, vector<int>(31, 0));
    for(int i=1;i<=n;++i) {
        nxt[i][0] = p[i];
    }
    for(int i=1;i<=30;++i) {
        for(int j=1;j<=n;++j) {
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
        }
    }

    vector<vector<int>> g(n+1);
    set<int> open;
    for(int i=1;i<=n;++i) {
        int cur = i;
        for(int j=0;j<=30;++j) {
            if(cnt & (1 << j)) {
                cur = nxt[cur][j];
            }
        }
        g[cur].push_back(i);
    }
    // for(int i=1;i<=n;++i) {
    //     cout << i << ": ";
    //     for(auto &j:g[i]) {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i=1;i<=n;++i) {
        if(mp[i] == 0) {
            assert(!open.empty());
            ans[*open.begin()] = i;
            open.erase(open.begin());
        }
        else {
            assert(!g[mp[i]].empty());
            ans[g[mp[i]][0]] = i;
            for(int j=1;j<sz(g[mp[i]]);++j) {
                open.insert(g[mp[i]][j]);
            }
        }
    }
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}