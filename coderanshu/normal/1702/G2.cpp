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
#define debug(...) 3000
#endif


const int N = 200005;

vector<int> g[N], v[N];

int in[N], out[N], dep[N], par[N][20], cur = 1;

void dfs(int s, int p) {
    par[s][0] = p;
    for(int i=1;i<20;++i) {
        par[s][i] = par[par[s][i-1]][i-1];
    }
    in[s] = cur++;
    for(auto &j:v[s]) {
        if(j == p) {
            continue;
        }
        dep[j] = dep[s] + 1;
        dfs(j, s);
    }
    out[s] = cur - 1;
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) {
        swap(u, v);
    }
    int d = dep[v] - dep[u];
    for(int i=19;i>=0;--i) {
        if(d & (1 << i)) {
            v = par[v][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i=19;i>=0;--i) {
        if(par[u][i] != par[v][i]) {
            u = par[u][i], v = par[v][i];
        }
    }
    return par[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=1;i<n;++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }

    auto is_anc = [&](int x, int y) {
        return in[x] <= in[y] and out[x] >= in[y];
    };

    dfs(1, 0);
    int Q;
    cin >> Q;
    while(Q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for(auto &i:a) {
            cin >> i;
        }
        sort(all(a), [&](int x, int y) {
            return in[x] < in[y];
        });
        if(k <= 2) {
            cout << "YES\n";
            continue;
        }
        int bk = -1;
        for(int i=k-2;i>=0;--i) {
            if(!is_anc(a[i], a[i + 1])) {
                bk = i;
                break;
            }
        }
        if(bk == -1) {
            cout << "YES\n";
            continue;
        }
        int ck = -1;
        for(int i=bk-1;i>=0;--i) {
            if(!is_anc(a[i], a[i + 1])) {
                ck = i;
                break;
            }
        }
        if(ck != -1) {
            cout << "NO\n";
            continue;
        }
        // 0 and bk + 1
        if(dep[a[0]] < dep[a[bk + 1]]) {
            if(bk == 0) {
                cout << "YES\n";
            }
            else {
                if(dis(a[bk + 1], a[0]) + dis(a[0], a[1]) == dis(a[bk + 1], a[1])) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
        else {
            if(bk == k - 2) {
                cout << "YES\n";
            }
            else {
                if(dis(a[0], a[bk + 1]) + dis(a[bk + 1], a[bk + 2]) == dis(a[0], a[bk + 2])) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
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
    // cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}