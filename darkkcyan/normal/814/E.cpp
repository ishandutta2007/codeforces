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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

#define def_op(type, op)\
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op##= (const type& o) 
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx= 0): x(xx) {}
    modint(ll xx) : x((int)(xx % mod)) {}
    def_op(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    def_op(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    def_op(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    modint pow(ll exp) const {
        modint base = *this, ans = 1;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    def_op(modint, /) {
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;
const int maxn = 52;

int n;
int d[maxn];

const int maxval = maxn * 3;
mint choose[maxval][maxval];
mint fac[maxval], ifac[maxval];
void precal() {
    rep(i, 0, maxval) {
        choose[i][0] = 1;
        rep(f, 1, i + 1)
            choose[i][f] = choose[i - 1][f] + choose[i - 1][f - 1];
    }
    fac[0] = 1;
    rep(i, 1, maxval) fac[i] = fac[i - 1] * i;
    ifac[maxval - 1] = 1 / fac[maxval - 1];
    for (int i = maxval; i-- > 1; ) {
        ifac[i - 1] = ifac[i] * i;
    }
}

mint dp[2][maxn][maxn][maxn][maxn];

void print_dp(int l) {
    DB();
    rep(p1, 0, n + 1) 
    rep(p2, 0, n + 1 - p1) 
    rep(c1, 0, n + 1 - p1 - p2) 
    rep(c2, 0, n + 1 - p1 - p2 - c1) {
        auto cur = dp[l][p1][p2][c1][c2];
        if (!cur.x) continue;
        clog << db(p1) << db(p2) << db(c1) << db(c2) << db(cur) << endl;
    }
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> d[i];
    dp[0][d[0]][0][0][0] = 1;
    
    rep(i, 1, n) {
        clog << db(i) << endl;
        print_dp(!(i & 1));
        auto& cdp = dp[i & 1];
        auto& pdp = dp[!(i & 1)];
        rep(p1, 0, n + 1) 
        rep(p2, 0, n + 1 - p1) 
        rep(c1, 0, n + 1 - p1 - p2) 
        rep(c2, 0, n + 1 - p1 - p2 - c1) {
            auto& cur = pdp[p1][p2][c1][c2];
            if (cur.x == 0) continue;
            if (p1 == 0 and p2 == 0) pdp[c1][c2][0][0] += cur;
            auto upd = [&](int np1, int np2, int par_way) {
                if (d[i] == 2) {
                    cdp[np1][np2][c1 + 1][c2] += cur * par_way;
                    if (c1)
                        cdp[np1][np2][c1 - 1][c2] += cur * c1 * par_way;
                    if (c2)
                        cdp[np1][np2][c1 + 1][c2 -1] += cur * c2 * par_way;
                } else {
                    cdp[np1][np2][c1][c2 + 1] += cur * par_way;
                    if (c1) 
                        cdp[np1][np2][c1][c2] += cur * c1 * par_way;
                    if (c2) 
                        cdp[np1][np2][c1 + 2][c2 - 1] += cur * c2 * par_way;
                    if (c1 >= 2)
                        cdp[np1][np2][c1 - 2][c2] += cur * choose[c1][2] * par_way;
                    if (c1 and c2)
                        cdp[np1][np2][c1][c2 - 1] += cur * c1 * c2 * par_way;
                    if (c2 >= 2)
                        cdp[np1][np2][c1 + 2][c2 - 2] += cur * choose[c2][2] * par_way;
                }
            };
            if (p1) upd(p1 - 1, p2, p1);
            if (p2) upd(p1 + 1, p2 - 1, p2);
            cur = 0;
        }
    }
    clog << db(n - 1) << endl;
    print_dp((n - 1) & 1);
    cout << dp[(n - 1) & 1][0][0][0][0] / fac[d[0]];
    
    return 0;
}

// vim: foldmethod=marker