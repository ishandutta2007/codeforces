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

const string big(1, char('9' + 1));
const int maxlen = 15;
const int maxk = 11;
string num;
int k;

string cal_bigger(int len_left, int mask) {
    if (len_left == 0) return "";
    if (__builtin_popcount(mask) == k) {
        int sml = __builtin_ctz(mask);
        return string(len_left, char(sml + '0'));
    }
    return string(len_left, '0');
}

auto smin(const string& u, const string& v) {
    if (sz(u) == 0) return v;
    if (sz(v) == 0) return u;
    return min(u, v);
}

string cal(int pos, int mask) {
    if (pos == sz(num)) return "";
    int cur = num[pos] - '0';
    string ans;
    int nm = mask | (1 << cur);
    if (__builtin_popcount(nm) <= k) {
        if (pos == sz(num) - 1) {
            ans = num[pos];
        } else {
            auto t = cal(pos + 1, nm);
            if (sz(t)) ans = num[pos] + t;
        }
    }
    for (int i = cur + 1; i <= 9; ++i) {
         nm = mask | (1 << i);
         if (__builtin_popcount(nm) <= k) {
             ans = smin(ans, char(i + '0') + cal_bigger(sz(num) - pos - 1, nm));
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
    
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> num >> k;
        auto ans = cal(0, 0);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker