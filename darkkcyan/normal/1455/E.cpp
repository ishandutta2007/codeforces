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

using point = pair<llong, llong>;
#define xx first
#define yy second

point p[4];

llong min_move_dist(array<llong, 4>& arr) {
    nth_element(arr.begin(), arr.begin() + 1, arr.end());
    llong ans = 0;
    for (auto& u: arr) ans += abs(arr[1]- u);
    return ans;
}

llong solve_side(llong side) {
    int pos[4] = {0, 1, 2, 3};
    llong ans = LLONG_MAX;
    do {
        array<llong, 4> xs = {p[pos[0]].xx, p[pos[1]].xx, p[pos[2]].xx - side, p[pos[3]].xx - side};
        array<llong, 4> ys = {p[pos[0]].yy, p[pos[1]].yy - side, p[pos[2]].yy, p[pos[3]].yy - side};
        ans = min(ans, min_move_dist(xs) + min_move_dist(ys));
    } while (next_permutation(pos, pos + 4));
    return ans;
}

llong solve() {
    llong l = 0, r = 1e10;
    while (r - l > 10) {
        llong mid1 = l + (r - l) / 3;
        llong mid2 = r - (r - l) / 3;
        if (solve_side(mid1) > solve_side(mid2)) l = mid1;
        else r = mid2;
    }
    llong ans = LLONG_MAX;
    for (llong x = l; x <= r; ++x) ans = min(ans, solve_side(x));
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        rep(i, 4) cin >> p[i].xx >> p[i].yy;
        auto ans = solve();
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker