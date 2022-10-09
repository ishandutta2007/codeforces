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

struct TreeEdge {
    int to;
    ll w[2];
};
const int maxn = 301010;
const int maxlgn = 20;

int n;
ll midw[maxn];
vector<TreeEdge> gr[maxn];
int up[maxlgn][maxn];
int depth[maxn];

using dist_t = array<array<ll, 2>, 2>;

dist_t up_dist[maxlgn][maxn];

void dfs_up(int u, int p) {
    for (const auto &[v, w] : gr[u]) {
        if (v == p)
            continue;
        dfs_up(v, u);
        midw[u] = min(midw[u], w[0] + w[1] + midw[v]);
    }
}

dist_t init_dist(ll w) { return {array<ll, 2>{0ll, w}, {w, 0ll}}; }

dist_t merge_dist(const dist_t &u, const dist_t &v) {
    dist_t ans;
    rep(start, 0, 2) rep(end, 0, 2) {
        ans[start][end] = min(u[start][0] + v[0][end], u[start][1] + v[1][end]);
    }
    return ans;
}

void dfs_down(int u, int p) {
    for (const auto &[v, w] : gr[u]) {
        if (v == p)
            continue;
        midw[v] = min(midw[v], w[0] + w[1] + midw[u]);

        depth[v] = depth[u] + 1;
        up[0][v] = u;
        up_dist[0][v][0][0] = min(w[0], w[1] + midw[u] + midw[v]);
        up_dist[0][v][1][1] = min(w[1], w[0] + midw[u] + midw[v]);
        up_dist[0][v][0][1] = min(w[0] + midw[u], w[1] + midw[v]);
        up_dist[0][v][1][0] = min(w[1] + midw[u], w[0] + midw[v]);

        rep(lv, 1, maxlgn) {
            up[lv][v] = up[lv - 1][up[lv - 1][v]];
            up_dist[lv][v] =
                merge_dist(up_dist[lv - 1][v], up_dist[lv - 1][up[lv - 1][v]]);
        }

        dfs_down(v, u);
    }
}

dist_t get_dist(int u, int v) {
    if (depth[u] < depth[v]) {
        auto ans = get_dist(v, u);
        swap(ans[0][1], ans[1][0]);
        return ans;
    }
    dist_t du = init_dist(midw[u]), dv = init_dist(midw[v]);

    for (int d = depth[u] - depth[v], i = 0; d > 0; d >>= 1, ++i)
        if (d & 1) {
            du = merge_dist(du, up_dist[i][u]);
            u = up[i][u];
        }
    if (u == v)
        return du;
    for (int lv = maxlgn; lv--;) {
        if (up[lv][u] == up[lv][v])
            continue;
        du = merge_dist(du, up_dist[lv][u]);
        dv = merge_dist(dv, up_dist[lv][v]);
        u = up[lv][u];
        v = up[lv][v];
    }
    du = merge_dist(du, up_dist[0][u]);
    dv = merge_dist(dv, up_dist[0][v]);
    swap(dv[0][1], dv[1][0]);
    return merge_dist(du, dv);
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    rep(i, 0, n) { cin >> midw[i]; }

    rep(i, 0, n - 1) {
        int u, v;
        ll w1, w2;
        cin >> u >> v >> w1 >> w2;
        --u;
        --v;
        gr[u].push_back({v, {w1, w2}});
        gr[v].push_back({u, {w1, w2}});
    }
    dfs_up(0, 0);
    dfs_down(0, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        auto x = get_dist(u / 2, v / 2);
        cout << x[u & 1][v & 1] << '\n';
    }

    return 0;
}