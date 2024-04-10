#include <bits/stdc++.h>
using namespace std;
 
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
 
int main() {
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
        
        vector<vector<int>> gr(n);
        rep(i, 0, n) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        
        bool ok = ([&] () -> bool {
            for (const auto& i: gr) {
                if (i.size() > 2) return false;
            }
            
            vector<bool> vis(n);
            rep(start, 0, n) {
                if (vis[start]) continue;
                if (gr[start].size() != 1) continue;
                
                vis[start] = true;
                int prv = start;
                int nxt = gr[start][0];
                while (gr[nxt].size() == 2) {
                    vis[nxt] = true;
                    tie(prv, nxt) = make_pair(nxt, gr[nxt][0] ^ gr[nxt][1] ^ prv);
                }
            }
            
            rep(start, 0, n) {
                if (vis[start]) continue;
                if (gr[start].size() != 2) continue;
                
                int prv = start, nxt = gr[start][0];
                int len = 0;
                while (!vis[nxt]) {
                    vis[nxt] = true;
                    ++len;
                    tie(prv, nxt) = make_pair(nxt, gr[nxt][0] ^ gr[nxt][1] ^ prv);
                }
                if (len & 1) return false;
            }
            
            return true;
        })();
        
        cout << (ok ? "YES\n" : "NO\n");
    }
    
    return 0;
}