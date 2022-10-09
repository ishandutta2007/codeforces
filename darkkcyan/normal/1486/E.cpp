#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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
const int max_val = 52;
const ll inf = 1e15;
template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

int n, m;
vector<pair<int, ll>> gr[maxn];

vector<ll> stupid() {
    vector<ll> dist(n + 1, inf);
    
    min_pq<pair<ll, int>> prio;
    for (dist[1] = 0, prio.emplace(0, 1); prio.size(); ) {
        auto [d, u] = prio.top();
        prio.pop();
        if (dist[u] < d) continue;
        for (auto [mid, wm]: gr[u]) {
            for (auto [v, wv]: gr[mid]) {
                ll nd = d + (wm + wv) * (wm + wv);
                if (nd >= dist[v]) continue;
                prio.emplace(nd, v);
                dist[v] = nd;
            }
        }
    }
    
    return dist;
}

vector<ll> solve() {
    vector<ll> dist(n + 1, inf);
    vector<vector<ll>> base_val(n + 1, vector<ll>(max_val, inf));
    vector<vector<ll>> base_ans(n + 1, vector<ll>(max_val, inf));
    
    min_pq<pair<ll, int>> prio;
    dist[1] = 0;
    prio.emplace(0, 1);
    
    while (prio.size()) {
        auto [d, u] = prio.top();
        prio.pop();
        if (dist[u] < d) continue;
        for (auto [mid, wm]: gr[u]) {
            if (base_val[mid][wm] <= d) continue;
            base_val[mid][wm] = d;
            rep1(i, max_val - 1) 
                base_ans[mid][i] = d + (wm + i) * (wm + i);
            
            for (auto [v, wv]: gr[mid]) {
                ll nd = base_ans[mid][wv];
                if (nd >= dist[v]) continue;
                prio.emplace(nd, v);
                dist[v] = nd;
            }
        }
    }
    return dist;
}

void print_ans(ostream& out, const vector<ll>& dist) {
    rep1(i, n) {
        if (dist[i] >= inf) out << -1 << ' ';
        else out << dist[i] << ' ';
    }
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        gr[u].emplace_back(v, c);
        gr[v].emplace_back(u, c);
    }
    // auto exp = stupid(); 
    // print_ans(cout, exp); 
    auto ans = solve();
    print_ans(cout, ans);
    
    return 0;
}

// vim: foldmethod=marker