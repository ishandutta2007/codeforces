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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
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

string s;
int predict(int pos, int diff_score) {
    if (pos == 10) return 10;
    int sign = pos & 1 ? 1 : -1;
    int mrg[2] = {0, 0}; 
    rep(i, pos, 10) { 
        // max_rest_goal += s[i] != '0';  
        mrg[i & 1] ++; 
    } 
    if (pos == 9) clog << db(diff_score) << db(mrg[0]) << db(mrg[1]) << endl;
    if (sign == 1 and (mrg[pos & 1] + diff_score < 0 or -mrg[!(pos & 1)] + diff_score > 0)) return pos;
    if (sign == -1 and (-mrg[pos & 1] + diff_score > 0 or mrg[!(pos + 1)] + diff_score < 0)) return pos;
    if (s[pos] != '?') {
        return predict(pos + 1, diff_score + (s[pos] == '1' ? sign : 0));
    }
    return min(predict(pos + 1, diff_score), predict(pos + 1, diff_score + sign));
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
        cin >> s;
        auto ans = predict(0, 0);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker