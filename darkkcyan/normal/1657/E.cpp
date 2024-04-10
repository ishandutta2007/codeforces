#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main
 
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
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
template<int mod>
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    
    modint pow(ll exp) const {
        modint base = *this, ans = 1;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    
    defop(modint, /) {
        return *this *= o.pow(mod - 2);
    }
    
    friend print_op(modint) {
        return out << u.x;
    }
};
using mint = modint<(int)998'244'353>;

const int maxn = 256;
const int max_fac = 2 * maxn;
mint fac[max_fac], ifac[max_fac];
void precal() {
    fac[0] = 1;
    rep(i, 1, max_fac)
        fac[i] = i * fac[i - 1];
    ifac[max_fac - 1] = 1 / fac[max_fac - 1];
    for (int i = max_fac - 1; i--;)
        ifac[i] = (i + 1) * ifac[i + 1];
}

mint choose(int n, int k) {
    if (k < 0 or n < k) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

int n, k;
mint dp[maxn][maxn];

int jalsol_orz() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    rep(col, 0, k + 1) dp[0][col] = 1;
    rep(i, 1, n) {
        int cnt_edges = i * (i + 1) / 2;
        dp[i][1] = mint(k).pow(cnt_edges - i);
        rep(col, 2, k + 1) {
            rep(picked, 0, i + 1) {
                int remain = i - picked;
                int new_edges = picked * remain + picked * (picked - 1) / 2;
                auto way_picked = choose(i, picked);
                auto way_color_new_edges = mint(k - col + 1).pow(new_edges);
                clog << db(i) << db(col) << db(picked) << db(remain) << db(way_picked) << db(way_color_new_edges) << endl;
                dp[i][col] += dp[remain][col - 1] * way_picked * way_color_new_edges;
            }
        }
    }
    rep(i, 1, n) rep(col, 1, k + 1)
        clog << db(i) << db(col) << db(dp[i][col]) << endl;
    
    cout << dp[n - 1][k];
    
    return 0;
}