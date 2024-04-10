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


ll inf = (ll)1e15;

ll safe_add(ll x, ll y) {
    if (x >= inf) return y;
    if (y >= inf) return x;
    return min(x + y, inf);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    
    vector<array<int, 26>> nxt(n + 1);
    nxt.back().fill(n);
    for (int i = n; i--; ) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }
    
    dp[0][0] = 1;
    rep(pos, 0, n) {
        rep(cur_len, 0, n) {
            rep(nxt_ch, 0, 26) {
                int np = nxt[pos][nxt_ch];
                if (np == n) continue;
                dp[np + 1][cur_len + 1] = safe_add(dp[np + 1][cur_len + 1], dp[pos][cur_len]);
            }
        }
        clog << db(pos) << db(dp[pos]) << endl;
    }
    clog << db(dp.back()) << endl;
    
    
    ll ans = 0;
    for (int len = n + 1; len--; ) {
        rep(pos, 0, n + 1) {
            ll cur_cnt = dp[pos][len];
            ll need = min(cur_cnt, k);
            k -= need;
            ans += need * (n - len);
        }
    }
    if (k > 0) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    
    
    return 0;
}

// vim: foldmethod=marker