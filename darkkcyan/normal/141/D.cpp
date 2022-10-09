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

template<class T>
using min_prio = priority_queue<T, vector<T>, greater<>>;

const int maxn = 101010;
const ll inf = (ll)1e15;
int n, l;
int x[maxn], d[maxn], t[maxn], p[maxn];

vector<tuple<int, ll, int>> gr[maxn * 3];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    rep(i, 0, n) {
        cin >> x[i] >> d[i] >> t[i] >> p[i];
    }
    
    vector<int> points;
    rep(i, 0, n) {
        if (x[i] - p[i] < 0) continue;
        points.push_back(x[i] - p[i]);
        points.push_back(x[i] + d[i]);
        int u = sz(points) - 2;
        int v = sz(points) - 1;
        gr[u].emplace_back(v, p[i] + t[i], i + 1);
    }
    
    points.push_back(0);
    points.push_back(l);
    
    vector<int> nodes(sz(points));
    rep(i, 0, sz(nodes)) nodes[i] = i;
    sort(all(nodes), [&](int u, int v) {
            return points[u] < points[v];
            });
    
    rep(i, 0, sz(nodes) - 1) {
        int u = nodes[i], v = nodes[i + 1];
        int dist = points[v] - points[u];
        gr[u].emplace_back(v, dist, 0);
        gr[v].emplace_back(u, dist, 0);
    }
    
    min_prio<pair<ll, int>> prio;
    vector<ll> dist(sz(points), inf);
    vector<pair<int, int>> trace(sz(points), {-1, -1});
    prio.emplace(0, nodes[0]);
    dist[nodes[0]] = 0;
    while (sz(prio)) {
        auto [du, u] = prio.top();
        prio.pop();
        if (du > dist[u]) continue;
        for (auto [v, cost, ramp_id]: gr[u]) {
            ll dv = du + cost;
            if (dv >= dist[v]) continue;
            dist[v] = dv;
            trace[v] = {u, ramp_id};
            prio.emplace(dv, v);
        }
    }
    
    cout << dist.back() << '\n';
    vector<int> used_ramp;
    for (int u = sz(dist) - 1; u >= 0; u = trace[u].first) {
        int r = trace[u].second;
        if (r > 0) used_ramp.push_back(r);
    }
    
    cout << sz(used_ramp) << '\n';
    for (int i = sz(used_ramp); i--; ) cout << used_ramp[i] << '\n';
    
    return 0;
}

// vim: foldmethod=marker