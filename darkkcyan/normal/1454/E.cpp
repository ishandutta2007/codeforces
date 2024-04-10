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

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB(ntest);
        int n; cin >> n;
        vector gr(n + 1, vector<int>());
        rep(i, n) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        vector<int> deg(n + 1);
        queue<int> qu;
        rep1(i, n) {
            deg[i] = len(gr[i]);
            if (deg[i] == 1) qu.push(i);
        }
        
        vector<bool> in_cycle(n + 1, true);
        for (; len(qu); qu.pop()) {
            auto u = qu.front();
            in_cycle[u] = false;
            for (auto v: gr[u]) {
                if (!in_cycle[v]) continue;
                --deg[v];
                if (deg[v] == 1) qu.push(v);
            }
        }
        
        vector<int> cycle;
        rep1(i, n) if (in_cycle[i]) cycle.push_back(i);
        clog << db(cycle) << endl;
        
        function<int(int, int)> dfs = [&](int u, int p) {
            int ans = 1;
            for (auto v: gr[u]) {
                if (v == p) continue;
                ans += dfs(v, u);
            }
            return ans;
        };
        
        llong ans = 0;
        for (auto u: cycle) {
            int total_children = 1;
            for (auto child_u: gr[u]) {
                if (in_cycle[child_u]) continue;
                total_children += dfs(child_u, u);
            }
            clog << db(u) << db(total_children) << endl;
            ans += 1ll * total_children * (total_children - 1);
            ans += 2ll * total_children * (n - total_children);
        }
        // cout << ans << '\n'; 
        ans /= 2;
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker