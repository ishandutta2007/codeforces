#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

map<pair<int, int>, ld> ans;

ld c, m, p, v;

ld solve2(ld x, ld y) {
    if (x < eps) return 1;
    return 1 + x * solve2(x - v, y + v);
}

ld cal(int incc, int incm) {
    auto it = ans.find({incc, incm});
    if (it != ans.end()) {
        return it->second;
    }
    auto& cur_ans = ans[{incc, incm}];
    ld cur_c = c + incc * v / 2;
    ld cur_m = m + incm * v / 2;
    ld cur_p = 1 - cur_c - cur_m;
    
    cur_ans = 1;
    if (cur_c < v + eps) {
        cur_ans += cur_c * solve2(cur_m + cur_c / 2, cur_p + cur_c / 2);
    } else cur_ans += cur_c * cal(incc - 2, incm + 1);
    
    if (cur_m < v + eps) {
        cur_ans += cur_m * solve2(cur_c + cur_m / 2, cur_p + cur_m / 2);
    } else cur_ans += cur_m * cal(incc + 1, incm - 2);
    clog << db(incc) << db(incm) << db(cur_c) << db(cur_m) << db(cur_p) << db(cur_ans) << endl;
    
    return cur_ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        cin >> c >> m >> p >> v;
        ans.clear();
        cout << fixed << setprecision(10) << cal(0, 0) << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker