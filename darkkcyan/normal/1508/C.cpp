#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

const int maxn = 201010;
int n, m;

struct Edge {
    int u, v;
    ll w;
};
vector<Edge> el;
vector<pair<int, int>> gr[maxn];

struct DSU {
    vector<int> dsu;
    
    DSU(int len): dsu(len, -1) {}
    
    int find_set(int u) {
        return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
    }
    
    void join(int u, int v) {
        clog << db(u) << db(v) << endl;
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-dsu[u] < -dsu[v]) swap(u, v);
        dsu[u] += dsu[v];
        dsu[v] = u;
    }
};

vector<int> it[maxn * 2];

void build(int len) {
    rep(i, len, 2 * len)
        it[i].push_back(i - len);
    
    for (int i = len; i--; ) {
        it[i] = it[2 * i];
        it[i].insert(it[i].end(), all(it[2 * i + 1]));
    }
}

void do_join(int len, DSU& dsu, int u, int l, int r) {
    DB();
    clog << db(l) << db(r) << endl;
    for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            while (sz(it[l]) > 1) {
                dsu.join(u, it[l].back());
                it[l].pop_back();
            }
            dsu.join(u, it[l][0]);
            ++l;
        }
        if (r & 1) {
            --r;
            while (sz(it[r]) > 1) {
                dsu.join(u, it[r].back());
                it[r].pop_back();
            }
            dsu.join(u, it[r][0]);
        }
    }
}

int state[maxn];
bool detect_cyc(int u, int p) {
    state[u] = 1;
    int i = 0;
    rep(v, 1, n + 1) {
        if (v == u or v == p) continue;
        clog << db(u) << db(v) << endl;
        while (i < sz(gr[u]) and gr[u][i].first < v) ++i;
        if (i < sz(gr[u]) and gr[u][i].first == v) continue;
        if (state[v] == 1) return true;
        if (state[v] == 2) continue;
        if (detect_cyc(v, u)) return true;
    }
    state[u] = 2;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    el.resize(m);
    
    ll xor_all = 0;
    rep(i, 0, m) {
        cin >> el[i].u >> el[i].v >> el[i].w;
        gr[el[i].u].emplace_back(el[i].v, el[i].w);
        gr[el[i].v].emplace_back(el[i].u, el[i].w);
        xor_all ^= el[i].w;
    }
    
    build(n + 1);
    
    DSU dsu(n + 1);
    
    rep(u, 1, n + 1) {
        DB();
        clog << db(u) << endl;
        sort(all(gr[u]));
        int prv = 1;
        for (auto [v, w]: gr[u]) {
            clog << db(v) << endl;
            do_join(n + 1, dsu, u, prv, v);
            prv = v+ 1;
        }
        
        do_join(n + 1, dsu, u, prv, n + 1);
    }
    
    DSU temp = dsu;
    ll based_ans = 0;
    sort(all(el), [](const Edge&u , const Edge&v) { return u.w < v.w; });
    
    
    for (auto& [u, v, w]: el) {
        clog << db(u) << db(v) << db(w) << endl;
        clog << db(temp.find_set(u)) << db(temp.find_set(v)) << endl;
        if (temp.find_set(u) == temp.find_set(v)) continue;
        based_ans += w;
        temp.join(u, v);
        w = LLONG_MAX;
    }
    clog << db(based_ans) << endl;
    ll min_add = xor_all;
    clog << db(xor_all) << endl;
    for (auto [u, v, w]: el) {
        if (sz(gr[u]) == (n - 1) and sz(gr[v]) == n - 1) continue;
        clog << db(u) << db(v) << db(w) << endl;
        min_add = min(min_add, w);
    }
    clog << db(min_add) << endl;
    
    ll total_edges = 1ll * n * (n - 1) / 2;
    ll fe = total_edges - m;
    clog << db(fe) << endl;
    if (fe > n) {
        cout << based_ans << '\n';
        return 0;
    }
    
    rep(u, 1, n + 1) {
        if (state[u] == 2) continue;
        if (detect_cyc(u, u)) {
            clog << "cyc" << db(u) << endl;
            cout << based_ans << '\n';
            return 0;
        }
    }
    
    cout << based_ans  +min_add;
    
    return 0;
}

// vim: foldmethod=marker