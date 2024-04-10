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

const int maxn = 501010;
int n, r;
ll k;
ll a[maxn];

ll def_lv[maxn];

ll cal_need(ll required) {
    vector<ll> pref(n + 1);
    ll ans = 0;
    rep(i, 0, n) {
        ll cur = def_lv[i] + pref[i];
        if (cur < required) {
            ll cur_need = required - cur;
            pref[i] += cur_need;
            pref[min(sz(pref) - 1, i + 2 * r + 1)] -= cur_need;
            ans += cur_need;
        }
        
        pref[i + 1] += pref[i];
    }
    DB();
    clog << db(required) << endl;
    clog << db(pref) << endl;
    clog << db(ans) << endl;
    return ans;
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> r >> k;
    rep(i, 0, n) cin >> a[i];
    
    rep(i, 0, n) {
        def_lv[max(0, i - r)] += a[i];
        def_lv[min(n, i + r + 1)] -= a[i];
    }
    
    rep(i, 0, n) def_lv[i + 1] += def_lv[i];
    clog << db(vector<ll>(def_lv, def_lv + n + 1)) << endl;
    
    ll lo = 0, hi = 1;
    while (cal_need(hi) <= k) hi *= 2;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (cal_need(mid) <= k) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
    
    return 0;
}

// vim: foldmethod=marker