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

struct DSU {
    vector<int> par;
    int comp_cnt;

    DSU(int sz) : par(sz, -1), comp_cnt(sz) {}

    int findset(int u) { return par[u] < 0 ? u : par[u] = findset(par[u]); }

    bool join(int u, int v) {
        u = findset(u);
        v = findset(v);
        if (u == v) return false;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --comp_cnt;
        return true;
    }
};

int main() {
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
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> gr(n + 1);
        string ans(m, '0');

        DSU dsu(n + 1);

        vector<tuple<int, int, int>> rest;

        for (auto i : views::iota(0, m)) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            gr[u].emplace_back(v, i);
            gr[v].emplace_back(u, i);

            if (dsu.join(u, v)) { continue; }
            rest.emplace_back(u, v, i);
            ans[i] = '1';
        }
        if (rest.size() == 3) {
            ranges::sort(rest);
            if (get<0>(rest[0]) == get<0>(rest[1]) and
                get<1>(rest[0]) == get<0>(rest[2]) and
                get<1>(rest[1]) == get<1>(rest[2])) {
                vector<int> par(n + 1, -1);
                
                auto [s, t, oid] = rest[0];
                queue<int> qu;
                for (par[s] = -2, qu.push(s); qu.size(); qu.pop()) {
                    int u = qu.front();
                    for (auto [v, id]: gr[u]) {
                        if (ans[id] == '1') continue;
                        if (par[v] != -1) continue;
                        par[v] = id;
                        qu.push(v);
                    }
                }
                ans[oid] = '0';
                ans[par[t]] = '1';
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}