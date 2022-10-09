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
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
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
};

using mint = modint<998'244'353>;

const int maxn = 10101010;

mint fac[maxn], ifac[maxn];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = 1 / fac[maxn - 1];
    for (int i = maxn - 1; i--; ) 
        ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int n, int k) {
    if (k < 0 or n < k) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
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
    // s = string(2000, '?'); 
    int n = sz(s);
    
    mint ans = 0;
    
    vector<mint> dp(n + 1);
    
    rep(sep, 0, n - 1) {
        int left_o = (int)count(s.begin(), s.begin() + sep + 1, '(');
        int left_ques = (int)count(s.begin(), s.begin() + sep + 1, '?');
        int right_c = (int)count(s.begin() + sep + 1, s.end(), ')');
        int right_ques = (int)count(s.begin() + sep + 1, s.end(), '?');
        
        rep(depth, 1, n + 1) {
            if (depth < left_o or depth < right_c) continue;
            auto cur_ans = choose(left_ques, depth - left_o) * choose(right_ques, depth - right_c);
            dp[depth] += cur_ans;
        }
    }
    
    for (int i = n + 1; i--; ) {
        // if (i < n) dp[i] -= dp[i + 1]; 
        ans += dp[i] * i;
    }
    cout << ans.x;
    
    return 0;
}

// vim: foldmethod=marker