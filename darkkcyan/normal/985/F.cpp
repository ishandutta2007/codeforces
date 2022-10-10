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

#define def_op(type, op, uop) \
    inline type& operator uop(const type& other) { return *this = *this op other; } \
    friend inline type operator op(type u, const type& v) 

template<int mod>
struct mod_int {
    int x;
    mod_int(int x_ = 0): x(x_) {}
    mod_int(ll x_) : x((int)(x_ % mod)) {}
    
    def_op(mod_int, +, +=) {
        if ((u.x += v.x) >= mod) u.x -= mod;
        return u;
    }
    
    def_op(mod_int, -, -=) {
        if ((u.x -= v.x) < 0) u.x += mod;
        return u;
    }
    def_op(mod_int, *, *=) { return 1ll * u.x * v.x; }
    friend bool operator==(const mod_int& u, const mod_int& v) { return u.x == v.x; }
    friend bool operator!=(const mod_int& u, const mod_int& v) { return u.x != v.x; }
    friend bool operator<(const mod_int& u, const mod_int& v) { return u.x < v.x; }
    friend ostream& operator<<(ostream& out, mod_int u) { return out << u.x; }
};

using mint1 = mod_int<(int)1e9 + 7>;
using mint2 = mod_int<(int)1e9 + 8181>;

struct Hash {
    mint1 x;
    mint2 y;
    Hash(int t = 0): x(t), y(t) {}
    Hash(ll t): x(t), y(t) {}
    def_op(Hash, +, +=) { u.x += v.x; u.y += v.y; return u; }
    def_op(Hash, -, -=) { u.x -= v.x; u.y -= v.y; return u; }
    def_op(Hash, *, *=) { u.x *= v.x; u.y *= v.y; return u; }
    friend bool operator==(const Hash& u, const Hash& v) { return u.x == v.x and u.y == v.y; }
    friend bool operator!=(const Hash& u, const Hash& v) { return u.x != v.x or u.y != v.y; }
    friend bool operator<(const Hash& u, const Hash& v) {
        if (u.x == v.x) return u.y < v.y;
        return u.x < v.x;
    }
    friend ostream& operator<<(ostream& out, Hash u) { return out << pair{u.x, u.y}; }
};

const int base = 3;
constexpr int maxch = 26;
const int maxn = 201010;
Hash base_pw[maxn];
void preprocess() {
    base_pw[0] = 1;
    rep(i, 1, maxn) base_pw[i] = base_pw[i - 1] * base;
}

struct PosHash {
    vector<array<Hash, maxch>> data;
    PosHash(const string& str): data(sz(str) + 1) {
        rep(i, 0, sz(str)) {
            rep(f, 0, 26) {
                data[i + 1][f] = data[i][f] * base;
                if (f == str[i] - 'a') data[i + 1][f] += 1;
            }
        }
    }
    
    array<Hash, maxch> get(int l, int r) const { // [l, r)
        array<Hash, maxch> ans;
        auto pw = base_pw[r - l];
        clog << db(pw) << db(data[1]) << endl;
        rep(i, 0, 26) ans[i] = data[r][i] - data[l][i] * pw;
        return ans;
    }
};

int n, q;
string s;

int main() {
    preprocess();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q >> s;
    
    PosHash hs(s);
    
    while (q--) {
        DB();
        int x, y, len;
        cin >> x >> y >> len;
        clog << db(x) << db(y) << db(len) << endl;
        --x; -- y;
        auto u = hs.get(x, x + len), v = hs.get(y, y + len);
        clog << db(u) << endl;
        clog << db(v) << endl;
        multiset<Hash> su(all(u)), sv(all(v));
        cout << (su == sv ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker