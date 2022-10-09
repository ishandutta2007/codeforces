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

const int maxn = 101010;
const int maxlg = 20;
int n;
vector<int> gr[maxn];

int up[maxlg][maxn];
int depth[maxn];
void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    up[0][u] = p;
    rep(i, 1, maxlg) up[i][u] = up[i - 1][up[i - 1][u]];
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int d = depth[u] - depth[v], i = 0; d > 0; d >>= 1, ++i)
        if (d & 1) u = up[i][u];
    if (u == v) return u;
    for (int i = maxlg; i--; ) {
        if (up[i][u] == up[i][v]) continue;
        u = up[i][u];
        v = up[i][v];
    }
    return up[0][u];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    dfs(1, 1);
    
    int q; cin >> q;
    while (q--) {
        DB();
        int x, y, a, b, k;
        cin >> x >>y >> a >> b >> k;
        clog << db(x) << db(y) << db(a) << db(b) << db(k) << endl;
        
        int l1 = dist(a, b);
        int l2 = dist(a, x) + 1 + dist(b, y);
        int l3 = dist(a, y) + 1 + dist(b, x);
        int l4 = l2 + dist(x, y) + 1;
        int l5 = l3 + dist(x, y) + 1;
        clog << db(l1) << db(l2) << db(l3) << db(l4) << db(l5) << endl;
        bool ok = false;
        for (auto t: {l1, l2, l3, l4, l5}) {
            if (t > k) continue;
            if ((t + k) & 1) continue;
            ok = true;
            break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker