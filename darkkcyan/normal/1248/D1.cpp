#pragma GCC optimize ("O3", "unroll-loops")
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

int max_beauty(const string& s) {
    DB();
    static vector<int> bal;
    bal.resize(sz(s) + 1, 0);
    int min_bal = 0;
    rep(i, 0, sz(s)) {
        int cur = s[i] == '(' ? 1 : -1;
        bal[i + 1] = bal[i] + cur;
        min_bal = min(min_bal, bal[i + 1]);
    }
    clog << db(bal) << db(min_bal) << endl;
    if (bal.back() != 0) return 0;
    int ans = 0;
    rep(i, 1, sz(s) + 1) {
        ans += bal[i] == min_bal;
    }
    
    return ans;
}

int n;
string s;

tuple<int, int, int> solve() {
    if (n % 2) return {0, 1, 1};
    tuple ans = {max_beauty(s), 1, 1};
    rep(i, 0, n) {
        rep(f, i + 1, n) {
            if (s[i] == s[f]) continue;
            swap(s[i], s[f]);
            clog << db(i) << db(f) << endl;
            ans = max(ans, {max_beauty(s), i + 1, f + 1});
            swap(s[i], s[f]);
        }
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
    cin >> n >> s;
    auto [mx_b, l, r] = solve();
    cout << mx_b << '\n' << l << ' ' << r;
    
    return 0;
}

// vim: foldmethod=marker