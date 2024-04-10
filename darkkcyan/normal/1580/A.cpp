#include <bits/stdc++.h>
using namespace std;


#define jalsol_orz main   // I did this for a meme :D


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

const int maxn = 444;
const int inf = (int)1e6;
int n, m;
string s[maxn];

int sum_col[maxn][maxn];

int cost_end(int c, int lo, int hi) {
    return (hi - lo - 2) - (sum_col[c][hi - 1] - sum_col[c][lo + 1]);
}

int cost_mid(int c, int lo, int hi) {
    return (sum_col[c][hi - 1] - sum_col[c][lo + 1]) + (s[lo][c] == '0') + (s[hi - 1][c] == '0');
}

int solve(int lo, int hi) {
    DB();
    clog << db(lo) << db(hi) << endl;
    if (hi - lo < 5) return inf;
    
    int cur_mx =  cost_mid(0, lo, hi) - cost_end(0, lo, hi);
    int cur_sum = cost_mid(0, lo, hi) + cost_mid(1, lo, hi) + cost_mid(2, lo, hi);
    int prev4_sum = cur_mx;
    int ans = inf;
    rep(i, 3, m) {
        int cur_end = cost_end(i, lo, hi);
        int new_sum = cur_sum + cur_end;
        int cur_cost = new_sum - cur_mx;
        clog << db(i) << db(cur_end) << db(cur_sum) << db(new_sum) << db(cur_cost) << db(prev4_sum) << db(ans) << db(cur_mx) << endl;
        ans = min(ans, cur_cost);
        prev4_sum += cost_mid(i - 2, lo, hi) - cost_end(i - 2, lo, hi);
        prev4_sum += cost_end(i - 3, lo, hi);
        cur_mx = max(cur_mx, prev4_sum);
        cur_sum += cost_mid(i, lo, hi);
    }
    return ans;
}

int solve() {
    rep(i, 0, n + 1) rep(f, 0, m + 1) {
        sum_col[f][i] = 0;
    }
    
    rep(f, 0, m) rep(i, 0, n) {
        sum_col[f][i + 1] = sum_col[f][i] + (s[i][f] == '1');
    }
    int ans = inf;
    rep(lo, 0, n) rep(hi, lo + 1, n + 1) {
        int cur_ans = solve(lo, hi);
        ans = min(ans, cur_ans);
    }
    return ans;
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> s[i];
        auto ans = solve();
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker