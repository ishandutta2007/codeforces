#ifdef LOCAL
#define TESTING
#endif
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

const int maxn = 1010;

int n;
int d[maxn];

namespace secret {
mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}

bool adj[maxn][maxn];
vector<int> gr[maxn];

void init() {
    n = rand(1, 1000);
    memset(adj, 0, sizeof(adj));
    
    rep(i, 0, n + 1) d[i] = 0;

    // int m = n == 1 ? 0 : rand(1, n * (n - 1) / 2);
    int m = n == 1  ? 0 : rand(1, min(n * (n - 1) / 2, 2 * n));
    // int m = n == 1  ? 0 : rand(max(n * (n - 1) / 2 - 10, 0), n * (n - 1) / 2);
    ofstream inp("main.inp");
    inp << n << ' ' << m << endl;
    cout << db(n) << db(m) << endl;
    rep(i, 0, m) {
        int u, v;
        do {
            u = rand(1, n);
            v = rand(1, n);
        } while (u == v or adj[u][v]);
        adj[u][v] = adj[v][u] = 1;
        ++d[u];
        ++d[v];
        inp << u << ' ' << v << endl;
    }
    
    rep(i, 0, n + 1) {
        gr[i].clear();
        rep(f, 0, n + 1) if (adj[i][f]) gr[i].push_back(f);
        ranges::shuffle(gr[i], rng);
        inp << db(i) << ' ' << gr[i] << endl;
    }
}

int ask(int u) {
    if (sz(gr[u]) == 0) return - 1;
    int t = gr[u].back();
    gr[u].pop_back();
    return t;
}

void answer(vector<int> color) {
    vector<int> par(n + 1, -1);
    function<int(int)> find_set = [&](int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    };
    
    auto join = [&] (int u, int v){
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
    };
    
    rep(i, 1, n + 1) {
        rep(f, 1, n + 1) if (adj[i][f] and color[i] == color[f]) join(i, f);
    }
    
    rep(i, 1, n + 1) {
        rep(f, 1, n + 1) {
            if (color[i] == color[f]) {
                assert(find_set(i) == find_set(f));
            }
        }
    }
    
    vector<int> cnt_col(n + 1);
    vector<int> cnt_deg(n + 1);
    rep(i, 1, n + 1) {
        cnt_col[color[i]]++;
        cnt_deg[color[i]] += (int)ranges::count(adj[i], 1);
    }
    
    rep(i, 0, n + 1) {
        if (cnt_col[i] == 0) continue;
        assert(cnt_deg[i] <= cnt_col[i] * cnt_col[i]);
    }
    cout << "OK" << endl;
}

} // namespace secret

void init() {
#ifdef TESTING
    secret::init();
#else
    cin >> n;
    rep(i, 1, n + 1) cin >> d[i];
#endif
}

int ask(int u) {
#ifdef TESTING
    return secret::ask(u);
#else
    cout << "? " << u << endl;
    int r;
    cin >> r;
    return r;
#endif
}

void answer(vector<int> c) {
#ifdef TESTING
    cout << db(c) << endl;
    secret::answer(c);
#else
    cout << "! ";
    rep(i, 1, n + 1) cout << c[i] << ' ';
    cout << endl;
#endif
}

void solve() {
    init();
    
    vector<int> nodes;
    rep(i, 1, n + 1) nodes.push_back(i);
    ranges::sort(nodes, greater<>(), [&](int x) { return d[x]; });
    
    vector<int> par(n + 1, -1);
    function<int(int)> find_set = [&](int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    };
    
    auto join = [&] (int u, int v){
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
    };
    
    vector<bool> vis(n + 1);
    
    int s = (int)sqrt(n);
    
    int qr_left = n;
    
    for (auto u: nodes) {
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        
        rep(i, 0, d[u]) {
            if (qr_left == 0) break;
            int v = ask(u);
            join(u, v);
            if (vis[v]) break;
            vis[v] = true;
            --qr_left;
        }
    }
    
    vector<int> color(n + 1, -1);
    vis.assign(n + 1, false);
    int cur_col = 0;
    rep(i, 1, n + 1) {
        if (color[i] != -1) continue;
        ++cur_col;
        color[i] = cur_col;
        rep(f, 1, n + 1) {
            if (find_set(i) == find_set(f)) {
                clog << db(i) << db(f) << endl;
                color[f] = cur_col;
            }
        }
    }
    answer(color);
}

int main() {
#ifdef LOCAL
    // freopen("main.inp", "r", stdin);
    // freopen("main.out", "w", stdout);
    // freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
#ifdef TESTING
    while (true) {
        cout << string(10, '-') << endl;
        solve();
    }
#else
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
#endif

    return 0;
}