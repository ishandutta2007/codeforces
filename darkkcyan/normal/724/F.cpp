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
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
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
    friend inline type operator op(type u, const type& v) { return u op##= v; }\
    type& operator op##=(const type& o)

int mod;
// template<int mod_> 
struct modint {
    // static constexpr int mod = mod_;  
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    defop(modint, + ) {
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
    modint pow(ll exp, modint ans = 1) const {
        modint base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) {
        return *this = o.pow(mod - 2, *this);
    }
    friend print_op(modint) { return out << u.x; }
};

using mint = modint;
const int maxn = 1024;
const int maxd = 16;
mint dp[maxn][maxd][maxn];
mint ifac[maxd];
void precal() {
    ifac[0] = 1;
    rep(i, 1, maxd) ifac[i] = ifac[i - 1] / i;
}

int n, d;
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d >> mod;
    precal();
    if (n == 1) {
        cout << "1";
        return 0;
    }
    
    // rep(deg, 0, d) dp[1][deg][0] = 1; 
    dp[1][0][0] = 1;  
    dp[1][d - 1][0] = 1;   
    rep(treesize, 2, n + 1) {
        DB();
        clog << db(treesize) << endl;
        rep(root_deg, 0, d + 1) {
            rep(max_sub_size, 1, treesize) {
                DB();
                clog << db(root_deg) << db(max_sub_size) << endl;
                auto& cur = dp[treesize][root_deg][max_sub_size];
                cur += dp[treesize][root_deg][max_sub_size - 1];
                auto u = max_sub_size > 1 ? dp[max_sub_size][d - 1][max_sub_size - 1] : 1;
                clog << db(u) << endl;
                mint cur_mul = 1;
                rep(cur_sub, 1, root_deg + 1) {
                    cur_mul *= (u + cur_sub - 1);
                    int new_size = treesize - cur_sub * max_sub_size;
                    if (new_size <= 0) break;
                    clog << db(new_size) << db(root_deg - cur_sub) << endl;
                    auto comb = cur_mul * ifac[cur_sub];
                    auto rest = dp[new_size][root_deg - cur_sub][min(new_size, max_sub_size) - 1];
                    clog << db(cur_sub) << db(comb.x) << db(rest) << endl;
                    cur += rest * comb;
                }
                clog << db(cur) << endl;
            }
        }
    }
    
    auto ans = dp[n][d][(n - 1) / 2];
    if (n % 2 == 0) {
        auto t = dp[n / 2][d - 1][n / 2 - 1];
        ans += t * (t + 1) * ifac[2];
    }
    cout << ans.x;
    
    return 0;
}

// vim: foldmethod=marker