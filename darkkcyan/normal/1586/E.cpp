#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct DSU {
    vector<int> par;
    DSU(int n): par(n, -1) {}
    int find_set(int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    }
    
    void join (int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
    }
    
    bool same_set(int u, int v) {
        return find_set(u) == find_set(v);
    }
};
const int maxn = 301010;
int n, m;

vector<int> gr[maxn];
char edge_par[maxn];
int par[maxn];
int depth[maxn];
void dfs(int u) {
    for (auto v: gr[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

list<int> get_path(int u, int v) {
    DB();
    clog << db(u) << db(v) << endl;
    list<int> x, y;
    clog << "lift u" << endl;
    while (depth[u] > depth[v]) {
        x.push_back(u);
        edge_par[u] ^= 1;
        u = par[u];
        clog << db(u) << db(v) << endl;
    }
    clog << "lift v" << endl;
    while (depth[u] < depth[v]) {
        y.push_back(v);
        edge_par[v] ^= 1;
        v = par[v];
        clog << db(u) << db(v) << endl;
    }
    clog << "lift both" << endl;
    while (u != v) {
        x.push_back(u);
        y.push_back(v);
        edge_par[u] ^= 1;
        edge_par[v] ^= 1;
        u = par[u];
        v = par[v];
        clog << db(u) << db(v) << endl;
    }
    x.push_back(u);
    y.reverse();
    x.splice(x.end(), y);
    return x;
}

int cal_unmatched(int u) {
    DB();
    clog << db(u) << endl;
    int ans = 0;
    int has_unmatched = 0;
    for (auto v: gr[u]) {
        if (v == par[u]) continue;
        ans += cal_unmatched(v);
        clog << db(v) << db(ans) << db((int)edge_par[v]) << endl;
        if (edge_par[v]) {
            if (has_unmatched) {
                ++ans;
                has_unmatched = false;
            } else {
                has_unmatched = true;
            }
        }
    }
    clog << db(ans) << endl;
    if (has_unmatched) {
        if (par[u] == -1 or edge_par[u] == 0) {
            ++ans;
        }
    }
    clog << db(ans) << endl;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    DSU dsu(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if (dsu.same_set(u, v)) continue;
        gr[u].push_back(v);
        gr[v].push_back(u);
        dsu.join(u, v);
        clog << u << ' ' << v << endl;
    }
    par[1] = -1;
    depth[1] = 0;
    dfs(1);
    
    int q;
    cin >> q;
    vector<list<int>> paths;
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        clog << db(i) << db(a) << db(b) << endl;
        paths.push_back(get_path(a, b));
    }
    
    ll left = cal_unmatched(1);
    if (left) {
        cout << "NO\n" << left << endl;
        return 0;
    }
    cout << "YES\n";
    for (auto& p: paths) {
        cout << sz(p) << '\n';
        for (auto i: p) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker