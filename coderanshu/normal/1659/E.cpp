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

struct DSU {
    int n, cmps;
    vector<int> p, sub, cnt;
    DSU(int n_) {
        n = n_;
        cmps = n;
        p.resize(n+1);
        sub.resize(n+1, 1);
        cnt.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int parent(int i) {
        assert(i <= n);
        return p[i] = (p[i] == i ? i : parent(p[i]));
    }
    bool merge(int x, int y) {
        assert(x <= n && y <= n);
        x = parent(x), y = parent(y);
        if(x == y) {
            return false;
        }
        --cmps;
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        sub[y] += sub[x];
        cnt[y] += cnt[x];
        cnt[x] = 0;
        p[x] = y;
        return true;
    }
    void clear() {
        cmps = n;
        iota(p.begin(), p.end(), 0);
        sub.assign(n+1, 1);
        cnt.assign(n + 1, 0);
    }
    int operator[](int i) {
        return parent(i);
    }
};


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(30, vector<int>(n + 1, 0));
    vector<int> cnt(n + 1, 0);
    vector<array<int, 3>> edges;
    for(int i=1;i<=m;++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    DSU dsu(n);
    for(int i=0;i<30;++i) {
        for(auto [x, y, w]:edges) {
            if(w & (1 << i)) {
                dsu.merge(x, y);
            }
        }
        for(int j=1;j<=n;++j) {
            a[i][j] = dsu.parent(j);
        }
        dsu.clear();
    }
    for(int i=1;i<30;++i) {
        for(auto &[x, y, w]:edges) {
            if(!(w & 1)) {
                ++dsu.cnt[x];
                ++dsu.cnt[y];
            }
        }
        for(auto &[x, y, w]:edges) {
            if((w & 1) && (w & (1 << i))) {
                dsu.merge(x, y);
            }
        }
        for(int j=1;j<=n;++j) {
            cnt[j] += dsu.cnt[dsu.parent(j)];
        }
        dsu.clear();
    }
    int Q;
    cin >> Q;
    for(int i=1;i<=Q;++i) {
        int u, v;
        cin >> u >> v;
        int ans = 1;
        for(int j=0;j<30;++j) {
            if(a[j][u] == a[j][v]) {
                ans = 0;
            }
        }
        if(ans == 0) {
            cout << ans << "\n";
            continue;
        }
        if(cnt[u] > 0) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
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