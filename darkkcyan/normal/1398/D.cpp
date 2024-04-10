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

const int maxn = 222;
const llong inf = 2010 * 2010 * maxn;
llong dp[maxn][maxn][maxn];

void maximize(llong& u, llong v) {
    if (u < v) {
        u = v;
        deb(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sz[3]; rep(i, 3) cin >> sz[i];
    vector<vector<llong>> a(3);
    rep(i, 3) {
        a[i].resize(sz[i]);
        for (auto& x: a[i]) cin >> x;
        sort(a[i].rbegin(), a[i].rend());
    }
    
    rep(i, sz[0] + 1) rep1(f, sz[1] + 1) rep1(g, sz[2] + 1) 
        dp[i][f][g] = -inf;
    dp[0][0][0] = 0;
    
    int it[3] = {0, 0, 0};
    llong ans = 0;
    
    for (; it[0] <= sz[0]; ++it[0])
    for (it[1] = 0; it[1] <= sz[1]; ++it[1])
    for (it[2] = 0; it[2] <= sz[2]; ++it[2]) {
        llong cur = dp[it[0]][it[1]][it[2]];
        maximize(ans, cur);
        rep(u, 3) for (int v = u + 1; v < 3; ++v) {
            if (it[u] < sz[u] and it[v] < sz[v]) {
                llong area = a[u][it[u]] * a[v][it[v]];
                ++it[u]; ++it[v];
                maximize(dp[it[0]][it[1]][it[2]], cur + area);
                --it[u]; --it[v];
            }
        }
    }
    
    cout << ans;

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker