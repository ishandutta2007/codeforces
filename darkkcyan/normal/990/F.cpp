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

const int maxn = 201010;
int n, m;
ll a[maxn];
ll flow[maxn];
vector<pair<int, int>> gr[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    if (accumulate(a + 1, a + n + 1, 0ll)) {
        cout << "Impossible";
        // perhaps the archives are incomplete
        return 0;
    }
    cout << "Possible\n";
    cin >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        gr[u].emplace_back(v, 2 * i);
        gr[v].emplace_back(u, 2 * i + 1);
    }
    
    vector<int> p(n + 1, -1);
    vector<int> up_eid(n + 1);
    p[1] = 1;
    vector<int> qu = {1};
    rep(i, 0, sz(qu)) {
        int u = qu[i];
        for (auto [v, eid]: gr[u]) {
            if (p[v] != -1) continue;
            p[v] = u;
            up_eid[v] = eid;
            qu.push_back(v);
        }
    }
    assert(find(1 + all(p), -1) == p.end()); // guaranteed that all nodes are connected.
    
    reverse(all(qu));
    qu.pop_back();
    for (auto u: qu) {
        clog << db(u) << db(p[u]) << db(a[u]) << endl;
        int eid = up_eid[u] / 2;
        int ori = up_eid[u] % 2;
        flow[eid] = ori ? -a[u] : a[u];
        a[p[u]] += a[u];
    }
    
    rep(i, 0, m) {
        cout << flow[i] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker