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

const ll mod = (ll) 1e9 + 7 ;
ll fact(int n) {
    static vector<ll> ans = {1};
    while (sz(ans) <= n)
        ans.push_back(ans.back() * sz(ans) % mod);
    return ans[n];
}

ll mpow(ll base, ll exp) {
    ll ans = 1;
    for (; exp > 0; exp >>= 1, base = base * base % mod)
        if (exp & 1) ans = ans * base % mod;
    return ans;
}

ll choose(int n, int k) {
    if (n < k or k < 0 or n < 0) return 0;
    return fact(n) * mpow(fact(k), mod - 2) % mod * mpow(fact(n - k), mod - 2) % mod;
}
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    ll sum = accumulate(all(a), 0ll);
    clog << db(sum) << endl;
    if (sum % n) {
        cout << "0\n";
        return 0;
    }
    ll avg = sum / n;
    map<ll, int> cnt;
    int cnt_less = 0, cnt_greater = 0;
    for (auto i: a) {
        cnt[i] ++;
        if (i > avg) ++cnt_greater;
        else if (i < avg) ++ cnt_less;
    }
    if (cnt[avg] == n) {
        cout << "1\n";
        return 0;
    }
    
    ll ans = 1;
    if (cnt_less == 1 or cnt_greater == 1) {
        (ans *= 1ll * (cnt_less + cnt_greater) % mod) %= mod;
    } else {
        (ans *= 2) %= mod;
    }
    for (auto [val, c]: cnt) {
        if (val < avg) {
            (ans *= choose(cnt_less, c)) %= mod;
            cnt_less -= c;
        } else if (val > avg) {
            (ans *= choose(cnt_greater, c)) %= mod;
            cnt_greater -= c;
        }
    }
    clog << db(ans) << endl;
    ans *= choose(n, cnt[avg]);
    ans %= mod;
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker