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

const int maxn = 201010;
int n;

vector<int> gr[maxn];

int dp[maxn], state[maxn];

int cal_dp(int u) {
    if (state[u] == 2) return dp[u];
    if (state[u] == 1) return -1;
    state[u] = 1;
    dp[u] = 1;
    for (auto v: gr[u]) {
        int x = cal_dp(v);
        if (x == -1) return -1;
        if (v < u) dp[u] = max(dp[u], dp[v]);
        else dp[u] = max(dp[u], dp[v] + 1);
    }
    
    state[u] = 2;
    return dp[u];
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
        cin >> n;
        rep(i, 1, n + 1) {
            gr[i].clear();
            dp[i] = 0;
            state[i] = 0;
        }
        rep(i, 1, n + 1) {
            int k; cin >> k;
            gr[i].resize(k);
            for (auto& u: gr[i]) cin >> u;
        }
        int ans = 1;
        rep(i, 1, n + 1) {
            int x = cal_dp(i);
            if (x == -1) {
                ans = -1;
                break;
            }
            ans = max(ans, x);
        }
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker