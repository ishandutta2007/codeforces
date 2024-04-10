#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
// DEBUGING TEMPLETE
// ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define clog                                                                   \
    if (0) cerr
#define DB(...)
#endif

template <class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T>
ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value) return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

#define defop(type, op)                                                        \
    friend inline type operator op(type u, const type &v) {                    \
        return u op## = v;                                                     \
    }                                                                          \
    type &operator op##=(const type &o)

template <int mod> struct modint {
    int x;
    modint(int x_ = 0) : x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}
    defop(modint, +) { return ((x += o.x) >= mod) && (x -= mod), *this; }
    defop(modint, -) { return ((x -= o.x) < 0) && (x += mod), *this; }
    defop(modint, *) { return *this = modint(1ll * x * o.x); }
    auto operator<=>(const modint &o) const = default;
    friend print_op(modint) { return out << u.x; }
};

template <class U, int mV> struct HashInt {
    U u;
    modint<mV> v;
    HashInt(int x = 0): u(x), v(x) {}
    HashInt(ll x): u(x), v(x) {}
#define defhashop(op)                                                          \
    defop(HashInt, op) { return (u op## = o.u), (v op## = o.v), *this; }
    defhashop(+) defhashop(-) defhashop(*)
    auto operator<=>(const HashInt &o) const = default;
    friend print_op(HashInt) { return out << u.u.x; }
};

using hint = HashInt<modint<(int)1e9 + 7>, 998'244'353>;

const int maxn = 301010;
const hint base = 31;
hint pwbase[maxn];
void precal() {
    pwbase[0] = 1;
    for (auto i: views::iota(0, maxn - 1)) {
        pwbase[i + 1] = pwbase[i] * base;
    }
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    map<int, set<hint>> dict;
    while (n--) {
        DB();
        int t;
        string s;
        cin >> t >> s;
        clog << db(t) << db(s) << endl;
        if (t == 1 or t == 2) {
            hint hs = 0;
            for (auto ch: s) {
                ch = ch - 'a' + 1;
                clog << db(ch) << endl;
                hs = hs * base + ch;
            }
            clog << db(hs) << endl;
            if (t == 1) dict[sz(s)].insert(hs);
            else dict[sz(s)].erase(hs);
            if (auto it = dict.find(sz(s)); it->second.empty()) {
                dict.erase(it);
            }
            continue;
        }
        
        ll ans = 0;
        for (const auto& [len, se]: dict) {
            if (len > sz(s)) break;
            clog << db(len) << db(se) << endl;
            
            hint hs = 0;
            for (auto i: views::iota(0, len - 1)) {
                auto ch = s[i] - 'a' + 1;
                hs = hs * base + ch;
            }
            for (auto i: views::iota(len - 1, sz(s))) {
                auto ch = s[i] - 'a' + 1;
                hs = hs * base + ch;
                clog << db(i) << db(hs) << endl;
                ans += se.count(hs);
                ch = s[i - len + 1] - 'a' + 1;
                hs -= ch * pwbase[len - 1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}