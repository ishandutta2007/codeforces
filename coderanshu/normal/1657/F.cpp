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


struct SAT
{
    int n;
    vector<int> a;
    vector<vector<int>> g,rg;

    SAT(){}

    SAT(int n_):n(n_)
    {
        a.resize(2*n+1);
        g.resize(2*n+1);
        rg.resize(2*n+1);
    }
    void add_edge(int x,int y,bool negx,bool negy)
    {
        --x,--y;
        x *= 2,y *= 2;
        if(negx)
            x ^= 1;
        if(negy)
            y ^= 1;
        assert(g.size() >= x + 1);
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    vector<int> solve()
    {
        vector<int> order;
        vector<bool> vis(2*n+1,0);
        vector<int> comp(2*n+1,0);
        function<void(int)> dfs1 = [&](int u)
        {
            vis[u] = true;
            for(auto j:g[u])
                if(!vis[j])
                    dfs1(j);
            order.push_back(u);
        };
        for(int i=0;i<2*n;++i)
            if(!vis[i])
                dfs1(i);
        reverse(order.begin(),order.end());
        int cur = 1;

        function<void(int,int)> dfs = [&](int u,int cmp)
        {
            comp[u] = cmp;
            for(auto j:rg[u])
                if(comp[j] == 0)
                    dfs(j,cmp);
        };
        for(int i:order)
        {
            if(comp[i] == 0)
                dfs(i,cur++);
        }
        vector<int> ans(n+1);
        for(int i=0;i<n;++i)
        {
            int j = i * 2;
            if(comp[j] == comp[j+1])
                return {-1};
            ans[i+1] = comp[j] > comp[j+1];
        }
        return ans;
    }
};


int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<int> par(n + 1, 0), dep(n + 1, 0);
    function<void(int, int)> dfs = [&](int s, int p) {
        par[s] = p;
        for(auto &j:g[s]) {
            if(j == p) {
                continue;
            }
            dep[j] = dep[s] + 1;
            dfs(j, s);
        }
    };
    dfs(1, 0);
    vector<vector<pair<char, int>>> v(n + 1);

    vector<vector<int>> paths;

    vector<pii> qrs;
    vector<string> strs;
    for(int i=1;i<=Q;++i) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        vector<int> p;
        if(dep[x] > dep[y]) {
            swap(x, y);
            reverse(all(s));
        }
        reverse(all(s));
        while(dep[y] != dep[x]) {
            p.push_back(y);
            y = par[y];
        }
        vector<int> t;
        while(x != y) {
            p.push_back(y);
            t.push_back(x);
            y = par[y];
            x = par[x];
        }
        qrs.push_back({y, x});
        strs.push_back(s);
        p.push_back(y);
        reverse(all(t));
        for(auto &j:t) {
            p.push_back(j);
        }
        paths.push_back(p);
        assert(sz(p) == sz(s));
        for(int j=0;j<sz(p);++j) {
            v[p[j]].push_back({s[j], i});
        }
        reverse(all(s));
        for(int j=0;j<sz(p);++j) {
            v[p[j]].push_back({s[j], -i});
        }
    }

    SAT sat(Q + 8e5);
    int cur = 1;
    for(int i=1;i<=n;++i) {
        sort(all(v[i]));
        vector<int> f;
        for(int j=0;j<sz(v[i]);++j) {
            int k = j;
            f.push_back(cur);
            while(k < sz(v[i]) && v[i][k].F == v[i][j].F) {
                // debug((i - 1) * 26 + ch + Q, abs(v[i][k].S));
                sat.add_edge(Q + cur, abs(v[i][k].S), true, v[i][k].S > 0);
                sat.add_edge(abs(v[i][k].S), Q + cur, v[i][k].S < 0, false);
                // if(i == 1 && ch == 2) {
                    // debug(v[i][k], (i - 1) * 26 + ch + Q);
                // }
                ++k;
            }
            ++cur;
            j = k - 1;
        }
        for(int j:f) {
            for(int k:f) {
                if(k == j) {
                    continue;
                }
                int ver = j + Q, ver2 = k + Q;
                sat.add_edge(ver, ver2, false, true);
                sat.add_edge(ver2, ver, false, true);
            }
        }
    }

    auto ans = sat.solve();
    if(ans[0] == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    string s(n, 'a');

    for(int i=0;i<Q;++i) {
        int c = ans[i + 1];
        // debug(i + 1,c);
        if(c == 0) {
            reverse(all(paths[i]));
        }
        // debug(paths[i], strs[i]);
        for(int j=0;j<sz(paths[i]);++j) {
            s[paths[i][j] - 1] = strs[i][j];
        }
    }   
    // debug(ans[11 * 2]);
    cout << s << "\n";
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