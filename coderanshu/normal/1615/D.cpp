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

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n+1);
    vector<int> p(n+1), sub(n+1, 1);
    iota(all(p),0);

    function<int(int)> parent = [&](int x) {
        return p[x] = (p[x] == x ? x : parent(p[x]));
    };

    function<void(int,int)> merge = [&](int x,int y) {
        x = parent(x), y = parent(y);
        if(x == y) {
            return ;
        }
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        sub[y] += sub[x];
        p[x] = y;
    };

    vector<pii> no;
    for(int i=0;i<n-1;++i) {
        int x, y, v;
        cin >> x >> y >> v;
        g[x].push_back({y, v});
        g[y].push_back({x, v});
        if(v == -1) {
            continue;
        }
        if(popcount(v) & 1) {
            no.push_back({x, y});
        }
        else {
            merge(x, y);
        }
    }
    for(int i=0;i<m;++i) {
        int a, b, p;
        cin >> a >> b >> p;
        if(popcount(p) & 1) {
            no.push_back({a, b});
        }
        else {
            merge(a, b);
        }
    }
    vector<vector<int>> v(n+1);
    vector<bool> vis(n+1);
    for(auto &[i, j]:no) {
        if(parent(i) == parent(j)) {
            cout << "NO\n";
            return 0;
        }
        v[parent(i)].push_back(parent(j));
        v[parent(j)].push_back(parent(i));
    }
    vector<int> parity(n+1,0);
    for(int i=1;i<=n;++i) {
        if(!vis[parent(i)]) {
            vector<int> q = {parent(i)};
            vis[parent(i)] = 1;
            for(int j=0;j<sz(q);++j) {
                int u = q[j];
                for(auto &k:v[u]) {
                    if(!vis[k]) {
                        parity[k] = parity[u] ^ 1;
                        q.push_back(k);
                        vis[k] = 1;
                    }
                    else if(parity[k] == parity[u]) {
                        debug(k,u);
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    vector<array<int,3>> ans;
    function<void(int,int)> dfs = [&](int s, int p) {
        for(auto &[j,k]:g[s]) {
            if(j == p) {
                continue;
            }
            if(k == -1) {
                k = parity[parent(s)] ^ parity[parent(j)];
            }
            dfs(j, s);
            ans.push_back({s,j,k});
        }
    };  

    dfs(1,0);

    for(auto [i,j,k]:ans) {
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}