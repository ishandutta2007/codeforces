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
 
const int maxn = 101010;

int n, m;

unordered_set<ll> edges;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u > v) swap(u, v);
        edges.insert(1ll * u * n + v);
    }
    
    vector<int> perm;
    for (int i: views::iota(0, n)) perm.push_back(i);
    
    mt19937 rng((ll)main);
    
    if (n <= 8) {
        vector<pair<int, int>> possible_edges;
        for (int u: views::iota(0, n)) for (int v: views::iota(u + 1, n)) {
            ll eid = 1ll * u * n + v;
            if (edges.count(eid)) continue;
            possible_edges.emplace_back(u, v);
        }
        clog << db(possible_edges) << endl;
        
        vector<pair<int, int>> picked;
        vector<int> deg(n);
        function<void(int)> backtrack = [&](int i) {
            clog << db(i) << endl;
            if (i == sz(possible_edges)) {
                clog << db(picked) << endl;
                if (sz(picked) < m) return ;
                for (auto [u, v]: picked) {
                    cout << u  + 1 << ' ' << v + 1 << '\n';
                }
                exit(0);
            }
            
            backtrack(i + 1);
            if (sz(picked) == m) return ;
            auto [u, v] = possible_edges[i];
            if (deg[u] == 2 or deg[v] == 2) return ;
            picked.emplace_back(u, v);
            ++deg[u];
            ++deg[v];
            backtrack(i + 1);
            picked.pop_back();
            --deg[u];
            --deg[v];
        };
        
        backtrack(0);
        cout << "-1\n";
        
        return 0;
    }
    
    const int max_iter = 100;
    bool ok = false;
    for (int _: views::iota(0, max_iter)) {
        ranges::shuffle(perm, rng);
        ok = true;
        for (ll e: edges) {
            int u = perm[e / n];
            int v = perm[e % n];
            if (u > v) swap(u, v);
            ll ne = 1ll * u * n + v;
            if (edges.count(ne)) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    
    if (!ok) {
        cout << "-1\n";
        return 0;
    }
    
    for (ll e: edges) {
        int u = perm[e / n];
        int v = perm[e % n];
        cout << u  + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}