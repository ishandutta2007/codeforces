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
        vector<string> s(n);
        int cnt1 = 0;
        for (auto& row: s) {
            cin >> row;
            cnt1 += (int)(count(all(row), '1'));
        }
        rep(i, 0, n) s.push_back(s[i]);
        for (auto& row: s) row += row;
        
        int ans = INT_MAX;
        auto upd_ans = [&](int diag1) {
            ans = min(ans, (n - diag1) + (cnt1 - diag1));
        };
        
        auto solve_corner = [&](int r, int c) {
            int diag1 = 0;
            rep(i, 0, n) {
                diag1 += s[r + i][c + i] == '1';
            }
            upd_ans(diag1);
            rep(i, n, 2 * n) {
                if (r + i >= 2 * n or c + i >= 2 * n) break;
                diag1 += s[r + i][c + i] == '1';
                diag1 -= s[r + i - n][c + i - n] == '1';
                upd_ans(diag1);
            }
        };
        rep(i, 0, n) {
            solve_corner(i, 0);
            solve_corner(0, i);
        }
        cout << ans << '\n';
    }
    
    return 0;
}