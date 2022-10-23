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
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##=(const type& o)
template<int mod>
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_): x(int(x_ % mod)) {}
    defop(modint, +) { return ((x += o.x) >= mod and (x -= mod)), *this; }
    defop(modint, -) { return ((x -= o.x) < 0 and (x += mod)), *this; }
    defop(modint, *) { return *this = modint(1ll * x * o.x); }
    defop(modint, /) { return *this *= o.pow(mod - 2); }
    modint pow(ll exp) const {
        modint ans = 1, base = * this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<998'244'353>;


ld brute(int n, int mask) {
    static map<pair<int, int>, ld> dp;
    auto [it, is_new] = dp.try_emplace({n, mask}, 0);
    if (!is_new) return it->second;
    int cnt1 = __builtin_popcount(mask);
    int cnt0 = n - cnt1;
    bool is_sorted = true;
    rep(i, 0, cnt0) {
        if ((mask >> i) & 1) {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted) {
        return it->second = 0;
    }
    
    int back_cases = 0;
    ld t = 0;
    rep(i, 0, n) {
        int u = (mask >> i) & 1;
        rep(f, i + 1, n) {
            int v = (mask >> f) & 1;
            if (u > v) {
                t += brute(n, mask ^ (1 << i) ^ (1 << f));
            } else {
                ++back_cases;
            }
        }
    }
    
    ld total = (ld)n * (n - 1) / 2;
    clog << db(n) << db(mask) << db(t) << db(total) << db(back_cases) << db(t) << endl;
    return it->second = (t / total + 1.) / (1. - ld(back_cases) / total);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    // rep(len, 1, 10) {
        // DB();
        // cout << db(len) << endl;
        // rep(mask, 0, (1 << len)) {
            // auto ans = brute(len, mask);
            // cout << bitset<10>(mask) << ' ' << ans << endl;
        // }
    // }
    // return 0;
    
    int ntest;
    cin >> ntest;
    
    while (ntest--) {
        int n;
        cin >> n;
        int cnt1 = 0;
        vector<int> a(n);
        rep(i, 0, n) {
            cin >> a[i];
            cnt1 += a[i];
        }
        
        int cnt0 = n - cnt1;
        int cnt_wrong = 0;
        rep(i, 0, cnt0) {
            cnt_wrong += a[i];
        }
        
        mint dp = 0;
        mint total = mint(n) * mint(n - 1) / 2;
        rep(i, 1, cnt_wrong + 1) {
            mint way_reduce = mint(i) * i;
            mint new_dp = (dp * way_reduce + total) / way_reduce;
            dp = new_dp;
        }
        cout << dp << '\n';
    }
    
    return 0;
}