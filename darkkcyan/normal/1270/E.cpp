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
int n;
pair<int, int> a[maxn];
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second; 
        a[i].first += (int)1e6 + 1;
        a[i].second += (int)1e6 + 1;
    }
    
    vector<int> groups[2][2];
    int cnt_group = 1;
    while (cnt_group == 1) {
        rep(i, 0, 2) rep(f, 0, 2) groups[i][f].clear();
        rep(i, 0, n) {
            groups[a[i].first & 1][a[i].second & 1].push_back(i);
            a[i].first /= 2;
            a[i].second /= 2;
        }
        
        cnt_group = 0;
        rep(i, 0, 2) rep(f, 0, 2) cnt_group += groups[i][f].size() > 0;
    }
    
    if (cnt_group == 2) {
        bool found = false;
        rep(i, 0, 2) rep(f, 0, 2) {
            if (found) break;
            if (groups[i][f].empty()) continue;
            cout << sz(groups[i][f]) << '\n';
            for (auto x: groups[i][f]) cout << x + 1 << ' ';
            found = true;
        }
    } else {
        cout << groups[0][0].size() + groups[1][1].size() << '\n';
        for (auto i: groups[0][0]) cout << i + 1 << ' ';
        for (auto i: groups[1][1]) cout << i + 1 << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker