#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y
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
template<class A, class B, class C, class D>
ostream& operator<<(ostream& out, const tuple<A, B, C, D>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t), get<3>(t)) << ")"; }
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
int n, x, y;
int a[maxn];
vector<int> pos[maxn];

struct cmp_len_pos {
    bool operator()(int u, int v) const {
        if (len(pos[u]) == len(pos[v])) return u < v;
        return len(pos[u]) < len(pos[v]);
    }
};

optional<vector<int>> solve() {
    DB("test");
    cin >> n >> x >> y;
    rep1(i, n + 1) pos[i].clear();
    rep(i, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    int untouched = 1;
    while (len(pos[untouched])) ++untouched;
    
    vector<int> ans(n, untouched);
    
    set<int, cmp_len_pos> prio;
    rep1(i, n + 1) if (len(pos[i])) prio.insert(i);
    
    int need_save = x, need_rem = n - y, need_sw = y - x;
    int mx = 1;
    rep1(i, n + 1) if (len(pos[mx]) < len(pos[i])) mx = i;
    
    while (need_save --) {
        int u = *--prio.end();
        prio.erase(u);
        deb(u);
        ans[pos[u].back()] = u;
        pos[u].pop_back();
        if (len(pos[u])) prio.insert(u);
    }
    
    rep1(i, n + 1) deb(pos[i]);
    
    int rest = n - x;
    while (rest and len(pos[*--prio.end()]) * 2 > rest) {
        if (!need_rem) return {};
        int u = *--prio.end();
        prio.erase(u);
        // ans[pos[u].back()] = u; 
        pos[u].pop_back();
        if (len(pos[u])) prio.insert(u);
        --need_rem;
        --rest;
    }
    
    clog << endl;
    rep1(i, n + 1) deb(pos[i]);
    
    vector<int> need_sw_pos;
    rep1(i, n + 1) {
        for (auto p: pos[i]) need_sw_pos.push_back(p);
    }
    
    int l = len(need_sw_pos);
    rep(i, l) {
        ans[need_sw_pos[i]] = a[need_sw_pos[(i + l/ 2) % l]];
    }
    rep(i, need_rem) ans[need_sw_pos[i]] = untouched;
    
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest ;cin >> ntest;
    while (ntest--) {
        if (auto ans = solve()) {
            cout << "YES\n";
            for (auto i: *ans) cout << i << ' ';
            cout << '\n';
        } else cout << "NO\n";
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker