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

const int maxn = 101010;
int n, m;
vector<int> gr[maxn];

int vis[maxn], timer;
bool comp_vis[maxn];
int dist[maxn];

vector<int> qu;
int bfs(int u) {
    ++timer;
    dist[u] = 0;
    qu.clear();
    qu.push_back(u);
    vis[u] = timer;
    for (int i = 0; i < sz(qu); ++i) {
        u = qu[i];
        comp_vis[u] = true;
        for (auto v: gr[u]) {
            if (vis[v] == timer) {
                if ((dist[v] ^ dist[u]) & 1) continue;
                return -1;
            }
            vis[v] = timer;
            dist[v] = dist[u] + 1;
            qu.push_back(v);
        }
    }
    return dist[u];
}

int process_comp(int u) {
    int ans = bfs(u);
    if (ans == -1) return -1;
    auto comp = qu;
    for (auto v: comp) {
        int cur_ans = bfs(v);
        if (cur_ans == -1) return -1;
        ans = max(ans, bfs(v));
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    int ans = 0;
    rep(i, 1, n + 1) {
        if (comp_vis[i]) continue;
        int cur_ans = process_comp(i);
        clog << db(i) << db(cur_ans) << endl;
        if (cur_ans == -1) {
            ans = -1;
            break;
        }
        ans += cur_ans;
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker