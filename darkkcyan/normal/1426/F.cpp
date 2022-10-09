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
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type & operator op ##= (const type& o)
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx) : x(int(xx % mod)) {}
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
    friend print_op(modint) {
        return out << u.x;
    }
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
};

using mint = modint<(int)1e9 + 7>;

int n;
string s;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;
    map<char, int> cnt_right;
    for (auto ch: s) cnt_right[ch] ++;
    int cnt_ques = cnt_right['?'];
    map<char, int> cnt_left;
    map<string, mint> cnt_sub;
    for (auto ch: s) {
        cnt_right[ch] -= 1;
        for (auto [cl, vl]: cnt_left)
            for (auto [cr, vr]: cnt_right)
                cnt_sub[string(1, cl) + ch + cr] += mint(vl) * vr;
        cnt_left[ch] += 1;
    }
    
    mint ans = 0;
    for (auto [sub, c]: cnt_sub) {
        clog << db(sub) << db(c) << endl;
        if (sub[0] != 'a' and sub[0] != '?') continue;
        if (sub[1] != 'b' and sub[1] != '?') continue;
        if (sub[2] != 'c' and sub[2] != '?') continue;
        int cur_cnt_ques = (int)count(all(sub), '?');
        clog << db(cur_cnt_ques) << endl;
        ans += mint(3).pow(cnt_ques - cur_cnt_ques) * c;
    }
    cout << ans;
    
    
    return 0;
}

// vim: foldmethod=marker