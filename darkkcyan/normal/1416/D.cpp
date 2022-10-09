#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

// Change these
using ans_type = vector<int>;
constexpr bool testing = 0;
constexpr bool print_brute = 0;
constexpr bool multitest = 0;

mt19937 rng(testing ? 177013 : chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

struct Query {
    int type, u;
    Query() {}
};
const int maxn = 201010;
const int maxm = 303030;
const int maxq = 500010;
int n, m, q;
int a[maxn];
vector<pair<int, int>> edge_list;
Query qr[maxq];

pair<int, int> it[(maxn + maxm)* 2];
int it_size;
void build(const vector<int>& vals) {
    it_size = len(vals);
    rep(i, it_size) it[i + it_size] = {vals[i], i};
    for (int i = it_size - 1; i > 1; --i) {
        it[i] = max(it[2 * i], it[2 * i + 1]);
    }
}

pair<int, int> get_max(int l, int r) {
    pair<int, int> ans(0, -1);
    for (l += it_size, r += it_size; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, it[l++]);
        if (r & 1) ans = max(ans, it[--r]);
    }
    return ans;
}

void set_val(int pos, int new_val) {
    it[pos + it_size] = {new_val, pos};
    for (pos += it_size; pos > 1; pos >>= 1) it[pos >> 1] = max(it[pos], it[pos ^ 1]);
}

void read() {
    if constexpr(!testing) {
        cin >> n >> m >> q;
        rep(i, n) cin >> a[i];
        edge_list.clear();
        rep(i, m) {
            int u, v; cin >> u >> v;
            --u; -- v;
            edge_list.emplace_back(u, v);
        }
        rep(i, q) {
            cin >> qr[i].type >> qr[i].u;
            --qr[i].u;
        }
        
    } else {
        ofstream inp("main.inp");
        n = 5;
        m = n + (int)(rng() % 3);
        rep(i, n) a[i] = i;
        shuffle(a, a + n, rng);
        set<pair<int, int>> edge;
        while (len(edge) < m) {
            int u = (int)(rng() % n);
            int v = (int)(rng() % (n - 1));
            if (v == u) ++v;
            if (u > v) swap(u, v);
            edge.emplace(u, v);
        }
        edge_list.assign(edge.begin(), edge.end());
        vector<int> del_order(m);
        rep(i, m) del_order[i] = i;
        shuffle(del_order.begin(), del_order.end(), rng);
        
        q = 20;
        rep(i, q) {
            qr[i].type = (int)(rng() & 1) + 1;
            if (qr[i].type == 2 and !len(del_order)) qr[i].type = 1;
            if (qr[i].type == 1) qr[i].u = (int)(rng() % n);
            else {
                qr[i].u = del_order.back();
                del_order.pop_back();
            }
        }
        
        inp << n << ' ' << m << ' ' << q << endl;
        rep(i, n) inp << a[i] << ' ';
        inp << endl;
        for (auto [u, v]: edge_list) inp << u + 1 << ' ' << v + 1 << '\n';
        rep(i, q) inp << qr[i].type << ' ' << qr[i].u + 1 << '\n';
    }
}

void print_ans(ostream& cout, const ans_type& ans) {
    for (auto i: ans) cout << i << '\n';
}

ans_type solve() {
    vector<int> dsu(n, -1);
    function <int(int)> find_set = [&](int u) {
        return dsu[u] < 0  ? u : dsu[u] = find_set(dsu[u]); };
    
    auto join = [&](int u, int v) -> bool {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return false;
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    };
    
    vector<vector<int>> tree(n);
    vector<bool> has_par(n);
    vector<bool> end_edges(m, true);
    
    rep(i, q) {
        if (qr[i].type == 2) end_edges[qr[i].u] = false;
    }
    
    auto make_tree_edge = [&](int u, int v) {
        if (find_set(u) == find_set(v)) return -1;
        int p = len(tree);
        tree.emplace_back();
        dsu.emplace_back(-1);
        
        int pu = find_set(u);
        int pv = find_set(v);
        
        tree[p].push_back(pv);
        tree[p].push_back(pu);
        join(p, pu);
        join(p, pv);
        return p;
    };
    
    rep(i, m) {
        if (!end_edges[i]) continue;
        auto [u, v] = edge_list[i];
        make_tree_edge(u, v);
    }
    
    vector<int> added_node(q);
    for (int i = q; i--; ) {
        if (qr[i].type == 1) continue;
        auto [u, v] = edge_list[qr[i].u];
        added_node[i] = make_tree_edge(u, v);
    }
    
    vector<int> start(len(tree)), stop(len(tree));
    vector<int> vals;
    function<void(int)> dfs = [&](int u) {
        DB(u);
        start[u] = len(vals);
        vals.push_back(u < n ? a[u] : 0);
        for (auto v: tree[u]) {
            dfs(v);
        }
        stop[u] = len(vals);
    };
    
    clog << len(tree) << ' ' << len(has_par) << endl;
    set<int> start_set;
    rep(i, len(tree)) {
        if (dsu[i] < 0) {
            clog << db(i) << endl;
            dfs(i);
            start_set.insert(start[i]);
        }
    }
    start_set.insert(len(vals));
    
    build(vals);
    clog << db(start) << endl;
    clog << db(stop) << endl;
    clog << db(vals) << endl;
    
    vector<int> ans;
    rep(i, q) {
        if (qr[i].type == 2) {
            int x = added_node[i];
            if (x == -1) continue;
            start_set.erase(start[x]);
            for (auto v: tree[x]) start_set.insert(start[v]);
            continue;
        }
        int u = qr[i].u;
        auto iter = start_set.upper_bound(start[u]);
        assert(iter != start_set.end());
        assert(iter != start_set.begin());
        auto mx = get_max(*prev(iter), *iter);
        ans.push_back(mx.first);
        set_val(mx.second, 0);
    }
    
    return ans;
}

ans_type brute() {
    vector<int> ans;
    vector<int> b(a, a + n);
    
    vector<vector<int>> gr(n);
    for (auto [u, v]: edge_list) {
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    set<pair<int, int>> removed;
    
    rep(i, q) {
        if (qr[i].type == 2) {
            auto [u, v] = edge_list[qr[i].u];
            if (u > v) swap(u, v);
            removed.emplace(u, v);
        } else {
            int u = qr[i].u;
            queue<int> qu;
            pair<int, int> mx(0, -1);
            vector<bool> vis(n);
            for (vis[u] = 1, qu.push(u); qu.size(); qu.pop()) {
                u = qu.front();
                mx = max(mx, {b[u], u});
                for (auto v: gr[u]) {
                    if (removed.count({u, v}) or removed.count({v, u})) continue;
                    if (vis[v]) continue;
                    qu.push(v);
                    vis[v] = true;
                }
            }
            ans.push_back(mx.first);
            b[mx.second] = 0;
        }
    }
    
    
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest = testing ? 1000 : 1; 
    if (multitest and !testing) cin >> ntest;
    
    rep1(testcase, ntest) {
        DB(testcase);
        read();
        if constexpr (!testing) {
            print_ans(cout, solve());
            if (print_brute) print_ans(cout << endl << "====" << endl, brute());
        } else {
            auto u = solve();
            auto v = brute();
            assert(u == v);
        }
    }
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker