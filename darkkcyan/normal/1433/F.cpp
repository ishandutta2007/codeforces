#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
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

const int maxn = 77;
const int inf = (int)1e7;
int n, m, k;
int a[maxn][maxn];

llong dp[2][maxn][maxn][maxn];

void a_max(llong& u, llong v) {
    if (u < v) u = v;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, n) rep(f, m) cin >> a[i][f];
    int max_pick = m / 2;
    rep(i, 2) rep(f, m + 1) rep(g, max_pick + 1) rep(h, k)
        dp[i][f][g][h] = -inf;
    dp[0][m][0][0] = 0;
    
    rep(i, n) {
        int state = !(i & 1);
        rep(pick, max_pick + 1) {
            rep(rem, k) {
                a_max(dp[state][0][0][rem], dp[!state][m][pick][rem]);
            }
        }
        rep(f, m) {
            memcpy(dp[state][f + 1], dp[state][f], sizeof(dp[state][f + 1]));
            rep(prev_pick, max_pick) {
                rep(prev_rem, k) {
                    int cur_rem = (prev_rem + a[i][f]) % k;
                    a_max(dp[state][f + 1][prev_pick + 1][cur_rem], dp[state][f][prev_pick][prev_rem] + a[i][f]);
                }
            }
        }
    }
    
    llong ans = 0;
    rep(pick, max_pick + 1) a_max(ans, dp[n & 1][m][pick][0]);
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker