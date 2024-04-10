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
int mod;
struct modint {
    int x;
    modint(int xx = 0): x(xx % mod) {
        if (x < 0) x += mod;
    }
    modint(ll xx): modint((int)(xx % mod)) {}
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
};

const int maxn = 101010;
int n, k;
string s[maxn];
int a[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    int cnt_ques = 0;
    rep(i, 0, n + 1) {
        cin >> s[i];
        if (s[i] == "?") {
            ++cnt_ques;
        } else {
            a[i] = stoi(s[i]);
        }
    }
    
    // if (n ==  42338 and k == 10000 and a[0] == 0 and a[1] == 0 and a[2] == 9440) {
        // cout << db(cnt_ques) << endl;
    // }
    if (cnt_ques) {
        if (k == 0) {
            if (s[0] != "?") {
                cout << (a[0] == 0 ? "Yes" : "No");
                return 0;
            }
            int turn = (n - cnt_ques) & 1;
            cout << (turn ? "No" : "Yes");
            return 0;
        }
        cout << (n & 1 ? "Yes" : "No");
        return 0;
    }
    
    if (k == 0) {
        cout << (a[0] == 0 ? "Yes" : "No");
        return 0;
    }
    
    if (k < 0) {
        k = -k;
        for (int i = 1; i <= n; i += 2) a[i] = -a[i];
    }
    
    if (k == 1) {
        cout << (accumulate(a, a + n + 1, 0ll) == 0 ? "Yes" : "No");
        return 0;
    }
    
    rep(i, 0, n + 30) {
        if (a[i] % k) {
            cout << "No";
            return 0;
        }
        a[i + 1] += a[i] / k;
    }
    
    cout << "Yes";
    
    
    return 0;
}

// vim: foldmethod=marker