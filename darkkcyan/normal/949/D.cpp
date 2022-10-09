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

int solve_1_side(vector<ll>& x, int lim_len, int lim_val, int max_dist) {
    DB();
    if (sz(x) < lim_len) x.resize(lim_len);
    clog << db(lim_len) << endl;
    vector<ll> pref_sum(sz(x) + 1);
    rep(i, 0, sz(x)) pref_sum[i + 1] = pref_sum[i] + x[i];
    ll carry = 0;  // negative will be debt
    rep(i, 0, min(sz(x), lim_len)) {
        clog << db(i) << db(x) << db(carry) << endl;
        carry += x[i];
        if (carry >= lim_val) {
            x[i] = lim_val;
            carry -= lim_val;
            continue;
        }
        if (carry <= 0) {
            x[i] = 0;
        }
        ll t = pref_sum[min(1ll * sz(x), i + 1ll * max_dist * i + max_dist + 1)] - pref_sum[i + 1] + carry;
        if (t >= lim_val) {
            carry -= x[i];
            carry -= lim_val - x[i];
            x[i] = lim_val;
        }
    }
    clog << db(x) << endl;
    return lim_len - (int)count(x.begin(), x.begin() + min(sz(x), lim_len), lim_val);
}

const int maxn = 101010;
int n, d, b;
ll a[maxn];

pair<int, int> cal(ll sep) {
    DB();
    clog << db(sep) << endl;
    int sep_pos = 0;
    ll sum = a[0];
    while (sep_pos < n - 1 and sum < sep) {
        sum += a[++sep_pos];
    }
    
    clog << db(sep_pos) << db(sum) << endl;
    
    vector<ll> u, v;
    rep(i, 0, sep_pos) {
        u.push_back(a[i]);
    }
    u.push_back(sep - (sum - a[sep_pos]));
    for (int i = n; i-- > sep_pos + 1; ) {
        v.push_back(a[i]);
    }
    v.push_back(sum - sep);
    clog << db(u) << endl;
    clog << db(v) << endl;
    auto x = solve_1_side(u, (n + 1) / 2, b, d);
    auto y = solve_1_side(v, n / 2, b, d);
    clog << db(x) << db(y) << endl;
    clog << db(u) << endl;
    clog << db(v) << endl;
    return {x, y};
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> d >> b;
    rep(i, 0, n) cin >> a[i];
    ll l = 0, r = 1ll * n * b;
    
    while (l < r) {
        ll mid = (l + r) / 2;
        auto [u, v] = cal(mid);
        if (u - v <= 0) r = mid;
        else l = mid + 1;
    }
    
    auto [u, v] = cal(l);
    cout << max(u, v) << '\n';
    
    return 0;
}

// vim: foldmethod=marker