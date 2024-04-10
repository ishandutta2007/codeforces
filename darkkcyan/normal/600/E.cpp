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
int n;
int c[maxn];
vector<int> gr[maxn];

int cnt_col[maxn];
int mx_col = 0;
ll sum_col = 0;

void inc_col(int col, int delta) {
    cnt_col[col] += delta;
    if (cnt_col[col] > mx_col) {
        mx_col = cnt_col[col];
        sum_col = col;
    } else if (cnt_col[col] == mx_col) {
        sum_col += col;
    }
}

void add_col(int u, int p, int delta) {
    inc_col(c[u], delta);
    for (auto v: gr[u]) {
        if (v == p) continue;
        add_col(v, u, delta);
    }
}

int cnt_child[maxn];
void dfs_count_child(int u, int p) {
    cnt_child[u] = 1;
    for (auto& v: gr[u]) {
        if (v == p) continue;
        dfs_count_child(v, u);
        cnt_child[u] += cnt_child[v];
        if (gr[u][0] == p or cnt_child[v] > cnt_child[gr[u][0]]) swap(gr[u][0], v);
    }
}

ll ans[maxn];
void dfs(int u, int p) {
    for (auto& v: gr[u]) {
        if (v == gr[u][0] or v == p) continue;
        dfs(v, u);
        add_col(v, u, -1);
        mx_col = 0;
        sum_col = 0;
    }
    if (gr[u].size() and gr[u][0] != p) dfs(gr[u][0], u);
    inc_col(c[u], 1);
    for (auto& v: gr[u]) {
        if (v == gr[u][0] or v == p) continue;
        add_col(v, u, 1);
    }
    ans[u] = sum_col;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> c[i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs_count_child(1, 1);
    dfs(1, 1);
    rep(i, 1, n + 1) cout << ans[i] << ' ';
    
    
    return 0;
}

// vim: foldmethod=marker