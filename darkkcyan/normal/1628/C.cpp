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
        vector a(n, vector<ll>(n));
        for (auto& row: a) for (auto& i: row) cin >> i;
        
        auto go_border = [&](int off_r, int off_c, int size) {
            vector<pair<int, int>> border_pos;
            rep(i, 0, size - 1) border_pos.emplace_back(i, 0);
            rep(i, 0, size - 1) border_pos.emplace_back(size - 1, i);
            for (int i = size - 1; i > 0; --i) border_pos.emplace_back(i, size - 1);
            for (int i = size - 1; i > 0; --i) border_pos.emplace_back(0, i);
            ll cur_ans = 0;
            for (int i = 0; i < sz(border_pos); i += 4)  {
                for (auto [r, c]: {border_pos[i], border_pos[i + 1]}) {
                    cur_ans ^= a[r + off_r][c + off_c];
                }
            }
            return cur_ans;
        };
        
        int off_r = 0, off_c = 0, size = n;
        ll ans = 0;
        while (size > 0) {
            ans ^= go_border(off_r, off_c, size);
            size -= 4;
            off_r += 2;
            off_c += 2;
        }
        cout << ans << '\n';
        
    }
    
    return 0;
}

// vim: foldmethod=marker