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

using i128 = __int128;

#define defop(type, op) \
    inline friend type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o)
template<ll mod>
struct modll {
    ll x;
    modll(int xx): x(xx) {}
    modll(ll xx = 0): x(xx) {}
    modll(i128 xx): x((ll)(xx % mod)) {}
    
    defop(modll, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modll, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modll, *) {
        return *this = modll((i128) x * o.x);
    }
    
    friend bool operator<(modll u, modll v) {
        return u.x < v.x;
    }
    
    friend print_op(modll) {
        return out << u.x;
    }
};

using mll = modll< 9999999900000001 >;

const int maxn = 7010101;

mll base;
mll pw[maxn];
mt19937 rng;

void precal() {
    base = ((int)rng() % 1000 + 1000) * 2 + 1;
    pw[0] = 1;
    rep(i, 1, maxn) pw[i] = pw[i - 1] * base;
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    set<mll> has;
    rep(i, 0, n) {
        string s;
        cin >> s;
        mll hs;
        for (auto ch: s) {
            hs = hs * base + (ch - 'a' + 1);
        }
        has.insert(hs);
    }
    
    clog << db(has) << endl;
    
    rep(qid, 0, m) {
        DB();
        string s;
        cin >> s;
        mll hs;
        for (auto ch: s) {
            hs = hs * base + (ch - 'a' + 1);
        }
        clog << db(hs) << endl;
        bool ok = false;
        rep(i, 0, sz(s)) {
            DB();
            char ch = s[i];
            for (auto nch: {'a', 'b', 'c'}) {
                if (nch == ch) continue;
                clog << db(ch) << db(nch) << endl;
                auto nhs = hs - (ch - 'a' + 1) * pw[sz(s) - i - 1];
                nhs += (nch - 'a' + 1) * pw[sz(s) - i - 1];
                clog << db(nhs) << endl;
                if (has.count(nhs)) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker