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
    mod_int (int xx = 0): x(xx) {}
    mod_int (ll xx) : x((int)(xx % mod)) {}
    def_op(mod_int, +, +=) {
        if ((u.x += v.x) >= mod) u.x -= mod;
        return u;
    }
    
    def_op(mod_int, -, -=) {
        if ((u.x -= v.x) < 0) u.x += mod;
        return u;
    }
    
    def_op(mod_int, *, *=) { return 1ll * u.x * v.x; }
    
    friend bool operator ==(const mod_int& u, const mod_int& v) {
        return u.x == v.x;
    }
    
    friend ostream& operator<<(ostream& out, mod_int u) {
        return out << u.x;
    }
};

using mint1 = mod_int<(int)1e9 + 7>;
using mint2 = mod_int<(int)998'244'353>;

struct Hash {
    mint1 x; mint2 y;
    Hash(int xx = 0): x(xx), y(xx) {}
    Hash(ll xx): x(xx), y(xx) {}
    
    def_op(Hash, +, +=) { u.x += v.x; u.y += v.y; return u; }
    def_op(Hash, -, -=) { u.x -= v.x; u.y -= v.y; return u; }
    def_op(Hash, *, *=) { u.x *= v.x; u.y *= v.y; return u; }
    
    Hash repeat(int times, Hash padding) const {
        Hash base = *this, ans(0);
        for (; times > 0; times >>= 1, base = base * padding + base, padding = padding * padding)
            if (times & 1) ans = ans * padding + base;
        return ans;
    }
    
    friend bool operator==(const Hash& u, const Hash& v) {
        return u.x == v.x and u.y == v.y;
    }
    
    friend ostream& operator<<(ostream& out, Hash u) {
        return out << pair{u.x, u.y};
    }
};

const int maxn = 501010;
const int base = 29;
Hash bpw[maxn];
void precal() {
    bpw[0] = 1;
    rep(i, 1, maxn) bpw[i] = bpw[i - 1] * base;
}

struct StrHash {
    vector<Hash> hs;
    StrHash(const string& s): hs(sz(s) + 1) {
        rep(i, 0, sz(s)) 
            hs[i + 1] = hs[i] * base + (int)(s[i] - 'a' + 1);
    }
    
    size_t size() const {
        return hs.size() - 1; 
    }
    
    Hash get(int l, int r) const { // [l, r)
        return hs[r] - hs[l];
    }
};

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    string s; cin >> s;
    StrHash hs(s);
    
    auto get_rep = [&](int base_len, int final_len) {
        if (final_len <= base_len) return hs.get(0, final_len);
        auto ans = hs.get(0, base_len).repeat(final_len / base_len, bpw[base_len]);
        ans = ans * bpw[final_len % base_len] + hs.get(0, final_len % base_len);
        return ans;
    };
    
    auto get_char = [&](int base_len, int pos) {
        return s[pos % base_len];
    };
    
    auto cmp = [&](int l1, int l2) {
        int l = min(l1, l2), r = k;
        while (l < r) {
            int mid = (l + r) / 2;
            if (get_rep(l1, mid) == get_rep(l2, mid))
                l = mid + 1;
            else
                r = mid;
        }
        return get_char(l1, l - 1) < get_char(l2, l - 1);
    };
    
    int opt = 1;
    rep(i, 2, n + 1) opt = min(opt, i, cmp);
    rep(i, 0, k) cout << get_char(opt, i);
    
    return 0;
}

// vim: foldmethod=marker