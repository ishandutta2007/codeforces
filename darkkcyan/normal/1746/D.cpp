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

    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        int n, k;
        cin >> n >> k;

        vector<int> p(n + 1);
        vector gr(n + 1, vector<int>());
        rep(i, 2, n + 1) {
            cin >> p[i];
            gr[p[i]].push_back(i);
        }
        
        vector<int> topo = {1};
        rep(i, 0, sz(topo)) {
            int u = topo[i];
            for (auto v: gr[u]) topo.push_back(v);
        }

        vector<ll> s(n + 1);
        rep(i, 1, n + 1) cin >> s[i];

        vector<ll> local_k(n + 1);
        vector<ll> max_local_path(n + 1);
        vector<bool> get_min(n + 1);
        local_k[1] = k;
        ll ans = 0;
        for (auto u: topo) {
            ans += s[u] * local_k[u];
            for (auto v : gr[u]) {
                local_k[v] = (local_k[u] + sz(gr[u]) - 1) / sz(gr[u]);
            }
        }

        clog << db(ans) << endl;
        for (auto u: topo | views::reverse) {
            DB();
            clog << db(u) << db(local_k[u]) << endl;
            max_local_path[u] = 0;
            vector<ll> cur_mx;
            for (auto v : gr[u]) { cur_mx.push_back(max_local_path[v]); }
            if (cur_mx.empty()) max_local_path[u] = s[u];
            else {
                ranges::sort(cur_mx);
                ll lim = (sz(gr[u]) - local_k[u] % sz(gr[u])) % sz(gr[u]);
                clog << db(lim) << endl;
                rep(i, 0, lim) { ans -= cur_mx[i]; }
                max_local_path[u] = s[u] + cur_mx[lim];
            }
            clog << db(max_local_path[u]) << endl;
        }
        cout << ans << '\n';
    }

    return 0;
}