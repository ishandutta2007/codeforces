#include <bits/stdc++.h>
#include <string_view>
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
        auto is_rbs = [](string_view s) {
            int bal = 0;
            for (auto i: s) {
                if (i == ')') -- bal;
                else ++bal;
                if (bal < 0) return false;
            }
            return bal == 0;
        };
        
        string s;
        cin >> s;
        vector<int> ques_pos;
        int cnt_open = 0, cnt_close = 0;
        rep(i, 0, sz(s)) {
            if (s[i] == '?') {
                ques_pos.push_back(i);
            } else if (s[i] == '(') {
                ++cnt_open;
            } else {
                ++cnt_close;
            }
        }
        int n = sz(s) / 2;
        string t = s;
        vector<int> open_pos(ques_pos.begin(), ques_pos.begin() + (n - cnt_open));
        vector<int> close_pos(ques_pos.begin() + (n - cnt_open), ques_pos.end());
        clog << db(cnt_open) << endl;
        clog << db(cnt_close) << endl;
        for (auto i: open_pos) t[i] = '(';
        for (auto i: close_pos) t[i] = ')';
        clog << db(open_pos) << endl;
        clog << db(close_pos) << endl;
        clog << db(s) << endl;
        clog << db(t) << endl;
        assert(is_rbs(t));
        if (open_pos.empty() or close_pos.empty()) {
            cout << "YES\n";
            continue;
        }
        t[open_pos.back()] = ')';
        t[close_pos[0]] = '(';
        if (!is_rbs(t)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}