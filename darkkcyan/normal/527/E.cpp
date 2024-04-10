#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int maxn = 101010;
const int maxm = 501010;
int n, m;
vector<pair<int, int>> gr[maxn];

bool used_edge[maxm];
bool vis[maxn];
list<int> euler_walk(int u) {
    DB();
    clog << db(u) << endl;
    list<int> ans;
    ans.push_back(u);
    while (sz(gr[u])) {
        auto [v, eid] = gr[u].back();
        gr[u].pop_back();
        if (used_edge[eid]) continue;
        used_edge[eid] = true;
        ans.push_back(u = v);
    }
    for (auto it = ++ans.begin(); it != ans.end(); ++it) {
        auto t = euler_walk(*it);
        t.pop_back();
        ans.splice(it, t);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        gr[u].emplace_back(v, i);
        gr[v].emplace_back(u, i);
    }
    
    int prev_odd = -1;
    rep(i, 1,  n + 1) {
        if (sz(gr[i]) % 2 == 0) continue;
        if (prev_odd == -1) {
            prev_odd = i;
            continue;
        }
        clog << db(i) << db(prev_odd) << endl;
        gr[i].emplace_back(prev_odd, m);
        gr[prev_odd].emplace_back(i, m);
        prev_odd = -1;
        ++m;
    }
    
    assert(prev_odd == -1);
    
    if (m & 1) {
        gr[1].emplace_back(1, m);
        gr[1].emplace_back(1, m);
        ++m;
    }
    
    cout << m << '\n';
    rep(i, 1, n + 1) {
        if (vis[i]) continue;
        auto ew = euler_walk(i);
        for (auto u: ew) vis[u] = true;
        
        bool alter = false;
        for (auto it = ew.begin(), nxt = next(it); nxt != ew.end(); it = nxt++) {
            if (alter) {
                cout << *nxt << ' ' << *it << '\n';
            } else {
                cout << *it << ' ' << *nxt << '\n';
            }
            alter = !alter;
        }
    }
    
    return 0;
}

// vim: foldmethod=marker