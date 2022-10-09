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
    friend inline type operator op(type u, const type & v) { return u op ##= v; } \
    type& operator op##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx) : x((int)(xx % mod)) {}
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
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;
const int maxn = 15;
int n;
mint a[maxn];
mint sum[maxn][maxn], isum[maxn][maxn];

mint win_prob(int u, int v) {
    return a[u] * isum[u][v];
}

mint prob_comp[1 << maxn];
mint prob_win_all[maxn][1 << maxn];

mint cal_prob_subcomp(int cur, int other) {
    mint ans = prob_comp[cur];
    rep(i, 0, n) {
        if (!((cur >> i) & 1)) continue;
        ans *= prob_win_all[i][other];
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    clog << mint(10) / 63;
    rep(i, 0, n) {
        cin >> a[i].x;
    }
    rep(i, 0, n) rep(f, 0, n) {
        sum[i][f] = a[i] + a[f];
        isum[i][f] = mint(1) / sum[i][f];
        // clog << db(i) << db(f) << db(sum[i][f]) << db(isum[i][f]) << db(sum[i][f] * isum[i][f]) << endl; 
    }
    
    rep(i, 0, n) rep(mask, 0, (1 << n)) {
        if ((mask >> i) & 1) continue;
        prob_win_all[i][mask] = 1;
        rep(f, 0, n) {
            if (!((mask >>f) & 1)) continue;
            prob_win_all[i][mask] *= win_prob(i, f);
        }
    }
    
    rep(comp_mask, 1, (1 << n)) {
        DB();
        clog << db(comp_mask) << endl;
        int sub = comp_mask;
        prob_comp[comp_mask] = 1;
        for (sub = (sub - 1) & comp_mask; sub > 0; sub = (sub - 1) & comp_mask) {
            auto x = cal_prob_subcomp(sub, comp_mask ^ sub);
            clog << db(sub) << db(x) << endl;
            prob_comp[comp_mask] -= x;
        }
        clog << db(comp_mask) << db(prob_comp[comp_mask]) <<endl;
    }
    
    mint ans = 0;
    int all1 = (1 << n) - 1;
    rep(comp_mask, 0, (1 << n)) {
        int cnt = __builtin_popcount(comp_mask);
        ans += cnt * cal_prob_subcomp(comp_mask, all1 ^ comp_mask);
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker