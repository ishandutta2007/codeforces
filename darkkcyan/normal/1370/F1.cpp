#ifdef LOCAL
// #define gentest 
#endif
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

mt19937 rng;
#define rand() ((int)(rng() >> 1))

const int maxn = 1010;
int n;
vector<int> gr[maxn];

namespace hidden {
    int x, y;
    vector<int> dx, dy;
};

vector<int> bfs(int src) {
    vector<int> dist(n + 1, -1);
    queue<int> qu;
    for (dist[src] = 0, qu.push(src); qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto v: gr[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            qu.push(v);
        }
    }
    return dist;
}

void init() {
#ifndef gentest
    cin >> n;
    rep(i, 0, n + 1) {
        gr[i].clear();
    }
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
#else
    n = rand() % 10 + 2;
    vector<int> nodes;
    rep(i, 0, n) nodes.push_back(i + 1);
    shuffle(all(nodes), rng);
    rep(i, 0, n + 1) gr[i].clear();
    cout << n << '\n';
    rep(i, 1, n) {
        int u = nodes[i];
        int v = nodes[rand() % i];
        cout << u << ' ' << v << endl;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    hidden::x = rand() % n + 1;
    hidden::y = rand() % n + 1;
    if (hidden::x == hidden::y) {
        ++hidden::x;
        if (hidden::x > n) hidden::x = 1;
    }
    hidden::dx = bfs(hidden::x);
    hidden::dy = bfs(hidden::y);
    cout << db(hidden::x) << db(hidden::y) << endl;
    cout << db(hidden::dx) << endl;
    cout << db(hidden::dy) << endl;
#endif
}

pair<int, int> ask(vector<int> nodes) {
    cout << "? " << sz(nodes);
    for (auto i: nodes) cout << ' ' << i;
    cout << endl;
#ifndef gentest
    int x, d;
    cin >> x >> d;
    if (x == -1) exit(1);
    return {d, x};
#else
    pair<int, int> ans{INT_MAX, -1};
    for (auto i: nodes) ans = min(ans, {hidden::dx[i] + hidden::dy[i], i});
    cout << db(ans) << endl;
    return ans;
#endif
}

void answer(int u, int v) {
    cout << "! " << u << ' ' << v << endl;
#ifndef gentest
    string answer;
    cin >> answer;
    if (answer != "Correct") exit(1);
#else 
    if (hidden::x == u and hidden::y == v) {
        cout << "OK" << endl;
        return; 
    }
    if (hidden::x == v and hidden::y == u) {
        cout << "OK" << endl;
        return ;
    }
    cout << "NO" << endl;
    exit(1);
#endif
}

void solve() {
    init();
    vector<int> all_nodes(n);
    rep(i, 0, n) all_nodes[i]= i + 1;
    auto [d, root] = ask(all_nodes);
    vector<int> cnt(n + 1);
    function<void(int, int)> dfs1 = [&](int u, int p) {
        cnt[u] = 1;
        for (auto v: gr[u]) {
            if (v == p) continue;
            dfs1(v, u);
            cnt[u] += cnt[v];
        }
    };
    
    vector<bool> in_big(n + 1);
    function<void(int, int)> dfs2 = [&](int u, int p) {
        in_big[u] = 1;
        for (auto v: gr[u]) {
            if (v == p) continue;
            dfs2(v, u);
        }
    };
    
    dfs1(root, root);
    pair<int, int> big = {0, -1};
    for (auto v: gr[root]) big=  max(big, {cnt[v], v});
    dfs2(big.second, root);
    int l = 1, r = 0;
    auto dist_root = bfs(root);
    rep(i, 1, n + 1) {
        if (!in_big[i]) r = max(r, dist_root[i]);
    }
    pair<int, int> x_side = {0, root};
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> cur_nodes;
        rep(i, 1, n + 1) {
            if (dist_root[i] == mid and !in_big[i]) cur_nodes.push_back(i);
        }
        auto [cur_d, cur_x] = ask(cur_nodes);
        if (cur_d == d) {
            x_side = max(x_side, {mid, cur_x});
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    auto dist_x = bfs(x_side.second);
    vector<int> cur_nodes;
    rep(i, 1, n + 1) if (dist_x[i] == d) cur_nodes.push_back(i);
    auto [cur_d, y] = ask(cur_nodes);
    answer(y, x_side.second);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);  
    // freopen("main.out", "w", stdout);   
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
#ifndef gentest
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
#else
    while (true) {
        cout << string(10, '-') << endl;
        solve();
    }
#endif
    
    return 0;
}

// vim: foldmethod=marker