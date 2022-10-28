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
    vector<vector<int>> a(n+1, vector<int>(m + 1));
    auto vis = a;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cin >> a[i][j];
        }
    }
    vector<int> dx = {0, 1, 1, 0}, dy = {0, 0, 1, 1};
    vector<array<int, 3>> ans;
    auto check = [&](int x, int y) {
        if(x >= 1 and x < n and y >= 1 and y < m) {
            set<int> color;
            for(int i=0;i<4;++i) {
                if(a[x + dx[i]][y + dy[i]] != -1) {
                    color.insert(a[x + dx[i]][y + dy[i]]);
                }
            }
            if(sz(color) > 1) {
                return -2;
            }
            if(sz(color) == 1) {
                return *color.begin();
            }
            return -1;
        }   
        return -2;
    };
    vector<pii> good;
    for(int i=1;i<n;++i) {
        for(int j=1;j<m;++j) {
            if(check(i, j) != -2) {
                good.push_back({i, j});
            }
        }
    }
    vector<int> dx2 = {+1, 0, -1, -1, -1, 0, 1, 1}, dy2 = {-1, -1, -1, 0, +1, +1, +1, 0};
    while(!good.empty()) {
        // debug(good);
        auto [x, y] = good.back();
        good.pop_back();
        if(vis[x][y]) {
            continue;
        }
        vis[x][y] = 1;
        int u = check(x, y);
        assert(u != -2);
        for(int i=0;i<4;++i) {
            a[x + dx[i]][y + dy[i]] = -1;
        }
        if(u != -1) {
            ans.push_back({x, y, u});
        }
        for(int i=0;i<8;++i) {
            if(check(x + dx2[i], y + dy2[i]) != -2 && !vis[x + dx2[i]][y + dy2[i]]) {
                good.push_back({x + dx2[i], y + dy2[i]});
            }
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j] != -1) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for(auto [i, j, k]:ans) {
        cout << i << " " << j << " " << k << "\n";
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
    // cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}