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
    type& operator op ##= (const type& o) 
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
    defop(modint, * ) {
        return *this = modint(1ll * x * o.x);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<998'244'353>;

using Config = array<int, 26>;
Config combine(Config u, const Config& v) {
    rep(i, 0, 26) u[i] = min(u[i], v[i]);
    return u;
}

const int inf = 1e5;

mint mul_elm(const Config& u) {
    mint ans = 1;
    for (auto i: u) ans *= i + 1;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<Config> s(n);
    for (auto& i: s) {
        string t;
        cin >> t;
        int cur = 0;
        rep(f, 0, 26) {
            i[f] = 0;
            while (cur < sz(t) and t[cur] == char('a' + f)) {
                ++i[f];
                ++cur;
            }
        }
    }
    
    vector<Config> all_conf(1 << n);
    all_conf[0].fill(inf);
    rep(mask, 1, (1 << n)) {
        int bit = __builtin_ctz(mask);
        int sub = mask ^ (1 << bit);
        all_conf[mask] = combine(s[bit], all_conf[sub]);
    }
    
    rep(mask, 0, (1 << n)) {
        clog << db(mask) << db(all_conf[mask]) << endl;
    }
    
    vector<mint> ans(1 << n);
    rep(mask, 1, (1 << n)) {
        ans[mask] = mul_elm(all_conf[mask]);
        if (!__builtin_parity(mask)) ans[mask] = 0 - ans[mask];
    }
    clog << db(ans) << endl;
    rep(bit, 0, n) {
        rep(i, 0, (1 << n)) {
            if ((i >> bit) & 1) {
                ans[i] += ans[i ^ (1 << bit)];
            }
        }
    }
    clog << db(ans) << endl;
    
    ll true_ans = 0;
    rep(mask, 1, (1<< n)) {
        mint cur = ans[mask];
        ll cur_ans = cur.x;
        int cnt_bit = 0;
        int sum_bit = 0;
        rep(bit, 0, n) {
            if ((mask >> bit) & 1) {
                sum_bit += bit + 1;
                ++cnt_bit;
            }
        }
        cur_ans *= cnt_bit * sum_bit;
        clog << db(mask) << db(cur) << db(cnt_bit) << db(sum_bit) << db(cur_ans) << endl;
        true_ans ^= cur_ans;
    }
    cout << true_ans;
    
    
    return 0;
}

// vim: foldmethod=marker