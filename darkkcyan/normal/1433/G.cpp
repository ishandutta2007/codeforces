#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////


const int maxn = 1111;
const int maxk = 1111;
const int inf = (int)1e8;
int n, m, k;
vector<pair<int, int>> gr[maxn];
int a[maxk], b[maxk];

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

vector<int> min_cost(int source) {
    vector<int> dist(n + 1, inf);
    dist[source] = 0;
    min_pq<pair<int, int>> prio;
    prio.emplace(0, source);
    while (len(prio)) {
        int u = prio.top().second;
        int cur_dist = prio.top().first;
        prio.pop();
        if (cur_dist > dist[u]) continue;
        for (auto [v, d]: gr[u]) {
            int new_cost = dist[u] + d;
            if (new_cost >= dist[v]) continue;
            dist[v] = new_cost;
            prio.emplace(new_cost, v);
        }
    }
    return dist;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        gr[u].emplace_back(v, w);
        gr[v].emplace_back(u, w);
    }
    rep(i, k) cin >> a[i] >> b[i];
    
    vector<vector<int>> dist(n + 1);
    rep1(i, n) dist[i] = min_cost(i);
    
    llong ans = 0;
    rep(i, k) ans += dist[a[i]][b[i]];
    rep1(u, n) {
        for (auto [v, _]: gr[u]) {
            llong cur_ans = 0;
            rep(i, k) {
                cur_ans += min({dist[a[i]][b[i]], dist[a[i]][u] + dist[b[i]][v], dist[a[i]][v] + dist[b[i]][u]});
            }
            ans = min(ans, cur_ans);
        }
    }
    cout << ans;

    
    return 0;
}

// vim: foldmethod=marker