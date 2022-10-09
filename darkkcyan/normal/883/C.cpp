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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    ll f, T, t0;
    cin >> f >> T >> t0;
    ll a1, t1, p1;
    cin >> a1 >> t1 >> p1;
    ll a2, t2, p2;
    cin >> a2 >> t2 >> p2;
    if (f * t0 <= T) {
        cout << 0;
        return 0;
    }
    auto solve2 = [&](ll f_left, ll T_left) -> ll {
        clog << db(f_left) << db(T_left) << endl;
        if (f_left * t0 <= T_left) {
            clog << "zero" << endl;
            return 0;
        }
        if (f_left * min(t0, t2) > T_left) return LLONG_MAX;
        // cnt2 * a2 * t2 + (f_left - cnt2 * a2) * t0 <= T_left 
        // cnt2 * a2 * (t2 - t0) + f_left * t0 <= T_left
        // cnt2 >= (T_left - f_left * t0) / (a2 * (t2 - t0))
        ll cnt2 = (T_left - f_left * t0) / (a2 * (t2 - t0));
        rep(delta, -3, 4) {
            ll cur = cnt2 + delta;
            if (cur < 0) continue;
            ll cur_time = min(cur * a2, f_left) * t2 + max(f_left - cur * a2, 0ll) * t0;
            if (cur_time <= T_left) return cur;
        }
        return LLONG_MAX;
    };
    ll min_cost = LLONG_MAX;
    rep(_, 0, 2) {
        rep(cnt1, 0, f + 1) {
            ll cur_data = min(cnt1 * a1, f);
            if (cur_data * t1 > T) continue;
            DB();
            ll cnt2 = solve2(f - cur_data, max(0ll, T - cur_data * t1));
            clog << db(cnt1) << db(cnt2) << endl;
            if (cnt2 >= LLONG_MAX) continue;
            min_cost = min(min_cost, cnt1 * p1 + cnt2 * p2);
        }
        swap(a1, a2);
        swap(t1, t2);
        swap(p1, p2);
    }
    if (min_cost >= LLONG_MAX) {
        cout << -1;
    } else {
        cout << min_cost;
    }
    
    return 0;
}

// vim: foldmethod=marker