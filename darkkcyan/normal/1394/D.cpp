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

const int maxn = 201010;
int n;
llong t[maxn], h[maxn];
vector<int> gr[maxn];

llong ans = 0;
int cnt_in[maxn], cnt_out[maxn];
llong dp_up[maxn], dp_down[maxn];

bool vis[maxn];
void dfs(int u, int p) {
    vis[u] = true;
    
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (h[u] == h[v]) {
            dfs(v, u);
        } else if (h[u] < h[v]) ++cnt_out[u];
        else ++cnt_in[u];
    }

    vector<llong> vals;
    llong sum_up = 0;
    for (auto v: gr[u]) {
        if (v == p or h[u] != h[v]) continue;
        sum_up += dp_up[v];
        vals.push_back(dp_down[v] - dp_up[v]);
    }
    
    sort(vals.rbegin(), vals.rend());
    bool not_root = u != p;
    dp_up[u] = 0;
    dp_down[u] = 0;
    deb(vals);
    rep(cur_down, len(vals) + 1) {
        int cur_up = len(vals) - cur_down;
        deb(cur_down, cur_up);
        dp_up[u] = max(dp_up[u], sum_up + t[u] * min(not_root + cnt_out[u] + cur_down, cur_up + cnt_in[u]));
        dp_down[u] = max(dp_down[u], sum_up + t[u] * min(cnt_out[u] + cur_down, cur_up + cnt_in[u] + not_root));
        if (cur_down < len(vals)) sum_up += vals[cur_down];
    }
    
    deb(u, p, dp_up[u], dp_down[u]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) cin >> t[i];
    rep1(i, n) cin >> h[i];
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        ans += t[u] + t[v];
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    rep1(i, n) {
        if (vis[i])continue;
        dfs(i, i);
        ans -= dp_up[i];
    }
    
    cout << ans;
    

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker