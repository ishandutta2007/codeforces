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
    friend inline type operator op(type u, const type& v) { return u op ## = v; } \
    type& operator op ##=(const type& o) 

template<int mod>
struct modint {
    int x;
    modint (int x_ = 0): x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}
    defop(modint, +) { return ((x += o.x) >= mod) and (x -= mod), *this; }
    defop(modint, -) { return ((x -= o.x) < 0) and (x += mod), *this; }
    defop(modint, *) { return *this = modint(1ll * x * o.x); }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<998'244'353>;

const int max_coor = 301010;
mint pw2[max_coor];
mint pw3[max_coor];
void precal() {
    pw2[0] = 1;
    pw3[0] = 1;
    rep(i, 1, max_coor) {
        pw2[i] = pw2[i - 1] + pw2[i - 1];
        pw3[i] = pw3[i - 1] + pw3[i - 1] + pw3[i - 1];
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
    vector add(max_coor, vector<int>());
    vector rem(max_coor, vector<int>());
    
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        add[l].emplace_back(i);
        rem[r + 1].emplace_back(i);
    }
    
    set<int> cur;
    mint ans = 0;
    
    rep(pos, 0, max_coor) {
        for (auto i: rem[pos]) cur.erase(i);
        for (auto i: add[pos]) cur.insert(i);
        
        if (cur.size() == 0) continue;
        int mx = *--cur.end();
        mint base;
        if (mx == 0) {
            base = 1;
        } else {
            base = pw3[mx - 1] * 2;
        }
        mint cur_ans = base * pw2[n - mx - 1];
        ans += cur_ans;
    }
    cout << ans;
    
    return 0;
}