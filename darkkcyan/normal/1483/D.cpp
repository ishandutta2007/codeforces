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

const int maxn = 606;
const int max_q = maxn * (maxn + 1) / 2;
const ll inf = 1e16;

struct Trip {
    int u, v;
    ll w;
};
int n, m, q;
ll min_dist[maxn][maxn];
Trip trip[max_q];
vector<Trip> edges;

ll max_half[maxn][maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep1(i, n) rep1(f, n) if (i != f) min_dist[i][f] = inf;
    
    rep(i, m) {
        int u, v, c; cin >> u >> v >> c;
        min_dist[u][v] = min_dist[v][u] = c;
        edges.push_back({u, v, (ll)c});
    }
    
    cin >> q;
    rep(i, q) cin >> trip[i].u >> trip[i].v >> trip[i].w;
    
    rep1(mid, n)
        rep1(u, n) rep1(v, n)
        min_dist[u][v] = min(min_dist[u][v], min_dist[u][mid] + min_dist[mid][v]);
    
    rep(i, q) {
        int u = trip[i].u;
        int v = trip[i].v;
        rep1(x, n) {
            max_half[x][u] = max(max_half[x][u], trip[i].w - min_dist[v][x]);
            max_half[x][v] = max(max_half[x][v], trip[i].w - min_dist[u][x]);
        }
    }
    
    int ans = 0;
    rep(i, m) {
        int u = edges[i].u, v = edges[i].v;
        ll w = edges[i].w;
        bool ok = false;
        rep1(x, n) {
            if (max_half[u][x] >= min_dist[v][x] + w) {
                ok = true;
                break;
            }
            if (max_half[v][x] >= min_dist[u][x] + w) {
                ok = true;
                break;
            }
        }
        ans += ok;
    }
    
    cout << ans;
    return 0;
}

// vim: foldmethod=marker