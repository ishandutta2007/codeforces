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

const int maxn = 20;
const int maxm = 10100;
int n, m;
int a[maxn][maxm];

int dist[maxn][maxn], dist_open_ended[maxn][maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n) rep(f, 0, m) cin >> a[i][f];
    
    rep(u, 0, n) rep(v, u + 1, n) {
        int min_dist = INT_MAX;
        rep(i, 0, m) min_dist = min(min_dist, abs(a[u][i] - a[v][i]));
        dist[u][v] = dist[v][u] = min_dist;
    }
    
    rep(u, 0, n) rep(v, 0, n) {
        dist_open_ended[u][v] = INT_MAX;
        rep(i, 0, m - 1) {
            dist_open_ended[u][v] = min(dist_open_ended[u][v], abs(a[u][i + 1] - a[v][i]));
        }
    }
    
    rep(i, 0, n) rep(f, 0, n) clog << db(i) << db(f) << db(dist[i][f]) << endl;
    
    int ans = INT_MIN;
    rep(first_row, 0, n) {
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MIN));
        dp[1 << first_row][first_row] = INT_MAX;
        rep(mask, 0, (1 << n)) rep(last, 0, n) {
            if ((mask >> last) & 1) {
                if (dp[mask][last] == INT_MIN) continue;
                rep(nxt, 0, n) {
                    if (((mask >> nxt) & 1)) continue;
                    dp[mask | (1 << nxt)][nxt] = max(
                        dp[mask | (1 << nxt)][nxt], 
                        min(dp[mask][last], dist[last][nxt])
                    );
                }
            }
        }
        rep(last, 0, n) {
            ans = max(ans, min(dp[(1 << n) - 1][last], dist_open_ended[first_row][last]));
        }
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker