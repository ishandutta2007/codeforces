#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
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

enum State {
    cross_max = 1, cross_min = 2
};

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const llong inf = (llong) 1e15;
const int maxn = 201010;
int n, m;
vector<pair<llong, int>> gr[maxn * 4];

void add_edge(int u, int v, llong cost) {
    u <<= 2;
    v <<= 2;
    rep(state, 4) 
        gr[u | state].emplace_back(cost, v | state);
    
    for (auto state: {0, (int)cross_min}) 
        gr[u | state].emplace_back(0, v | state | cross_max);
    
    for (auto state: {0, (int)cross_max}) 
        gr[u | state].emplace_back(2 * cost, v | state | cross_min);
    gr[u].emplace_back(cost, v | 3);
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
        int u, v, c; cin >> u >> v >> c;
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    
    vector<llong> dist(4 * n + 5, inf);
    dist[1 << 2] = 0;
    min_pq<pair<llong, int>> prio;
    for (prio.emplace(0, 1 << 2); prio.size(); ) {
        auto [d, u] = prio.top();
        prio.pop();
        if (d > dist[u]) continue;
        clog << db(u) << db(d) << endl;
        for (auto [cost, v]: gr[u]) {
            llong new_d = d + cost;
            if (new_d >= dist[v]) continue;
            dist[v] = new_d;
            prio.emplace(new_d, v);
        }
    }
    
    for (int u = 2; u <= n; ++u) {
        cout << dist[u << 2 | 3] << ' ';
    }
    
    
    return 0;
}

// vim: foldmethod=marker