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

template<class IT>
bool stupid_merge_sort(IT beg, IT end) {
    auto n = distance(beg, end);
    if (n <= 1) return true ;
    auto mid = next(beg, n / 2);
    if (!stupid_merge_sort(beg, mid)) return false;
    if (!stupid_merge_sort(mid, end)) return false;
    static vector<int> temp;
    temp.clear();
    int left_dec = 0;
    auto jt = mid;
    for (auto it = beg; it != mid; ++it) {
        int right_inc = (int)(mid - it);
        for (; jt != end and *jt + right_inc <= *it - left_dec; ++jt) {
            temp.push_back(*jt + right_inc);
            ++left_dec;
        }
        temp.push_back(*it - left_dec);
        ++right_inc;
    }
    temp.insert(temp.end(), jt, end);
    if (!is_sorted(all(temp))) return false;
    copy(all(temp), beg);
    return true;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    auto ok = stupid_merge_sort(all(a));
    if (!ok) {
        cout << ":(";
    } else {
        for (auto i: a) cout << i << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker