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

const int maxn = 101010;
const int inf = maxn;
int n, m;
vector<int> gr[maxn];

vector<int> shortest_path(int u) {
    vector<int> ans(n + 1, inf);
    ans[u] = 0;
    queue<int> qu;
    for (qu.push(u); qu.size(); qu.pop()) {
        u = qu.front();
        for (auto v: gr[u]) {
            if (ans[v] != inf) continue;
            ans[v] = ans[u] + 1;
            qu.push(v);
        }
    }
    return ans;
}

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
        if (u == v) continue;
        gr[u].push_back(v);
    }
    vector<vector<int>> dist(n + 1);
    rep(u, 1, n + 1) dist[u] = shortest_path(u);
    
    vector<vector<pair<int, int>>> top_forw(n + 1), top_back(n + 1);
    rep(u, 1, n + 1) {
        rep(v, 1, n + 1) {
            if (u == v) continue;
            if (dist[u][v] != inf) top_forw[u].emplace_back(dist[u][v], v);
            if (dist[v][u] != inf) top_back[u].emplace_back(dist[v][u], v);
            if (top_forw[u].size() > 4) {
                sort(all(top_forw[u]),greater<>());
                top_forw[u].pop_back();
            }
            if (top_back[u].size() > 4) {
                sort(all(top_back[u]), greater<>());
                top_back[u].pop_back();
            }
        }
        clog << db(u) << endl;
        clog << db(dist[u]) << endl;
        clog << db(top_forw[u]) << endl;
        clog << db(top_back[u]) << endl;
    }
    
    tuple<int, int, int, int, int> ans {-1, 0, 0, 0, 0};
    rep(u, 1, n + 1) {
        rep(v, 1, n + 1) {
            if (u == v) continue;
            if (dist[u][v] == inf) continue;
            for (auto [d1, x]: top_back[u]) {
                if (x == v) continue;
                for (auto [d2, y]: top_forw[v]) {
                    if (x == y or u == y) continue;
                    ans = max(ans, {d1 + dist[u][v] + d2, x, u, v, y});
                }
            }
        }
    }
    assert(get<0>(ans) != inf);
    clog << db(ans) << endl;
    cout << get<1>(ans) << ' ';
    cout << get<2>(ans) << ' ';
    cout << get<3>(ans) << ' ';
    cout << get<4>(ans) << ' ';
                
    
    return 0;
}

// vim: foldmethod=marker