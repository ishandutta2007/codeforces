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
    while (ntest--){ 
        DB("test");
        int n; llong m;  cin >> n >> m;
        vector<llong> cnt(n + 1), h(n + 1);
        vector<vector<int>> gr(n + 1);
        rep1(i, n) cin >> cnt[i];
        rep1(i, n) cin >> h[i];
        rep(i, n - 1) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        bool ans = true;
        vector<llong> new_cnt(n + 1);
        vector<llong> good(n + 1), bad(n + 1), sum_child_good(n + 1), sum_child_bad(n + 1);
        function<void(int, int)> dfs = [&](int u, int p) {
            new_cnt[u] = cnt[u];
            for (auto v: gr[u]) {
                if (v == p) continue;
                dfs(v, u);
                new_cnt[u] += new_cnt[v];
                sum_child_good[u] += good[v];
                sum_child_bad[u] += bad[v];
            }
            
            if ((h[u] + new_cnt[u]) & 1) {
                ans = false;
            } else {
                good[u] = (h[u] + new_cnt[u]) / 2;
                bad[u] = new_cnt[u] - good[u];
                if (good[u] > new_cnt[u] or bad[u] > new_cnt[u]) ans = false;
                if (good[u] < 0 or bad[u] < 0) ans = false;
                llong min_change = max(0ll, sum_child_bad[u] - bad[u]);
                if (sum_child_good[u] > good[u] - min_change) {
                    ans = false;
                }
            }
        };
        
        dfs(1, 1);
        deb(ans);
        deb(good);
        deb(bad);
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker