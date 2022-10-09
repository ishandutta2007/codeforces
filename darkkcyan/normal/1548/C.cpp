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
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0) : x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
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
    
    modint pow(ll exp) const {
        modint base = *this, ans = 1;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) {
        if (o.x == 1) return *this;
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
    friend bool operator==(modint u, modint v) {
        return u.x == v.x;
    }
};

using mint = modint<(int)1e9 + 7>;
const int maxn = 1010100;
const int maxval = 3 * maxn;
mint fac[maxval], ifac[maxval];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxval) fac[i] = fac[i - 1] * i;
    ifac[maxval - 1] = 1 / fac[maxval - 1];
    for (int i = maxval - 1; i--; )
        ifac[i] = ifac[i + 1] * (i  + 1);
}

mint choose(int n, int k) {
    if (n < k or k < 0) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

void find_pattern() {
    rep(n, 1, 10 + 1) {
        DB();
        clog << db(n) << endl;
        vector<mint> ans = {0};
        rep(x, 1, 3 * n + 1) {
            mint cur_ans = 0;
            rep(j, 1, n + 1) {
                cur_ans += choose(3 * j, x);
            }
            ans.push_back(cur_ans);
        }
        clog << db(ans) << endl;
        auto t = ans;
        for (auto& i: t) i /= 3;
        clog << db(t) << endl;
        clog << db(accumulate(all(ans), mint(0))) << endl;
    }
}

struct Poly {
    vector<mint> coef;
    Poly(size_t deg = 0) : coef(deg + 1, 0) {}
    Poly(initializer_list<mint> li): coef(li) {
        if (coef.size() == 0) coef.push_back(0);
    }
    mint& operator[](size_t i) { return coef[i]; }
    mint operator[](size_t i) const { return coef[i]; }
    static Poly binom(size_t deg) {
        Poly ans(deg);
        rep(i, 0, deg + 1) ans.coef[i] = choose((int)deg, i);
        return ans;
    }
    
    size_t deg() const {
        assert(sz(coef) >= 1);
        return coef.size() - 1;
    }
    
    Poly& norm() {
        while (sz(coef) > 1 and coef.back() == 0) coef.pop_back();
        return *this;
    }
    
    defop(Poly, +) {
        coef.resize(max(deg(), o.deg()) + 1);
        rep(i, 0, o.deg() + 1) coef[i] += o[i];
        return norm();
    }
    defop(Poly, -) {
        coef.resize(max(deg(), o.deg()) + 1);
        rep(i, 0, o.deg() + 1) coef[i] -= o[i];
        return norm();
    }
    
    defop(Poly, /) { 
        Poly res(max(deg() - o.deg(), size_t()));
        for (int i = (int)deg(); i >= (int)o.deg(); --i) {
            auto t = coef[i] / o[o.deg()];
            res[i - o.deg()] = t;
            rep(f, 0, o.deg() + 1) {
                coef[i - o.deg() + f] -= t * o[f];
            }
        }
        
        swap(*this, res);
        clog << db(res) << endl;
        return norm();
    }
    
    friend print_op(Poly) {
        return out << u.coef;
    }
};

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    // find_pattern(); 
    int n, q; cin >> n >> q; 
    
    auto u = Poly::binom(3 * n + 3);
    auto v = Poly::binom(3);
    clog << db(u) << endl;
    clog << db(v) << endl;
    auto t = u - v;
    clog << db(t) << endl;
    auto ans = t / (v - Poly{1});
    clog << db(ans) << endl;
    
    while (q--) {
        int x; cin >> x;
        if (x > (int)ans.deg()) cout << "0\n";
        else cout << ans[x] << '\n';
    }
    
    
    return 0;
}

// vim: foldmethod=marker