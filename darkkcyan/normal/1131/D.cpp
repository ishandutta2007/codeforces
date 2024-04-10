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


const int maxn = 1010;
int n, m;
string cmp[maxn];

struct DSU {
    vector<int> par;
    DSU(int len): par(len, -1) {}
    int find_set(int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    }
    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
    }
};

vector<int> gr[maxn * 2];
int rev_deg[maxn * 2];

int mark[maxn * 2];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    DSU dsu(n + m);
    rep(i, 0, n) {
        cin >> cmp[i];
        rep(f, 0, m) {
            if (cmp[i][f] == '=') dsu.join(i, f + n);
        }
    }
    
    rep(i, 0, n) {
        int u = dsu.find_set(i);
        rep(f, 0, m) {
            int v = dsu.find_set(f + n);
            if (cmp[i][f] == '<') {
                gr[u].push_back(v);
                ++rev_deg[v];
            }
            else if (cmp[i][f] == '>') {
                gr[v].push_back(u);
                ++rev_deg[u];
            }
        }
    }
    
    set<pair<int, int>> root_set;
    rep(i, 0, n + m) {
        if (dsu.find_set(i) == i) root_set.emplace(rev_deg[i], i);
    }
    
    clog << db(root_set) << endl;
    
    while (sz(root_set) > 0) {
        auto [deg, u] = *root_set.begin();
        clog << db(deg) << db(u) << db(gr[u]) << endl;
        root_set.erase(root_set.begin());
        if (deg > 0) {
            cout << "No";
            return 0;
        }
        for (auto v: gr[u]) {
            mark[v] = max(mark[v], mark[u] + 1);
            root_set.erase({rev_deg[v], v});
            --rev_deg[v];
            root_set.emplace(rev_deg[v], v);
        }
    }
    
    cout << "Yes\n";
    rep(i, 0, n) {
        cout << mark[dsu.find_set(i)] + 1 << ' ';
    }
    cout << '\n';
    rep(i, 0, m) {
        cout << mark[dsu.find_set(i + n)] + 1 << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker