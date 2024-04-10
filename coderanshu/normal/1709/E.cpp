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
    vector<int> a(n + 1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<int> sub(n + 1, 0), pxor(n + 1, 0);
    function<void(int, int)> dfs1 = [&](int s, int p) {
        sub[s] = 1;
        pxor[s] ^= a[s];
        for(auto &j:g[s]) {
            if(j == p) {
                continue;
            }
            pxor[j] ^= pxor[s];
            dfs1(j, s);
            sub[s] += sub[j];
        }
    };
    dfs1(1, 0);
    int ans = 0;

    map<int, int> mp;
    vector<vector<int>> xors(n + 1);
    function<void(int, int, int)> dfs = [&](int s, int p, int keep) {
        int mx = -1, big = -1;
        for(auto &j:g[s]) {
            if(j == p) {
                continue;
            }
            if(sub[j] > mx) {
                mx = sub[j], big = j;
            }
        }
        for(auto &j:g[s]) {
            if(j != p and j != big) {
                dfs(j, s, 0);
            }
        }
        if(big != -1) {
            dfs(big, s, 1);
            swap(xors[s], xors[big]);
        }
        ++mp[pxor[s]];
        xors[s].push_back(pxor[s]);
        int bad = mp[a[s] ^ pxor[s]] > 0;
        for(auto &j:g[s]) {
            if(j == p or j == big) {
                continue;
            }
            for(auto &k:xors[j]) {
                bad |= mp[k ^ a[s]] > 0;
                xors[s].push_back(k);
            }
            for(auto &k:xors[j]) {
                ++mp[k];
            }
        }
        if(bad) {
            ++ans;
            xors[s].clear();
            mp.clear();
        }
        if(!keep) {
            mp.clear();
        }
    };  
    dfs(1, 0, 1);
    cout << ans << "\n";
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