#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

struct DSU {
    vector<int> par;
    int cnt_comp;
    DSU(int n): par(n, -1), cnt_comp(n) {}
        
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
        --cnt_comp;
    }
};

struct Edge {
    int u, v, c;
};
const int maxn = 101010;
const int maxval = (int)1e9 + 1;
const int maxbit = 31;
int n, m;
vector<Edge> el;

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
        cin >> n >> m;
        el.resize(m);
        for (auto& [u, v, c]: el) cin >> u >> v >> c;
        
        int ans = 0;
        for (int bit = maxbit; bit--; ) {
            DSU dsu(n + 1);
            for (auto [u, v, c]: el) {
                if ((c >> bit) & 1) continue;
                dsu.join(u, v);
            }
            clog << db(dsu.cnt_comp) << endl;
            if (dsu.cnt_comp == 2) {
                el.erase(
                    remove_if(all(el), [&](auto& e) { return (bool)((e.c >> bit) & 1); }),
                    el.end()
                );
            } else {
                ans |= 1 << bit;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker