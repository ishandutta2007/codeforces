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
        DB();
        int n, d;
        cin >> n >> d;
        vector<int> pos(n + 2);
        pos.back() = d + 1;
        rep(i, 1, n + 1) cin >> pos[i];
        if (n == 1) {
            cout << d - 1 << '\n';
            continue;
        }
        multiset<int> lengths;
        rep(i, 1, n + 1) lengths.insert(pos[i] - pos[i - 1] - 1);
        
        clog << db(lengths) << endl;
        
        ll ans = *lengths.begin();
        rep(i, 1, n) {
            clog << db(i) << endl;
            int u = pos[i] - pos[i - 1] - 1;
            int v = pos[i + 1] - pos[i] - 1;
            int new_l = u + 1 + v;
            lengths.erase(lengths.find(u));
            lengths.erase(lengths.find(v));
            lengths.insert(new_l);
            clog << db(lengths) << endl;
            int mx = *--lengths.end();
            int cur_last = i == n ? pos[n - 1] : pos[n];
            ll cur_ans = min({*lengths.begin(), max((mx - 1) / 2, d - cur_last - 1)});
            clog << db(mx) << db(cur_last) << db(cur_ans) << endl;
            ans = max(ans, cur_ans);
            lengths.erase(lengths.find(new_l));
            lengths.insert(u);
            lengths.insert(v);
        }
        
        int mx = *--lengths.end();
        lengths.erase(lengths.find(pos[n] - pos[n - 1] - 1));
        int cur_last = pos[n - 1];
        ll cur_ans = min({*lengths.begin(), max((mx - 1) / 2, d - cur_last - 1)});
        ans = max(ans, cur_ans);
        
        
        cout << ans << '\n';
    }
    
    return 0;
}