#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

const int maxn = 201010;
int n;
int h[maxn];
vector<int> gr[maxn];

ll submax[maxn];

ll ans;
void dfs(int u, int p) {
    submax[u] = sz(gr[u]) == 1 ? h[u] : 0;
    if (sz(gr[u]) == 1) ans += h[u];
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        submax[u] = max(submax[u], submax[v]);
    }
    if (submax[u] < h[u]) {
        ans -= submax[u];
        submax[u] = h[u];
        ans += h[u];
    }
    if (u == p) {
        ll first_max = 0, sec_max = 0;
        for (auto v: gr[u]) {
            ll t = submax[v];
            if (t > first_max) swap(t, first_max);
            sec_max = max(t, sec_max);
        }
        if (sz(gr[u]) == 1) {
            ll t = h[u];
            if (t > first_max) swap(t, first_max);
            sec_max = max(t, sec_max);
        }
        if (sec_max < h[u]) {
            ans -= sec_max;
            ans += h[u];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> h[i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    int root = (int)(max_element(h + 1, h + n + 1) - h);
    ans = 0;
    dfs(root, root);
    cout << ans;
    
    
    return 0;
}

// vim: foldmethod=marker