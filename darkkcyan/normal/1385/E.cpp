#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const int maxn = 202020;
int n, m;
vector<int> digr[maxn], gr[maxn];

int state[maxn];
vector<int> topo;
bool dfs(int u) {
    state[u] = 1;
    for (auto v: digr[u]) {
        if (state[v] == 2) continue;
        if (state[v] == 1) return true;
        if (dfs(v)) return true;
    }
    state[u] = 2;
    topo.push_back(u);
    return false;
}

int vis_order[maxn];
bool solve() {
    cin >> n >> m;
    rep1(i, n) {
        gr[i].clear();
        digr[i].clear();
        state[i] = 0;
        vis_order[i] = -1;
    }
    
    rep(i, m) {
        int t, u, v; cin >> t >> u >> v;
        if (t) digr[u].push_back(v);
        else {
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
    }
    topo.clear();
    rep1(i, n) {
        if (state[i] == 2) continue;
        if (dfs(i)) return false;
    }
    rep(i, len(topo)) {
        vis_order[topo[i]] = i;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        if (!solve()) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep1(u, n) {
            for (auto& g: {gr[u]}) for (auto v: g) {
                if (vis_order[u] > vis_order[v]) cout << u << ' ' << v << '\n';
            }
            for (auto v: digr[u]) cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker