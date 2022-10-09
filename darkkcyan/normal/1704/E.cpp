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
 
#define defop(type, op) \
    friend inline type  operator op(type u, const type& v) { return u op ##= v; }  \
    type& operator op ##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x-= mod;
        return *this;
    }
    
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<998'244'353>;

mint solve() {
    DB();
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vector<int>> gr(n + 1);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }
    
    rep(time, 0, n + 1) {
        vector<int> pos;
        rep(i, 1, n + 1) if (a[i]) pos.push_back(i);
        if (pos.size() == 0) return time;
        for (auto u: pos) {
            --a[u];
            for (auto v: gr[u]) ++a[v];
        }
    }
    
    vector<mint> way(n + 1);
    vector<bool> vis(n + 1);
    function<mint(int)> dfs = [&](int u) {
        if (vis[u]) return way[u];
        vis[u] = true;
        if (gr[u].size() == 0) {
            return way[u] = 1;
        }
        for (auto v: gr[u]) {
            way[u] += dfs(v);
        }
        return way[u];
    };
    
    clog << db(a) << endl;
    mint ans = n + 1;
    rep(i, 1, n + 1) {
        ans += mint(a[i]) * dfs(i);
    }
    clog << db(way) << endl;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cout << solve() << '\n';
    }
    
    return 0;
}