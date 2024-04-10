// vim: foldmethod=marker
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
#define clog cerr << string(max(__db_level * 2, 0), ' ')
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
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first, p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t), get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t), get<1>(t), get<2>(t) << ")"; }
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

const int maxn = 88;
const llong inf = (llong)1e15;
int n, k;
llong dist[maxn][maxn];
vector<pair<llong, int>> min_dist[maxn][maxn];

int excluded[maxn] = {0};
inline llong find_min(llong from, llong to) {
    rep(i, len(min_dist[from][to])) {
        if (excluded[min_dist[from][to][i].second]) continue;
        return min_dist[from][to][i].first;
    }
    // assert(false); 
    return inf;
}

vector<int> nodes;
llong backtrack(int i = 0) {
    if (i >= k / 2 - 1) {
        llong ans = find_min(nodes.back(), 0);
        rep(cur, len(nodes) - 1) {
            ans += find_min(nodes[cur], nodes[cur + 1]);
        }
        return ans;
    }
    llong ans = inf;
    rep(u, n) {
        ++excluded[u];
        nodes.push_back(u);
        ans = min(ans, backtrack(i + 1));
        nodes.pop_back();
        --excluded[u];
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(u, n) rep(v, n) {
        cin >> dist[u][v];
    }

    rep(u, n) rep(v, n) {
        rep(i, n) if (i != u and i != v) min_dist[u][v].emplace_back(dist[u][i] + dist[i][v], i);
        sort(min_dist[u][v].begin(), min_dist[u][v].end());
    }

    excluded[0] = 1;
    nodes.push_back(0);
    cout << backtrack();

    return 0;
}