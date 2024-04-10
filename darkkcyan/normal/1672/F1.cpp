#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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
 
int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        rep(i, 0, n) {
            int x;
            cin >> x;
            a[i] = x;
            pos[x].push_back(i);
        }
        
        int mx_val = 0;
        rep(i, 1, n + 1) {
            if (sz(pos[i]) > sz(pos[mx_val])) mx_val = i;
        }
        
        int mx_sz = sz(pos[mx_val]);
        vector<vector<int>> groups(mx_sz);
        rep(i, 0, mx_sz) {
            groups[i].push_back(pos[mx_val][i]);
        }
        
        int cur = 0;
        rep(v, 1, n + 1) {
            if (v == mx_val) continue;
            rep(i, 0, sz(pos[v])) {
                groups[cur].push_back(pos[v][i]);
                ++cur;
                if (cur == mx_sz) cur = 0;
            }
        }
        
        vector<int> ans(n);
        for (auto& g: groups) {
            if (sz(g) == 1) {
                ans[g[0]] = a[g[0]];
                continue;
            }
            int prv = sz(g) - 1;
            rep(i, 0, sz(g)) {
                ans[g[prv]] = a[g[i]];
                prv = i;
            }
        }
        for (auto i: ans) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}