#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 3030;
const int maxm = maxn * maxn;
int n, m;
vector<pair<int, int>> gr[maxn];
int adj[maxn][maxn];

int used[maxm];
int ptr[maxn];
int ptr_used[maxn];
int timer = 1;

inline void upd_ptr(int u) {
    if (ptr_used[u] != timer) {
        ptr[u] = 0;
        ptr_used[u] = timer;
    }
}
list<int> euler_path(int u) {
    upd_ptr(u);
    if (ptr[u] == len(gr[u])) return {u};
    // clog << u << endl; 
    list<int> ans;
    while (ptr[u] < len(gr[u])) {
        auto& [v, eid] = gr[u][ptr[u]++];
        if (used[eid] == timer) {
            continue;
        }
        used[eid] = timer;
        ans.push_back(u);
        u = v;
        upd_ptr(u);
        // clog << u << ' ' << eid << endl; 
    }
    ans.push_back(u);
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        auto nxt_tour = euler_path(*it);
        nxt_tour.pop_back();
        ans.splice(it, nxt_tour);
    }
    return ans;
}



int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>m;
    memset(adj, -1, sizeof(adj));
    rep(i, m) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = i;
        gr[u].emplace_back(v, i);
        gr[v].emplace_back(u, i);
    }
    
    vector<int> odd_nodes;
    rep1(i, n) if (len(gr[i]) & 1) odd_nodes.push_back(i);
    clog << db(odd_nodes) << endl;
    if (len(odd_nodes) <= 2) {
        int start = len(odd_nodes) ? odd_nodes[0] : 1;
        auto ans = euler_path(start);
        cout << len(ans) << '\n';
        for (auto i: ans) cout << i << ' ';
        return 0;
    }
    
    list<int> ans;
    
    rep1(i, n) {
        DB();
        clog << db(i) << endl;
        vector<int> odd_adj, rest_odd;
        for (auto u: odd_nodes) {
            if (i == u) continue;
            if (adj[i][u] >= 0) odd_adj.push_back(u);
            else rest_odd.push_back(u);
        }
        clog << db(odd_adj) << endl;
        clog << db(rest_odd) << endl;
        if (len(rest_odd) > 1) continue;
        auto try_path = [&](int start) -> bool {
            clog << db(start) << endl;
            ++timer;
            bool start_is_adj = false;
            for (auto u: odd_adj) {
                if (u == start) {
                    start_is_adj = true;
                    continue;
                }
                used[adj[i][u]] = timer;
            }
            ans = euler_path(start);
            clog << db(ans) << endl;
            int cnt_edges = m - (len(odd_adj) - start_is_adj);
            clog << db(cnt_edges) << db(len(ans)) << endl;
            if (len(ans) < cnt_edges + 1) {
                ans.clear();
                return false;
            }
            ans.push_back(-1);
            for (auto u: odd_adj) {
                if (u == start) continue;
                ans.push_back(u);
                ans.push_back(i);
            }
            return true;
        };
        if (len(rest_odd) == 1) {
            if (try_path(rest_odd[0])) break;
            continue;
        } 
        if (try_path(i)) break;
        for (auto u: odd_adj) {
            if (try_path(u)) {
                break;
            }
        }
        if (len(ans)) break;
    }
    cout << len(ans) << '\n';
    for (auto i: ans) cout << i << ' ';
    
    return 0;
}

// vim: foldmethod=marker