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

const int maxn = 55;
const int inf = (int)1e6;
int n, init_pos, k;
int a[maxn];
int sum_a;
string color;

template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

int solve() {
    DB();
    vector<vector<int>> dp(n, vector<int>(sum_a + 1, inf));
    
    min_pq<tuple<int, int, int>> prio;
    
    rep(i, 0, n) {
        dp[i][a[i]] = abs(init_pos - i);
        prio.emplace(dp[i][a[i]], i, a[i]);
    }
    
    while (prio.size()) {
        DB();
        auto [d, pos, eaten] = prio.top();
        prio.pop();
        if (dp[pos][eaten] < d) continue;
        clog << db(d) << db(pos) << db(eaten) << endl;
        if (eaten >= k) {
            return d;
        }
        rep(nxt, 0, n) {
            if (nxt == pos) continue;
            if (color[pos] == color[nxt]) continue;
            if (a[nxt] <= a[pos]) continue;
            int nd = d + abs(pos - nxt);
            if (dp[nxt][eaten + a[nxt]] <= nd) continue;
            dp[nxt][eaten + a[nxt]] = nd;
            prio.emplace(nd, nxt, eaten + a[nxt]);
        }
    }
    return INT_MAX;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> init_pos >> k ;
    rep(i, 0, n) cin >> a[i];
    sum_a = accumulate(a, a + n, 0);
    cin >> color;
    
    --init_pos;
    
    string o = "BGR";
    int ans = solve();
    if (ans >= INT_MAX) ans = -1;
    cout << ans << '\n';
    
    return 0;
}

// vim: foldmethod=marker