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
 
template<int n>
void brute() {
    vector<int> a(n);
    rep(i, 0, n) a[i] = 1 << i;
    rep(i, 0, n) {
        cout << bitset<n>(a[i]) << ' ';
    }
    cout << endl;
    rep(i, 0, n) {
        rep(f, 1, n) a[f] ^= a[f - 1];
        rep(f, 0, n) cout << bitset<n>(a[f]) << ' ';
        cout << endl;
    }
}


void solve(int* a, int n) {
    DB();
    if (n == 1) return; 
    int lg = 31 - __builtin_clz(n);
    int t = 1 << lg;
    if (t == n) t >>= 1;
    rep(i, t, n) {
        a[i] ^= a[i - t];
    }
    rotate(a, a + t, a + n);
    solve(a, n - t);
    solve(a + n - t, t);
    rep(i, 0, n - t) {
        a[n - (n - t) + i] ^= a[i];
        // a[i + n - t + t] ^= a[i];
    }
}
const int maxn = 1001010;
int n;
int a[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    // brute<10>();
    // cout << endl;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    
    solve(a, n);
    rep(i, 0, n) cout << a[i] << ' ';
    
    return 0;
}