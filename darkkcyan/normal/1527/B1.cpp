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

const int maxn = 1010;
const ll inf = 1e15;
const ll undef = LLONG_MIN;

ll dp[maxn][maxn][2][2];

ll cal_dp(int cnt_00, int cnt_01, bool mid_0, bool prev_rev) {
    DB();
    clog << db(cnt_00) << db(cnt_01) << db(mid_0) << db(prev_rev) << endl;
    if (cnt_00 < 0 or cnt_01 < 0) return inf;
    ll& ans = dp[cnt_00][cnt_01][mid_0][prev_rev];
    if (ans != undef) return ans;
    ans = inf;
    if (cnt_00 == 0 and cnt_01 == 0 and !mid_0) return ans = 0;
    if (!prev_rev and cnt_01) ans = min(ans, -cal_dp(cnt_00, cnt_01, mid_0, 1));
    if (mid_0) ans = min(ans, 1 - cal_dp(cnt_00, cnt_01, 0, 0));
    if (cnt_00) ans = min(ans, 1 - cal_dp(cnt_00 - 1, cnt_01 + 1, mid_0, 0));
    if (cnt_01) ans = min(ans, 1 - cal_dp(cnt_00, cnt_01 - 1, mid_0, 0));
    clog << db(cnt_00) << db(cnt_01) << db(mid_0) << db(prev_rev) << db(ans) << endl;
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
    
    rep(i, 0, maxn) rep(f, 0, maxn) rep(u, 0, 2) rep(v, 0, 2) dp[i][f][u][v] = undef;
    
    while (ntest--) {
        DB();
        int n; cin >> n;
        string s; cin >> s;
        int cnt_00 = 0, cnt_01 = 0;
        bool mid_0 = 0;
        
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            if (s[l] == '1' and s[r] == '1') continue;
            if (s[l] == '0' and s[r] == '0') ++ cnt_00;
            else ++cnt_01;
        }
        
        if (n & 1 and s[n / 2] == '0') mid_0 = 1;
        clog << db(cnt_00) << db(cnt_01) << db(mid_0) << endl;
        
        auto ans = cal_dp(cnt_00, cnt_01, mid_0, 0);
        clog << db(ans) << endl;
        if (ans == 0) {
            cout << "DRAW\n";
        } else if (ans < 0) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
    
    return 0;
}

// vim: foldmethod=marker