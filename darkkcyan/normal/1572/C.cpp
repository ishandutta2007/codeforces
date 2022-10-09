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

const int maxn = 3010;

int n;
int a[maxn];
int dp[maxn][maxn];

int solve() {
    DB();
    vector<vector<int>> pos(n + 1);
    vector<int> nxt(n + 1, n), prv(n + 1, -1);
    vector<int> cur(n + 1, -1);
    rep(i, 0, n) {
        prv[i] = cur[a[i]];
        cur[a[i]] = i;
    }
    cur.assign(n + 1, n);
    for (int i = n; i--; ) {
        nxt[i]  = cur[a[i]];
        cur[a[i]] = i;
    }
    rep(i, 0, n) dp[i][i + 1] = 0;
    rep(i, 0, n - 1) {
        if (a[i] == a[i + 1]) dp[i][i + 2] = 0;
        else dp[i][i + 2] = 1;
        clog << db(i) << db(i + 2) << db(dp[i][i + 2]) << endl;
    }
    
    for (int l = n; l--; ) {
        rep(r, l + 3, n + 1) {
            dp[l][r] = dp[l + 1][r - 1] + (a[l] != a[r - 1]) + 1;
            if (a[l] == a[r - 1]) {
                for (int u = nxt[l]; u < r; u = nxt[u]) {
                    dp[l][r] = min(dp[l][r], dp[l][u + 1] + dp[u][r]);
                }
            } else {
                for (int u = nxt[l]; u < r; u = nxt[u]) {
                    dp[l][r] = min(dp[l][r], dp[l][u + 1] + dp[u + 1][r] + 1);
                }
                for (int u = prv[r - 1]; u >= l; u = prv[u]) {
                    dp[l][r] = min(dp[l][r], dp[l][u] + dp[u][r] + 1);
                }
            }
            clog << db(l) << db(r) << db(dp[l][r]) << endl;
        }
    }
    return dp[0][n];
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        cout << solve() << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker