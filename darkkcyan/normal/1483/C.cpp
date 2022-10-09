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

struct BIT {
    vector<ll> val;
    BIT(int sz, ll init = 0): val(sz + 10, init) {}
    
    void upd(int i, ll v) {
        for (++i; i < len(val); i += i & -i)
            val[i] = max(val[i], v);
    }
    
    ll get(int i, ll ans = 0) {
        for (++i; i > 0; i -= i & -i)
            ans = max(ans, val[i]);
        return ans;
    }
};

const int maxn = 301010;
const ll inf = (ll)1e16;
int n;
ll h[maxn], b[maxn];
ll solve() {
    vector<int> st = {n};
    vector<ll> dp(n + 1);
    dp[n] = -inf;
    h[n] = 0;
    BIT bit(n, -inf);
    bit.upd(n, 0);
    for (int i = n; i--; ) {
        DB();
        clog << db(i) << endl;
        while (h[st.back()] >= h[i]) st.pop_back();
        clog << db(st) << endl;
        ll max_contrib = bit.get(st.back(), -inf);
        max_contrib += b[i];
        dp[i] = max(max_contrib, dp[st.back()]);
        clog << db(dp[st.back()]) << endl;
        clog << db(max_contrib) << endl;
        st.push_back(i);
        bit.upd(i, dp[i]);
    }
    clog << db(dp) << endl;
    return dp[0];
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> b[i];
    cout << solve() << endl;
    
    return 0;
}

// vim: foldmethod=marker