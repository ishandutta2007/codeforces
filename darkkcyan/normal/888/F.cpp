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
    inline friend type operator op (type u, const type& v) { return u op ##= v; } \
    type&  operator op ##= (const type& o) 
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this= modint(1ll * x * o.x);
    }
    
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;
const int maxn = 555;
int n;
int gr[maxn][maxn];

bool vis[maxn][maxn][2];
mint dp[maxn][maxn][2];

mint cal_dp(int u, int v, bool u_connectable) {
    auto& ans = dp[u][v][u_connectable];
    if (vis[u][v][u_connectable]) {
        return ans;
    }
    DB();
    vis[u][v][u_connectable] = true;
    int len = (v - u + n + 1);
    if (len > n) len -= n;
    clog << db(u) << db(v) << db(len) << endl;
    if (len == 0) return ans = 0;
    if (len == 1) return ans = 1;
    if (len == 2) return ans = 1;
    ans = 0;
    rep(i, 1, len - 1) {
        int t = (u + i) % n;
        if (u_connectable and gr[u][t]) {
            auto x = cal_dp(u, t, 1);
            auto y = cal_dp(t, v, 1);
            ans += x * y;
        }
        if (gr[v][t]) {
            auto x = cal_dp(u, t, 0);
            auto y = cal_dp(t, v, 1);
            ans += x * y;
        }
    }
    clog << db(u) << db(v) << db(u_connectable) << db(ans) << endl;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n)
        rep(f, 0, n)
        cin >> gr[i][f];
    
    mint ans = 0;
    rep(i, 1, n) {
        if (!gr[0][i]) continue;
        DB();
        auto x = cal_dp(0, i, 0);
        auto y = cal_dp(i, 0, 1);
        clog << db(i) << db(x) << db(y) << db(x * y) << endl;
        ans += x * y;
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker