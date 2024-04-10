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

#define defop(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x(int(xx % mod)) {}
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

using mint = modint<(int)1e9 + 7>;
const int maxn = 101010;
const int maxx = 11;
int n, m, k, x;
vector<int> gr[maxn];

mint dp[maxn][3][maxx];
void dfs(int u, int p) {
    DB();
    dp[u][0][0] = k - 1;
    dp[u][1][1] = 1;
    dp[u][2][0] = m - k;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        array<mint, maxx> tmp[3];
        rep(i, 0, 3) tmp[i].fill(0);
        rep(u_lab, 0, 3) rep(v_lab, 0, 3) {
            if (u_lab == 1 and v_lab != 0) continue;
            if (v_lab == 1 and u_lab != 0) continue;
            rep(u1, 0, x + 1) rep(v1, 0, x + 1) {
                if (u1 + v1 > x) break;
                tmp[u_lab][u1 + v1] += dp[u][u_lab][u1] * dp[v][v_lab][v1];
            }
        }
        rep(lab, 0, 3) rep(one, 0, x + 1) 
            dp[u][lab][one] = tmp[lab][one];
    }
    clog << db(u) << endl;
    rep(lab, 0,3 ) rep(one, 0, x + 1) {
        clog << db(lab) << db(one) << db(dp[u][lab][one]) << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1, 1);
    mint ans = 0;
    rep(lab, 0, 3) rep(one, 0, x + 1) ans += dp[1][lab][one];
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker