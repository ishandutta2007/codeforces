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

int n;
vector<string> words;

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    words.resize(n);
    for (auto& i: words) cin >> i;
    
    vector<vector<bool>> eq_w(n, vector<bool>(n));
    rep(i, 0, n) {
        eq_w[i][i] = true;
        rep(f, i + 1, n) {
            eq_w[i][f] = eq_w[f][i] = words[i] == words[f];
        }
    }
    
    vector<vector<vector<bool>>> eq_s(n + 1, vector<vector<bool>>(n, vector<bool>(n)));
    rep(i, 0, n) rep(f, 0, n) eq_s[0][i][f] = true;
    
    rep(len, 1, n + 1)
    rep(u, 0, n - len + 1)
    rep(v, 0, n - len + 1)  {
        eq_s[len][u][v] = eq_s[len - 1][u][v] and eq_w[u + len - 1][v + len - 1];
    }
    
    vector<int> sum_len(n + 1);
    rep(i, 0, n) sum_len[i + 1] = sum_len[i] + sz(words[i]);
    clog << eq_s[2][0][4] << endl;
    
    int ans = n - 1;
    for (auto& i: words) ans += sz(i);
    rep(start, 0, n) {
        rep(stop, start + 1, n + 1) {
            int len = stop - start;
            int cur_ans = sum_len[start] + start + len;
            int shorten_cnt = 1;
            for (int i = stop; i < n;) {
                ++cur_ans;
                if (eq_s[len][start][i]) {
                    cur_ans += len;
                    i += len;
                    ++shorten_cnt;
                } else {
                    cur_ans += sz(words[i]);
                    ++i;
                }
            }
            clog << db(start) << db(stop) << db(cur_ans) << db(shorten_cnt) << endl;
            if (shorten_cnt > 1) ans = min(ans, cur_ans);
        }
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker