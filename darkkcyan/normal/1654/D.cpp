#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main
 
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
    modint(ll x_): x((int)(x_ % mod)) {}
    
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
        auto base = *this;
        modint ans = 1;
        for (; exp > 0; exp >>= 1, base *= base)
            if( exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) {
        return *this *= o.pow(mod - 2);
    }
};
using mint = modint<998'244'353>;

struct Edge {
    int to;
    int x, y;
};

const int maxn = 201010;
int n;
vector<Edge> gr[maxn];

mint ans, coef;

int pdiv[maxn];
void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (pdiv[i]) continue;
        for (int f = i; f < maxn; f += i) pdiv[f] = i;
    }
}

map<int, int> cnt_pdiv, max_pdiv;
void dfs1(int u, int par) {
    DB();
    clog << db(u) << endl;
    for (auto [v, x, y]: gr[u]) {
        if (v == par) continue;
        clog << db(v) << db(x) << db(y) << endl;
        vector<pair<int, int>> used_p;
        while (x > 1) {
            int p = pdiv[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            auto& t = cnt_pdiv[p];
            used_p.emplace_back(p, t);
            cnt_pdiv[p] += cnt;
        }
        while (y > 1) {
            int p = pdiv[y];
            int cnt = 0;
            while (y % p == 0) {
                y /= p;
                ++cnt;
            }
            auto& t = cnt_pdiv[p];
            used_p.emplace_back(p, t);
            cnt_pdiv[p] -= cnt;
        }
        for (auto [p, t]: used_p) {
            max_pdiv[p] = max(max_pdiv[p], cnt_pdiv[p]);
        }
        clog << db(cnt_pdiv) << db(max_pdiv) << endl;
        dfs1(v, u);
        reverse(all(used_p));
        for (auto [p, t]: used_p) {
            cnt_pdiv[p] = t;
        }
    }
}

void dfs2(int u, int p, mint down = 1) {
    clog << db(u) << db((down * coef) .x) << endl;
    ans += coef * down;
    for (auto [v, x, y]: gr[u]) {
        if (v == p) continue;
        dfs2(v, u, down * y / x);
    }
}

int jalsol_orz() {
    sieve();
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
        cin >> n;
        rep(i, 0, n + 1) {
            gr[i].clear();
        }
        rep(i, 0, n - 1) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            gr[u].push_back({v, x, y});
            gr[v].push_back({u, y, x});
        }
        
        ans = 0;
        cnt_pdiv.clear();
        max_pdiv.clear();
        dfs1(1, 1);
        coef = 1;
        clog << db(max_pdiv) << endl;
        for (auto [p, cnt]: max_pdiv) {
            coef *= mint(p).pow(cnt);
        }
        clog << db(coef.x) << endl;
        dfs2(1, 1);
        cout << ans.x << '\n';
    }
    
    
    return 0;
}