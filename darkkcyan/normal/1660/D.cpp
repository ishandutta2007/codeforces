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

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        // first: pos
        // second: cnt 2
        array<pair<int, int>, 2> first_pos;
        int cur_cnt2, sign;

        tuple<int, int, int> ans = {0, n, n};

        auto reset = [&](int pos) {
            clog << "reset" << db(pos) << endl;
            first_pos[0] = {pos, 0};
            first_pos[1] = {-1, -1};
            cur_cnt2 = 0;
            sign = 1;
        };
        reset(0);
        rep(i, 0, n) {
            DB();
            if (a[i] == 0) {
                reset(i + 1);
                continue;
            }
            cur_cnt2 += abs(a[i]) == 2;
            sign *= (a[i] > 0) - (a[i] < 0);
            clog << db(i) << db(cur_cnt2) << db(sign) << endl;
            int sb = sign > 0 ? 0 : 1;
            if (first_pos[sb].first != -1) {
                clog << db(first_pos[sb]) << endl;
                ans = max(ans, {cur_cnt2 - first_pos[sb].second,
                                first_pos[sb].first, i + 1});
            } else {
                first_pos[sb] = {i + 1, cur_cnt2};
            }
            clog << db(ans) << endl;
        }
        int x = get<1>(ans);
        int y = n - get<2>(ans);
        cout << x << ' ' << y << '\n';
    }

    return 0;
}