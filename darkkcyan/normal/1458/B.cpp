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

const int maxn = 111;
const llong inf = 1e13;
int n;
llong a[maxn], b[maxn];

llong dp[maxn][maxn * maxn], old_dp[maxn][maxn * maxn];

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n + 10) fill(dp[i], dp[i] + maxn * maxn, -inf);
    dp[0][0] = 0;
    rep(i, n) {
        memcpy(old_dp, dp, sizeof(dp));
        rep(prev_cnt, n) {
            llong cur_cap = a[i] - b[i];
            rep(prev_cap, maxn * maxn - cur_cap - 1) {
                llong& cur = dp[prev_cnt + 1][prev_cap + cur_cap];
                cur = max(cur, old_dp[prev_cnt][prev_cap] + b[i]);
            }
        }
    }
    
    llong sum_b = accumulate(b, b + n, 0ll);
    rep1(i, n) {
        long double ans = 0;
        rep(cap, maxn * maxn) {
            llong cur = dp[i][cap];
            if (cap == 8 and i == 1) {
                clog << db(cur) << db(sum_b) << endl;
            }
            if (cur < 0) continue;
            ans = max(ans, 0.5 * (long double)(min(2 * (cur + cap), cur + sum_b)));
            if (cap == 8 and i == 1) {
                clog << db(cur) << db(sum_b) << db(ans) << endl;
            }
            if (i == 1 and ans > 7) {
                clog << db(i) << db(cur) << db(cap) << db(ans) << endl;
            }
        }
        cout << fixed << setprecision(10) << ans << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker