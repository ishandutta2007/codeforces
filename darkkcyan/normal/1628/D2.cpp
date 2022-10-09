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
    type& operator op##= (const type& o)
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
        return *this = modint(1ll * x * o.x);
    }
    
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
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

using mint = modint<(int)1e9 + 7>;

const int maxn = (int)1e6 + 10;
int n, m, k;
// ld dp[maxn][maxn];
// mint dp[maxn][maxn];
// int vis[maxn][maxn];
int timer;

const mint inv2 = mint(1) / 2;
// const ld inv2 = 0.5;

const int maxfac = maxn * 2;
mint fac[maxfac], ifac[maxfac];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxfac) fac[i] = fac[i - 1] * i;
    ifac[maxfac - 1] = 1 / fac[maxfac - 1];
    for (int i = maxfac - 2; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int N, int K) {
    if (N < K or K < 0) return 0;
    return fac[N] * ifac[K] * ifac[N - K];
}

// ld solve() {
mint solve() { 
    mint ans = 0;
    for (int val = m, i = 0; val > 0; --val, ++i) {
        ans += choose(n, i) * val;
    }
    ans *= inv2.pow(n - 1);
    ans *= k;
    return ans;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
void check() {
    cout << "test" << endl;
    n = rand(1, 1000);
    m = rand(1, n);
    k = rand(1, 100);
    solve();
}

int main() {
    precal();
    // while (1) check();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m >> k;
        cout << solve() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker