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

const int maxn = 201010;
const int mxlg = 20;
int n;
vector<int> gr[maxn];

int in_t[maxn], out_t[maxn], cur_t = 0;
int depth[maxn];
int up[mxlg][maxn];

void dfs(int u, int p) {
    in_t[u] = cur_t++;
    up[0][u] = p;
    rep(lv, 0, mxlg - 1)
        up[lv + 1][u] = up[lv][up[lv][u]];
    for (auto v : gr[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
    out_t[u] = cur_t++;
}

bool is_ancestor(int p, int u) {
    return in_t[p] <= in_t[u] and out_t[u] <= out_t[p];
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 0, d = depth[u] - depth[v]; d; d >>= 1, ++i)
        if (d & 1) u = up[i][u];
    if (u == v) return u;
    for (int i = mxlg; i--; ) {
        if (up[i][u] == up[i][v]) continue;
        u = up[i][u];
        v = up[i][v];
    }
    return up[0][u];
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, 1);

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (auto &i : nodes) cin >> i;
        sort(all(nodes), [](int u, int v) { return depth[u] < depth[v]; });
        
        clog << db(nodes) << endl;
        
        array<int, 2> ep = {-1, -1};
        bool ok = true;
        while (sz(nodes) + (ep[0] != -1) + (ep[1] != -1) > 2) {
            DB();
            int p = nodes.back();
            nodes.pop_back();
            ok = false;
            clog << db(p) << endl;
            if (ep[0] != -1 and ep[1] != -1 and is_ancestor(p, ep[0]) and is_ancestor(p, ep[1])) {
                ok = nodes.empty() and p == lca(ep[0], ep[1]);
                break;
            }
            for (auto& x: ep) {
                if (x == -1 or is_ancestor(p, x)) {
                    ok = true;
                    x = p;
                    break;
                }
            }
            clog << db(ep) << endl;
            clog << db(ok) << endl;
            if (!ok) break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}