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

const int maxn = 101010;
int n, m, k;
vector<int> gr[maxn];
int depth[maxn];
int par[maxn];

void find_ans(int u, int l, int sl) {
    vector<int> ans = {u};
    for (; sl != l; sl = par[sl])
        ans.push_back(sl);
    ans.push_back(l);
    if (len(ans) <= k) {
        cout << "2\n";
        cout << len(ans) << '\n';
        for (auto i: ans) cout << i << ' ';
    } else {
        cout << "1\n";
        for (int i = 0, cnt = (k + 1) / 2; cnt--; i += 2) {
            cout << ans[i] << ' ';
        }
    }
    exit(0);
}

void dfs(int u) {
    depth[u] = depth[par[u]] + 1;
    int lowest = par[u], second_lowest = par[u];
    for (auto v: gr[u]) {
        if (depth[v] == -1) continue;
        int temp = v;
        if (depth[temp] < depth[lowest]) swap(temp, lowest);
        if (depth[temp] < depth[second_lowest]) swap(temp, second_lowest);
    }
    if (lowest != par[u]) {
        find_ans(u, lowest, second_lowest);
    }
    for (auto v: gr[u]) {
        if (depth[v] != -1) continue;
        par[v] = u;
        dfs(v);
    }
}

int dp[maxn][2];
void find_max_cover(int u) {
    depth[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (auto v: gr[u]) {
        if (v == par[u]) continue;
        find_max_cover(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int cnt = 0;
void print_cover(int u, int state) {
    if (state == 1) {
        cout << u << ' ';
        --cnt;
        if (cnt == 0) exit(0);
        for (auto v: gr[u]) {
            if (v == par[u]) continue;
            print_cover(v, 0);
        }
    } else {
        for (auto v: gr[u]) {
            if (v == par[u]) continue;
            print_cover(v, dp[v][0] < dp[v][1]);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    rep(_, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    rep1(i, n) {
        if (depth[i] != -1) continue;
        depth[i] = 0;
        par[i] = i;
        dfs(i);
    }

    memset(depth, -1, sizeof(depth));
    cout << "1\n";
    cnt = (k + 1) / 2;
    rep1(i, n) {
        if (depth[i] != -1) continue;
        find_max_cover(i);
        print_cover(i, dp[i][0] < dp[i][1]);
    }

    return 0;
}

// Remember:
// - Multitest? Refreshing data!!!
// vim: foldmethod=marker