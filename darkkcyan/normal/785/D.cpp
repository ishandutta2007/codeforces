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

#define def_op(type, op) \
    friend type operator op(type u, const type& v) { return u op##= v; } \
    type& operator op ##= (const type& o)
template<int mod>
struct mod_int {
    int x;
    mod_int(int xx= 0): x(xx) {}
    mod_int(ll xx): x((int)(xx % mod)) {}
    
    def_op(mod_int, +) {
        if ((x += o.x) >= mod) x-= mod;
        return *this;
    }
    
    def_op(mod_int, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    
    def_op(mod_int, *) { return *this = mod_int(1ll * x * o.x); }
    
    mod_int pow(ll exp) const {
        mod_int base = *this, ans =1;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    
    def_op(mod_int, /) { return *this *= o.pow(mod - 2); }
};

using mint = mod_int<(int)1e9 + 7>;
const int maxn = 401010;
mint fac[maxn], ifac[maxn];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = 1 / fac[maxn - 1];
    for (int i = maxn - 2; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int n, int k) {
    if (n < 0 or k < 0 or n < k) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

mint distribute(int a, int b) {
    return choose(a + b, a);
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s; 
    cin >> s;
    
    vector<int> sum(sz(s) + 1);
    rep(i, 0, sz(s))
        sum[i + 1] = sum[i] + (s[i] == '(');
    
    mint ans = 0;
    rep(i, 0, sz(s)) {
        if (s[i] == ')') continue;
        int open = sum[i + 1];
        int close = (sz(s) - i - 1) - (sum[sz(s)] - sum[i + 1]);
        clog << db(i) << db(open) << db(close) << endl;
        ans += distribute(open, close) - distribute(open - 1, close);
    }
    
    cout << ans.x;
    
    return 0;
}

// vim: foldmethod=marker