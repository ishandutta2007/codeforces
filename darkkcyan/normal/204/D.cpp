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
    type& operator op ##= (const type& o) 

template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    
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
    friend print_op(modint) {
        return out << u.x;
    }
};

const int maxn = 1010101;
using mint = modint<(int)1e9 + 7>;

mint pref_b[maxn], pref_no_b[maxn], suff_w[maxn], suff_no_w[maxn];

mint p2[maxn];
void precal() {
    p2[0] = 1;
    rep(i, 1, maxn) p2[i] = p2[i - 1] + p2[i - 1];
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    if (2 * k > n) {
        cout << "0\n";
        return 0;
    }
    
    string s;
    cin >> s;
    
    vector<int> sw(n + 1), sb(n + 1), sx(n + 1);
    rep(i, 0, n) {
        sw[i + 1] = sw[i] + (s[i] == 'W');
        sb[i + 1] = sb[i] + (s[i] == 'B');
        sx[i + 1] = sx[i] + (s[i] == 'X');
    }
    
    pref_b[0] = 0;
    mint sum = 0;
    rep(i, 0, k) pref_no_b[i] = p2[sx[i]];
    rep(i, k, n + 1) {
        if (s[i - 1] == 'X') sum += sum;
        if (sw[i] - sw[i - k] == 0 and (i - k <= 0 or s[i - k - 1] != 'B')) {
            pref_b[i] = i - k <= 0 ? 1 : pref_no_b[i - k - 1];
            sum += pref_b[i];
        }
        
        pref_no_b[i] = p2[sx[i]] - sum;
    }
    
    sum = 0;
    rep(i, n - k + 1, n + 1) suff_no_w[i] = p2[sx[n] - sx[i]];
    for (int i = n - k; i >= 0; --i) {
        if (s[i] == 'X') sum += sum;
        if (sb[i + k] - sb[i] == 0 and (i + k >= n or s[i + k] != 'W')) {
            suff_w[i] = i + k >= n ? 1 : suff_no_w[i + k + 1];
            sum += suff_w[i];
        }
        suff_no_w[i] = p2[sx[n] - sx[i]] - sum;
    }
    
    clog << db(s) << endl;
    rep(i, 0, n + 1) {
        clog << db(i) << db(pref_b[i]) << db(pref_no_b[i]) << db(suff_w[i]) << db(suff_no_w[i])  << endl;
    }
    
    mint ans = 0;
    rep(i, k, n) {
        if (sw[i] - sw[i - k] == 0) {
            ans += pref_b[i] * (p2[sx[n] - sx[i]] - suff_no_w[i]);
        }
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker