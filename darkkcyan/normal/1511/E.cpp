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

const int mod = 998'244'353;

int add(int u, int v) {
    u += v;
    if (u >= mod) u -= mod;
    return u;
}

int sub(int u, int v) {
    u -= v;
    if (u < 0) u += mod;
    return u;
}

int mul(int u, int v) {
    return (int)(1ll * u * v % mod);
}

const int maxn = 301010;
int p2[maxn];
int cnt_dp[maxn][2], dp[maxn][2], sdp[maxn];
void precal() {
    p2[0] = 1;
    rep(i, 1, maxn) p2[i] = add(p2[i - 1], p2[i - 1]);
    cnt_dp[0][0] = 1;
    rep(i, 1, maxn) {
        cnt_dp[i][0] = add(cnt_dp[i - 1][0], cnt_dp[i - 1][1]);
        cnt_dp[i][0] = add(cnt_dp[i][0], cnt_dp[i - 1][1]);
        cnt_dp[i][1] = cnt_dp[i - 1][0];
        
        dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = add(dp[i][0], add(dp[i - 1][1], cnt_dp[i - 1][1]));
        dp[i][1] = dp[i - 1][0];
        sdp[i] = add(dp[i][0], dp[i][1]);
    }
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<string> a(n);
    int cntw = 0;
    rep(i, 0, n) {
        cin >> a[i];
        for (auto& ch: a[i]) {
            if (ch == '*') ch = ' ';
            cntw += ch == 'o';
        }
    }
    
    int ans = 0;
    clog << "hor" << endl;
    rep(i, 0, n) {
        stringstream ss;
        ss << a[i];
        string t; 
        while (ss >> t) {
            clog << db(sz(t)) << endl;
            ans = add(ans, mul(sdp[sz(t)], p2[cntw - sz(t)]));
        }
    }
    
    clog << "ver" << endl;
    rep(f, 0, m) {
        stringstream ss;
        rep(i, 0, n) ss << a[i][f];
        string t;
        while (ss >> t) {
            clog << db(sz(t)) << endl;
            ans = add(ans, mul(sdp[sz(t)], p2[cntw - sz(t)]));
        }
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker