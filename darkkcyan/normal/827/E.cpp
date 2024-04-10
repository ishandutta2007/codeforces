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
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_): x(int(x_ % mod)) {}
    
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

using mint = modint<998'244'353>;
const mint primitive_root = mint(3).pow(7 * 17);
const mint inv_primitive_root = mint(1) / primitive_root;
const ll root_pw = 1ll << 23;

int inv_inc(int num, int len) {
    for (int i = len; i--; ) {
        num ^= 1 << i;
        if ((num >> i) & 1) break;
    }
    return num;
}

template<bool is_inv>
void ntt(vector<mint>& a) {
    int lg = 32 - __builtin_clz(sz(a) - 1);
    a.resize(1 << lg, 0);
    
    for (int u = 0, v = 0; u < sz(a); ++u, v = inv_inc(v, lg)) {
        if (u < v) swap(a[u], a[v]);
    }
    
    const mint w = is_inv ? inv_primitive_root : primitive_root;
    for (int step = 2; step <= sz(a); step <<= 1) {
        int hs = step >> 1;  // half step
        mint w_len = w.pow(root_pw / step);
        for (int group = 0; group < sz(a); group += step) {
            mint cur_w = 1;
            for (int i = 0, f = hs; i < hs; ++i, ++f) {
                auto u = a[i + group], v = a[f + group] * cur_w;
                a[i + group] = u + v;
                a[f + group] = u - v;
                cur_w *= w_len;
            }
        }
    }
    
    if constexpr (is_inv) {
        const auto inv_n = mint(1) / sz(a);
        for (auto& i: a) i *= inv_n;
    }
}

vector<mint> mul(vector<mint> a, vector<mint> b) {
    int mx_size = 2 * (int)max(a.size(), b.size());
    a.resize(mx_size);
    b.resize(mx_size);
    ntt<false>(a);
    ntt<false>(b);
    for (auto i: views::iota(0, sz(b))) {
        a[i] *= b[i];
    }
    
    ntt<true>(a);
    return a;
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
        DB();
        int n;
        string s;
        cin >> n >> s;
        vector<mint> vpos(n), kpos(n);
        for (auto i: views::iota(0, n)) {
            if (s[i] == 'V') vpos[i] = 1;
            if (s[i] == 'K') kpos[n - i - 1] = 1;
        }
        clog << db(vpos) << endl;
        clog << db(kpos) << endl;
        
        auto x = mul(vpos, kpos);
        clog << db(x) << endl;
        
        auto xp = x.begin() + n - 1;
        vector<int> ans;
        for (auto i: views::iota(1, n)) {
            bool ok = true;
            for (int multiple = i; multiple < n; multiple += i) {
                if (xp[multiple].x > 0 or xp[-multiple].x > 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
        ans.push_back(n);
        cout << sz(ans) << '\n';
        for (auto i: ans) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}