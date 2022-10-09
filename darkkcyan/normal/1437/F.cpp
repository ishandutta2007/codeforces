#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

const int maxn = 5555;
template<int mod>
struct mod_int {
    int x;
    mod_int(int x_ = 0): x(x_) {}
    mod_int(ll x_): x((int)(x_ % mod)) {}
    
#define def_op(op, uop)\
    inline mod_int& operator uop (mod_int other) { return *this = *this op other; } \
    friend inline mod_int operator op(mod_int u, mod_int v)
    
    def_op(+, +=) {
        if ((u.x += v.x) >= mod) u.x -= mod;
        return u;
    }
    def_op(-, -= ) {
        if ((u.x -= v.x) < 0) u.x += mod;
        return u;
    }
    def_op(*, *=) { return 1ll * u.x * v.x; }
    
    friend ostream& operator<<(ostream& out, mod_int u) { return out << u.x; }
};

using mint = mod_int<998'244'353>;

mint choose[maxn][maxn];
void preprocess() {
    rep(i, 0, maxn) {
        choose[i][0] = 1;
        rep(f, 1, i + 1) 
            choose[i][f] = choose[i - 1][f] + choose[i - 1][f - 1];
    }
}

int main() {
    preprocess();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    vector<vector<mint>> dp_sum(n + 1, vector<mint>(n + 1));
    
    dp[0][0] = dp_sum[0][0] = 1;
    
    clog << db(dp[0]) << endl;
    clog << db(dp_sum[0]) << endl;
    
    rep(i, 0, n) {
        DB();
        clog << db(i) << endl;
        int prev_smaller = i - 1;
        
        while (prev_smaller >= 0 and a[prev_smaller] * 2 > a[i]) --prev_smaller;
        clog << db(prev_smaller) << endl;
        
        rep(f, 0, i + 1) {
            dp[i + 1][f + 1] += dp_sum[prev_smaller + 1][f];
        }
        
        int max_pickable = prev_smaller + 2;
        clog << db(max_pickable) << endl;
        rep(f, 0, max_pickable) {
            dp[i + 1][f + 1] += dp[i + 1][f] * (max_pickable - f);
        }
        
        rep(f, 0, n + 1) {
            dp_sum[i + 1][f] = dp_sum[i][f] + dp[i + 1][f];
        }
        
        clog << db(dp[i + 1]) << endl;
        clog << db(dp_sum[i + 1]) << endl;
    }
    
    cout << dp[n][n];
    
    return 0;
}

// vim: foldmethod=marker