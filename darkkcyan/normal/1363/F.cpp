#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

vector<array<int, 26>> cal_suff_sum(const string& s) {
    vector<array<int, 26>> ans(sz(s) + 1);
    for (int i = sz(s); i--; ) {
        ans[i] = ans[i + 1];
        ans[i][s[i] - 'a'] ++;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        
        auto suff_s = cal_suff_sum(s);
        auto suff_t = cal_suff_sum(t);
        
        if (suff_s[0] != suff_t[0]) {
            cout << "-1\n";
            continue;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 2 * n));
        
        rep(i, 0, n + 1) dp[0][i] = 0;
        
        rep(i, 1, n + 1)
        rep(f, i, n + 1) {
            char ch = t[f -1 ] - 'a';
            if (suff_s[i][ch] > suff_t[f][ch]) {
                dp[i][f] = min(dp[i][f], dp[i][f - 1]);
            }
            if (s[i - 1] == t[f - 1]) dp[i][f] = min(dp[i][f], dp[i - 1][f - 1]);
            dp[i][f] = min(dp[i][f], dp[i - 1][f] + 1);
        }
        
        rep(i, 1, n + 1) {
            clog << db(i) << db(dp[i]) << endl;
        }
        
        cout << dp[n][n] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker