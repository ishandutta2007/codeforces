#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int maxn = 201010;
const int maxlog = 20;
int n;

vector<int> gr[maxn];

int subcnt[maxn], depth[maxn];
int up[maxn][maxlog];
int parent[maxn];

void dfs(int u, int p) {
    parent[u] = p;
    up[u][0] = p;
    rep(i, 1, maxlog)
        up[u][i] = up[up[u][i - 1]][i - 1];
    
    subcnt[u] = 1;
    depth[u] = depth[p] + 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        subcnt[u] += subcnt[v];
    }
}

bool filled[maxn];
int leaves[maxn];

bool fill_up(int x, int new_leave) {
    if (filled[x]) {
        if (x == leaves[0]) {
            leaves[0] = new_leave;
            return true;
        }
        if (x == leaves[1]) {
            leaves[1] = new_leave;
            return true;
        }
        return false;
    }
    filled[x] = true;
    return fill_up(parent[x], new_leave);
}

int lift(int u, int to_depth) {
    int d = depth[u] - to_depth;
    assert(d >= 0);
    for (int i = 0; d > 0; d >>= 1, ++i)
        if (d & 1) u = up[u][i];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[v]);
    if (u == v) return u;
    for (int i = maxlog; i--; ) {
        if (up[u][i] == up[v][i]) continue;
        u = up[u][i];
        v = up[v][i];
    }
    return up[u][0];
}


ll dp[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n;
        rep(i, 0, n) {
            gr[i].clear();
            depth[i] = 0;
            filled[i] = 0;
        }
        
        rep(i, 0, n - 1) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        dfs(0, 0);
        rep(i, 0, n + 1) dp[i] = 0;
        
        dp[0] = 1ll * n * (n - 1) / 2;
        dp[1] = 0;
        {
            ll sum_prev = 1;
            for (auto v: gr[0]) {
                dp[1] += 1ll * sum_prev * subcnt[v];
                sum_prev += subcnt[v];
            }
        }
        
        filled[0] = true;
        leaves[0] = leaves[1] = 0;
        
        rep(mex, 2, n + 1) {
            DB();
            clog << db(mex) << endl;
            if (!filled[mex - 1]) {
                if (!fill_up(mex - 1, mex - 1)) break;
            }
            
            clog << db(leaves[0]) << db(leaves[1]) << endl;
            
            if (leaves[0] == 0 or leaves[1] == 0) {
                int v = leaves[0] + leaves[1];
                clog << db(v) << db(depth[v]) << db(depth[0] + 1) << endl;
                int branch = lift(v, depth[0] + 1);
                clog << db(subcnt[v]) << db(subcnt[branch]) << endl;
                dp[mex] = 1ll * subcnt[v] * (n - subcnt[branch]);
            } else {
                int u = leaves[0];
                int v = leaves[1];
                clog << db(u) << db(v) << db(subcnt[u]) << db(subcnt[v]) << endl;
                
                dp[mex] = 1ll * subcnt[u] * subcnt[v];
            }
        }
        
        // clog << db(vector<ll>(dp, dp + n + 1)) << endl; 
        
        ll sum_prev_dp = dp[n];
        for (int i = n; i --; ) {
            dp[i] -= sum_prev_dp;
            sum_prev_dp += dp[i];
        }
        rep(i, 0, n + 1) cout << dp[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker