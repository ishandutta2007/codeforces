#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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

const int maxn = 1 << 18;
const ll inf = 1e13;
int n;
ll a[maxn];

// ll brute() { 
    // ll ans = inf; 
    //  
    // vector<int> pos(n); 
    // iota(pos.begin(), pos.end(), 0); 
    //  
    // do { 
        // auto cur = pos; 
        // ll cur_ans = 0; 
        // while (len(cur)  > 1){  
            // for (int i = 0; i < len(cur); i += 2) { 
                // if (a[cur[i]] != -1 and a[cur[i]] != -1) { 
                // } 
            // } 
        // } 
    // } while (next_permutation(pos.begin(), pos.end())); 
    // return ans; 
// } 

ll solve() {
    vector<ll> b(a, a + n);
    for (int i = 0; ; ++i) {
        bool it = b[i] == -1;
        b[i] = 0;
        if (it) break;
    }
    reverse(b.begin(), b.end());
    int l2 = 31 - __builtin_clz(n);
    vector<vector<ll>> dp(l2, vector<ll>(n, inf));
    dp[0][0] = b[0];
    ll range = n / 2;
    for (int lv = 1; lv < l2; ++lv, range |= range >> 1) {
        ll cur_min = inf;
        rep(i, range + 1) {
            dp[lv][i] = min(dp[lv][i], cur_min + b[i]);
            cur_min = min(cur_min, dp[lv - 1][i]);
        }
    }
    return *min_element(dp.back().begin(), dp.back().end());
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    
    cout << solve() << '\n';
    
    return 0;
}

// vim: foldmethod=marker