#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

// #define constexpr(...) (__VA_ARGS__)
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
// DEBUGING TEMPLETE
// ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define clog                                                                   \
    if (0)                                                                     \
    cerr
#define DB(...)
#endif

template <class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type
operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T>
ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int n, c;
    cin >> n >> c;

    vector<ll> max_hxd(c + 1);
    rep(i, 0, n) {
        ll cost, h, d;
        cin >> cost;
        cin >> h >> d;
        ll hxd = h * d;
        max_hxd[cost] = max(max_hxd[cost], hxd);
    }

    clog << db(max_hxd) << endl;
    rep(i, 1, c + 1) {
        for (int f = 2 * i, cnt = 2; f <= c; f += i, ++cnt)
            max_hxd[f] = max(max_hxd[f], max_hxd[i] * cnt);
    }
    clog << db(max_hxd) << endl;

    vector<pair<ll, int>> dm;
    rep(i, 1, c + 1) dm.emplace_back(max_hxd[i], i);
    sort(all(dm), [&](const pair<ll, int> &u, const pair<ll, int> &v) {
        if (u.first == v.first)
            return u.second < v.second;
        return u.first > v.first;
    });
    
    int nl = 1;
    rep(i, 1, sz(dm)) {
        if (dm[i].first == dm[nl - 1].first) continue;
        dm[nl] = dm[i];
        dm[nl].second = min(dm[nl].second, dm[nl - 1].second);
        ++nl;
    }
    dm.resize(nl);
    reverse(all(dm));
    clog << db(dm) << endl;
    int q;
    cin >> q;
    while (q--) {
        ll h, d;
        cin >> h >> d;
        ll hxd = h * d;
        auto ans = upper_bound(all(dm), pair{hxd, INT_MAX});
        if (ans == dm.end()) {
            cout << "-1 ";
        } else {
            cout << ans->second << ' ';
        }
    }

    return 0;
}