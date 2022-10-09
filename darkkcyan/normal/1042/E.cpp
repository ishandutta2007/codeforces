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
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
template<int mod>
struct modint {
    static constexpr int mod_ = mod;
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
const int maxn = 1010;
int n, m;
int a[maxn][maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n) rep(f, 0, m) cin >> a[i][f];
    
    int r, c; cin >> r >> c;
    --r;
    --c;
    
    map<int, vector<pair<int, int>>> groups;
    rep(i, 0, n) rep(f, 0, m) groups[a[i][f]].emplace_back(i, f);
    
    if (a[r][c] == groups.begin()->first) {
        cout << "0\n";
        return 0;
    }
    mint free_term = 0, u = 0, v = 0;
    int cnt_smaller = 0;
    for (auto [i, f]: groups.begin()->second) {
        free_term += mint(i) * i + mint(f) * f;
        u += i;
        v += f;
        ++cnt_smaller;
    }
    groups.erase(groups.begin());
    clog << db(free_term) << db(u) << db(v) << db(cnt_smaller) << endl;
    mint ans;
    for (auto [value, cells]: groups) {
        DB();
        clog << db(value) << endl;
        mint new_free, nu, nv;
        mint inv_cnt = mint(1) / cnt_smaller;
        bool has_ans = false;
        for (auto [i, f]: cells) {
            DB();
            clog << db(i) << db(f) << endl;
            auto cur = (free_term - 2 * i * u - 2 * f * v) * inv_cnt;
            auto sq = mint(i) * i + mint(f) * f;
            clog << db(cur) << db(sq) << endl;
            if (i == r and f == c) {
                ans = cur + sq;
                has_ans = true;
                break;
            }
            new_free += cur + sq * 2;
            nu += i;
            nv += f;
        }
        if (has_ans) break;
        clog << db(new_free) << db(nu) << db(nv) << endl;
        free_term += new_free;
        u += nu;
        v += nv;
        cnt_smaller += sz(cells);
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker