#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int inf = 1e7;
int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        string s; cin >> s;
        if (len(s) == 1) {
            cout << "0\n";
            continue;
        }
        if (len(s) == 2) {
            cout << (s[0] == s[1]) << '\n';
            continue;
        }
        
        int dp[2][2];
        dp[1][1] = 2;
        dp[0][1] = 1;
        dp[1][0] = 1;
        dp[0][0] = s[0] == s[1] ? inf : 0;
        
        for (int i = 2; i < len(s); ++i) {
            int new_dp[2][2];
            rep(u, 2) rep(v, 2) new_dp[u][v] = inf;
            rep(x_changed, 2) rep(y_changed, 2) rep(z_changed, 2) {
                char x = x_changed ? '0' : s[i - 2];
                char y = y_changed ? '1' : s[i - 1];
                char z = z_changed ? '2' : s[i];
                if (x == y or y == z or z == x) continue;
                new_dp[y_changed][z_changed] = min(new_dp[y_changed][z_changed], dp[x_changed][y_changed] + z_changed);
            }
            memcpy(dp, new_dp, sizeof(new_dp));
        }
        int ans = inf;
        rep(i, 2) rep(f, 2) ans = min(ans, dp[i][f]);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker