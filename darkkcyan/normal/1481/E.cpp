#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 501010;
int n;
int a[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    
    struct ColorInt {
        int l, r;
        ColorInt(): l(INT_MAX), r(INT_MIN) {}
        void upd(int pos) {
            l = min(l, pos);
            r = max(r, pos + 1);
        }
    };
    
    vector<ColorInt> col_int(n + 1);
    rep(i, n) col_int[a[i]].upd(i);
    
    vector<int> max_pref(n + 1), max_suff(n + 1);
    vector<int> cnt(n + 1);
    rep(i, n) {
        cnt[a[i]]++;
        max_pref[i + 1] = max(max_pref[i], cnt[a[i]]);
    }
    
    cnt.assign(n + 1, 0);
    for (int i = n; i--; ) {
        cnt[a[i]]++;
        max_suff[i] = max(max_suff[i + 1], cnt[a[i]]);
    }
    
    vector<int> dp(n + 1);
    // int rev_ans = 0;   // use this for solving the case where we can also move book to the left
    //                       well I didn't read the problem properly :(
    for (int i = n; i --; ) {
        dp[i] = dp[i + 1];
        if (i != col_int[a[i]].l) continue;
        int& cur_dp = dp[i];
        cur_dp = max(cur_dp, cnt[a[i]] + max(dp[col_int[a[i]].r], max_suff[col_int[a[i]].r]));
        // rev_ans = max(rev_ans, cur_dp + max_pref[i]); 
    }
    clog << db(dp) << endl;
    // cout << n - rev_ans << endl; 
    cout << n - dp[0];
    
    return 0;
}

// vim: foldmethod=marker