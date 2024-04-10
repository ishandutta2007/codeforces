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

const int maxk = 20;
const int maxn = 501010;
bool removed[maxn];

struct edge {
    int id;
    int v;
    
    edge(int id_, int v_): id(id_), v(v_) {}
    bool is_removed() { return removed[id]; }
    void set_remove() {
        removed[id] = true;
    }
};

ostream& operator<<(ostream& out, const edge& u) {
    return out << "edge(" << u.id << ", " << u.v << ")";
}

list<edge> euler_cycle(vector<vector<edge>>& gr, int u) {
    list<edge> ans;
    while (true) {
        deb(u);
        while (len(gr[u]) and gr[u].back().is_removed()) gr[u].pop_back();
        if (!len(gr[u])) break;
        gr[u].back().set_remove();
        ans.push_back(gr[u].back());
        u = gr[u].back().v;
    }
    
    for (auto it = ans.begin(); it != ans.end(); ) {
        u = it->v;
        ++it;
        ans.splice(it, euler_cycle(gr, u));
    }
    return ans;
}

int n;
pair<int, int> edges[maxn];

bool is_connected(const vector<vector<edge>>& gr) {
    int cnt_single = 0;
    rep(i, len(gr)) cnt_single += len(gr[i]) == 0;
    
    vector<bool> visited(len(gr));
    int start = 0;
    while (len(gr[start]) == 0) ++start;
    
    visited[start] = true;
    int cnt_vis = 1;
    queue<int> qu;
    for (qu.push(start); qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto it: gr[u]) {
            int v = it.v;
            if (visited[v]) continue;
            visited[v] =true;
            ++cnt_vis;
            qu.push(v);
        }
    }
    return cnt_vis == len(gr) - cnt_single;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> edges[i].first >> edges[i].second;
    
    int ans = 0;
    vector<vector<edge>> gr, prev_gr;
    for (int k = 0; k <= maxk; ++k) {
        DB(""; deb(k));
        prev_gr = gr;
        gr.clear();
        deb(prev_gr);
        int mask = (1 << k) - 1;
        gr.resize(mask + 1);
        rep(i, n) {
            int u = edges[i].first & mask;
            int v = edges[i].second & mask;
            gr[u].emplace_back(i, v);
            gr[v].emplace_back(i, u);
        }
        
        deb(gr);
        if (!is_connected(gr)) break;
        clog << "connected " << endl;
        bool has_odd_node = false;
        rep(i, len(gr)) if (len(gr[i]) & 1) {
            has_odd_node = true;
            break;
        }
        deb(has_odd_node);
        if (has_odd_node) break;
        ans = k;
    }
    
    
    deb(ans);
    cout << ans << '\n';
    int start = 0;
    deb(prev_gr);
    while (len(prev_gr[start]) == 0) ++start;
    deb(start);
    int mask = (1 << ans) - 1;
    for (auto i: euler_cycle(prev_gr, start)) {
        int tail = i.v;
        int u = 2 * i.id + 1;
        int v = 2 * i.id + 2;
        if ((edges[i.id].first & mask) == tail)
            swap(u, v);
        cout << u << ' ' << v << ' ';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker