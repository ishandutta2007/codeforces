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

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        int n, m; cin >> n >> m;
        vector gr(n + 1, vector<int>());
        rep(i, m) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        vector<int> depth(n + 1), par(n + 1);
        vector<bool> visited(n + 1);
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto v: gr[u]) {
                if (visited[v]) continue;
                depth[v] = depth[u] + 1;
                par[v] = u;
                dfs(v);
            }
        };
        
        depth[1] = 1;
        dfs(1);
        
        int deepest = (int)(max_element(depth.begin(), depth.end()) - depth.begin());
        if (depth[deepest] >= (n + 1) / 2) {
            cout << "PATH\n";
            vector<int> ans;
            for (int u = deepest; u; u = par[u]) ans.push_back(u);
            cout << len(ans) << '\n';
            for (auto i: ans) cout << i << ' ';
            cout << '\n';
            continue;
        }
        
        cout << "PAIRING\n";
        vector<pair<int, int>> ans;
        vector<int> last_unmatched(n + 1);
        rep1(i, n) {
            if (last_unmatched[depth[i]]) {
                ans.emplace_back(last_unmatched[depth[i]], i);
                last_unmatched[depth[i]] = 0;
            } else last_unmatched[depth[i]] = i;
        }
        
        cout << len(ans) << '\n';
        for (auto [u, v]: ans) cout << u << ' ' << v << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker