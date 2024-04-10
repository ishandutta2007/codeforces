#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int maxn = 301010;
const int maxlg = 20;
int n, m;
vector<int> gr[maxn];

int up[maxlg][maxn];
int depth[maxn];
void dfs(int u = 1, int p = 1) {
    up[0][u] = p;
    rep(i, maxlg - 1)
        up[i + 1][u] = up[i][up[i][u]];
    depth[u] = depth[p] + 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int d = depth[u] - depth[v], i = 0; d > 0; d >>= 1, ++i) 
        if (d & 1) u = up[i][u];
    if (u == v) return u;
    for (int i = maxlg; i--; ) {
        if (up[i][u] == up[i][v]) continue;
        u = up[i][u];
        v = up[i][v];
    }
    return up[0][u];
}

int closest(int u, int ancestor) {
    if (u == ancestor) return u;
    for (int d = depth[u] - depth[ancestor] - 1, i = 0; d > 0; i++, d >>= 1) {
        if (d & 1) u = up[i][u];
    }
    return u;
}

vector<pair<int, int>> path_over[maxn];
vector<pair<int, int>> qr_list;
ll acc_path[maxn], start_from[maxn];

void clear() {
    rep1(i, n) {
        gr[i].clear();
        depth[i] = 0;
        path_over[i].clear();
        acc_path[i] = 0;
        start_from[i] = 0;
    }
    memset(up, 0, sizeof(up));
    qr_list.clear();
}

void add(int u, int v) {
    int l = lca(u, v);
    if (u != l) {
        start_from[u]++;
        acc_path[l]--;
    }
    if (v != l) {
        start_from[v]++;
        acc_path[l]--;
    }
    path_over[l].emplace_back(u, v);
    qr_list.emplace_back(u, v);
}

ll solve(int u = 1, int p = 1) {
    DB();
    clog << db(u) << endl;
    ll ans = 0;
    for (auto v: gr[u]) {
        if (v == p) continue;
        ans += solve(v, u);
        acc_path[u] += acc_path[v];
    }
    acc_path[u] += start_from[u];
    
    ll single = 0;
    map<int, ll> till_u;
    map<int, ll> over_from;
    map<pair<int, int>, ll> cnt_over;
    int cnt_true_over = 0;
    for (auto& [x, y]: path_over[u]) {
        int cx = closest(x, u);
        int cy = closest(y, u);
        clog << db(x) << db(y) << db(cx) << db(cy) << endl;
        if (x == u and y == u) {
            ++single;
        } else if (x == u) {
            ++till_u[cy];
            --acc_path[cy];
        } else if (y == u) {
            ++till_u[cx];
            --acc_path[cx];
        } else {
            acc_path[cx]--;
            acc_path[cy]--;
            over_from[cx]++;
            over_from[cy]++;
            cnt_over[{cx, cy}] ++;
            ++cnt_true_over;
        }
        x = cx;
        y = cy;
    }
    
    ll sum_acc_path = 0;
    ll sum_till_u = 0;
    for (auto v: gr[u]) 
        if (v != p) {
            sum_acc_path += acc_path[v];
            sum_till_u += till_u[v];
        }
    
    
    clog << db(sum_acc_path) << endl;
    clog<< db(sum_till_u) << endl;
    clog << db(single) << endl;
    clog << db(cnt_true_over) << endl;
    clog << db(path_over[u]) << endl;
    clog << db(start_from[u]) << endl;
    clog << db(acc_path[u]) << endl;
    clog << db(ans) <<endl;
    clog << db(till_u) << endl;
    clog << db(over_from) << endl;
    clog << db(cnt_over) << endl;
    for (auto [x, y]: path_over[u]) {
        if (x == u or y == u) continue;
        ans += sum_acc_path - acc_path[x] - acc_path[y];
        clog << db(x) << db(y) << db(ans) << endl;
        ans += sum_till_u - till_u[x] - till_u[y];
        clog << db(x) << db(y) << db(ans) << endl;
        ans += cnt_true_over - over_from[x] - over_from[y] + cnt_over[{x, y}] + cnt_over[{y, x}];
        clog << db(x) << db(y) << db(ans) << endl;
        ans += single;
        clog << db(x) << db(y) << db(ans) << endl;
        ans += start_from[u];
        clog << db(x) << db(y) << db(ans) << endl;
    }
    clog << db(ans) << endl;
    
    for (auto v: gr[u]) {
        if (v == p) continue;
        // ans += acc_path[v] * (sum_acc_path - acc_path[v]); 
        ans += acc_path[v] * (sum_till_u - till_u[v]);
        ans += acc_path[v] * (cnt_true_over - over_from[v]);
        ans += acc_path[v] * single;
        
        ans += till_u[v] * (sum_till_u - till_u[v]);
        ans += till_u[v] * (sum_acc_path - acc_path[v]);
        ans += till_u[v] * (cnt_true_over - over_from[v]);
        ans += till_u[v] * single;
        ans += till_u[v] * start_from[u];
    }
    clog << db(ans) << endl;
    
    ans += single * (single - 1);
    ans += single * sum_acc_path;
    ans += single * sum_till_u;
    ans += single * cnt_true_over;
    ans += single * start_from[u];
    clog << db(ans) << endl;
    
    ans += start_from[u] * single;
    ans += start_from[u] * sum_till_u;
    ans += start_from[u] * cnt_true_over;
    
    clog << db(ans) << endl;
    return ans;
}

ll stupid() {
    DB();
    auto nodes = [&](int u, int v) {
        vector<int> ans;
        while (depth[u] > depth[v]) {
            ans.push_back(u);
            u = up[0][u];
        }
        while (depth[v] > depth[u]) {
            ans.push_back(v);
            v = up[0][v];
        }
        while (u != v) {
            ans.push_back(u);
            ans.push_back(v);
            v = up[0][v];
            u = up[0][u];
        }
        ans.push_back(u);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    };
    ll ans = 0;
    rep(i, len(qr_list)) {
        auto li = nodes(qr_list[i].first, qr_list[i].second);
        for (int f = i + 1; f < len(qr_list); ++f) {
            auto lf = nodes(qr_list[f].first, qr_list[f].second);
            int cnt = 0;
            for (auto x: lf) {
                auto it = lower_bound(li.begin(), li.end(), x);
                if (it == li.end()) continue;
                if (*it != x) continue;
                ++cnt;
            }
            ans += cnt == 1;
            if (cnt == 1) {
                clog << qr_list[i] << ' ' << qr_list[f] << endl;
            }
        }
    }
    return ans;
}

void stress() { 
    mt19937 rng;
#define rand() ((int)(rng() >> 1))
    auto next = [&](int l, int r) {
        return rand() % (r - l + 1)  + l;
    };
    while (true) {
        n = rand() % 5+ 1;
        m = rand() % 6 + 1;
        clear();
        vector<int> perm(n);
        rep1(i, n) perm[i - 1] = i;
        shuffle(perm.begin(), perm.end(), rng);
        vector<pair<int, int>> edges;
        rep1(i, n - 1) {
            edges.emplace_back(perm[i], perm[rand() % i]);
        }
        shuffle(edges.begin(), edges.end(), rng);
        for (auto [u, v]: edges) {
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs();
        rep(i, m) {
            int u = next(1, n);
            int v = next(1, n);
            add(u, v);
        }
        ofstream inp("main.inp");
        inp << n << endl;
        for (auto [u, v]: edges) {
            inp << u << ' ' << v << endl;
        }
        inp << m << endl;
        for (auto [u, v]: qr_list) {
            inp << u << ' ' << v << endl;
        }
        auto exp = stupid();
        auto ans = solve() / 2;
        inp << ans << endl << exp << endl;
        inp.close();
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
        cout << "FAILED" << endl;
        exit(0);
    }
    
}

int main(void) {
    // stress();      
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n ;
    rep(i, n - 1) {
        int u, v;cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    dfs();
    cin >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        add(u, v);
    }
#ifdef LOCAL
    ll exp = stupid();
    cout << exp << endl;
#endif
    
    ll ans = solve();
    ans /= 2;
    cout << ans << '\n';
    
    return 0;
}

// vim: foldmethod=marker