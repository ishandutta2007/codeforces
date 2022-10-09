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

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
const int maxn = 202020;
const int maxm = maxn;
const llong mod = (llong)998244353;
const int limit_depth = 30;
int n, m;
vector<int> gr[maxn], rgr[maxn];

struct Cost {
    int cnt_trans;
    int cnt_edges;
    Cost(int t = 0, int e = 0): cnt_trans(t), cnt_edges(e)  {}
    
    static Cost inf() {
        return Cost(maxm, maxm);
    }
    
    bool is_small() const {
        return cnt_trans < limit_depth;
    }
    
    llong true_cost() const {
        return (1ll << cnt_trans) + cnt_edges - 1;
    }
    
    llong true_cost_mod() const {
        llong ans = 1;
        rep(i, cnt_trans) {
            ans += ans;
            if (ans >= mod) ans -= mod;
        }
        ans += cnt_edges - 1;
        while (ans >= mod) ans -= mod;
        while (ans < 0) ans += mod;
        return ans;
    }
    
    friend bool operator<(const Cost& u, const Cost& v) {
        if (u.is_small() != v.is_small()) {
            return u.is_small();
        }
        if (u.is_small()) {
            if (u.true_cost() == v.true_cost()) return u.cnt_trans < v.cnt_trans;
            return u.true_cost() < v.true_cost();
        }
        if (u.cnt_trans == v.cnt_trans) return u.cnt_edges < v.cnt_edges;
        return u.cnt_trans < v.cnt_trans;
    }
    
    friend ostream& operator<<(ostream& out, const Cost& u ) {
        return out << "(" << u.cnt_trans << ", " << u.cnt_edges << ")";
    }
};

Cost cost[maxn][limit_depth + 1][2];

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        rgr[v].push_back(u);
    }
    
    min_pq <tuple<Cost, int, int, bool>> prio;
    
    rep1(i, n) rep(l, limit_depth + 1) rep(f, 2) cost[i][l][f] = Cost::inf();
    cost[1][0][0] = Cost(0, 0);
    prio.emplace(cost[1][0][0], 1, 0, 0);
    
    while (len(prio)) {
        auto [c, u, cur_trans, s] = prio.top();
        prio.pop();
        if (cost[u][cur_trans][s] < c) continue;
        auto& cur_gr = s ? rgr : gr;
        
        auto new_cost = Cost(c.cnt_trans, c.cnt_edges + 1);
        for (auto v: cur_gr[u]) {
            if (!(new_cost < cost[v][cur_trans][s])) continue;
            cost[v][cur_trans][s] = new_cost;
            prio.emplace(cost[v][cur_trans][s], v, cur_trans, s);
        }
        
        new_cost = Cost(c.cnt_trans + 1, c.cnt_edges);
        int new_trans = min(limit_depth, cur_trans + 1);
        if (new_cost < cost[u][new_trans][!s]) {
            cost[u][new_trans][!s] = new_cost;
            prio.emplace(cost[u][new_trans][!s], u, new_trans, !s);
        }
    }
    
    Cost ans = Cost::inf();
    rep(l, limit_depth + 1) {
        ans = min({ans, cost[n][l][0], cost[n][l][1]});
    }
    cout << ans.true_cost_mod() << '\n';
    
    return 0;
}

// vim: foldmethod=marker