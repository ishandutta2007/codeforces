#include <bits/stdc++.h>
using namespace std;

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
    if (0) cerr
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
    if constexpr (i == tuple_size<T>::value) return out << ")";
    else
        return print_tuple_utils<i + 1, T>(
            out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE
// ////////////////////////////////////////////////////////////////}}}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector gr(n + 1, vector<int>());

    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    const int lg = 20;
    vector up(lg, vector<int>(n + 1));

    up[0][1] = 1;
    vector<int> topo = {1};
    vector<int> d(n + 1);
    rep(i, 0, sz(topo)) {
        int u = topo[i];
        for (auto v : gr[u]) {
            if (v == up[0][u]) continue;
            topo.push_back(v);
            up[0][v] = u;
            d[v] = d[u] + 1;
        }
    }

    rep(lv, 0, lg - 1) {
        rep(i, 1, n + 1) { up[lv + 1][i] = up[lv][up[lv][i]]; }
    }

    vector<ll> sum_d_up(n + 1);
    vector<ll> cnt_children(n + 1);
    for (auto u : topo | views::reverse) {
        cnt_children[u] = 1;
        for (auto v : gr[u]) {
            if (v == up[0][u]) continue;
            cnt_children[u] += cnt_children[v];
            sum_d_up[u] += sum_d_up[v] + cnt_children[v];
        }
    }
    clog << db(cnt_children) << endl;
    clog << db(sum_d_up) << endl;

    vector<ll> sum_d_down(n + 1);
    for (auto u : topo) {
        for (auto v : gr[u]) {
            if (v == up[0][u]) continue;
            sum_d_down[v] = sum_d_down[u] + sum_d_up[u] -
                            (sum_d_up[v] + cnt_children[v]) +
                            (n - cnt_children[v]);
        }
    }
    clog << db(sum_d_down) << endl;

    auto cal_res = [&](ll cnt1, ll sum1, ll cnt2, ll sum2, ll dist) {
        clog << db(cnt1) << db(sum1) << db(cnt2) << db(sum2) << db(dist)
             << endl;
        ll total_way = cnt1 * cnt2;
        ll numerator = cnt1 * sum2 + cnt2 * sum1 + (dist + 1) * total_way;
        return (ld)numerator / (ld)total_way;
    };

    auto solve = [&](int u, int v) {
        DB();
        clog << db(u) << db(v) << endl;
        if (d[u] < d[v]) swap(u, v);
        int u1 = u, v1 = v;
        if (d[u] != d[v]) {
            for (int i = 0, k = d[u] - d[v] - 1; k; k >>= 1, ++i)
                if (k & 1) u = up[i][u];
            if (up[0][u] == v)
                return cal_res(cnt_children[u1], sum_d_up[u1],
                               n - cnt_children[u],
                               sum_d_down[u] - (n - cnt_children[u]),
                               d[u1] - d[v1]);
            u = up[0][u];
        }
        for (int i = lg; i--;) {
            if (up[i][u] == up[i][v]) continue;
            u = up[i][u];
            v = up[i][v];
        }
        u = v = up[0][u];
        ll dist = d[u1] + d[v1] - 2 * d[u];
        return cal_res(cnt_children[u1], sum_d_up[u1], cnt_children[v1],
                       sum_d_up[v1], dist);
    };

    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << fixed << setprecision(10) << solve(u, v) << '\n';
    }

    return 0;
}