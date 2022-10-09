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

ll mpow(ll base, ll exp, ll mod) {
    ll ans = 1;
    for (; exp > 0; exp >>= 1, (base *= base) %= mod) {
        if (exp & 1) (ans *= base) %= mod;
    }
    return ans;
}

const int maxn = 5010100;
int pdiv[maxn];
void precal() {
    for (int i = 2; i < maxn; ++i) {
        if (pdiv[i]) continue;
        for (int f = i; f < maxn; f += i)
            pdiv[f] = i;
    }
}

bool is_primitive_root(ll num, ll n) {
    DB();
    clog << db(num) << endl;
    ll t = n - 1;
    while (t > 1) {
        ll p = pdiv[t];
        ll cur_pw = mpow(num, (n - 1) / p, n); 
        clog << db(num) << db(p) << db(cur_pw) << endl; 
        if (cur_pw == 1) return false;
        while (t % p == 0) t /= p;
    }
    clog << "is primitive " << db(num) << endl; 
    return true;
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, x;
    cin >> n >> x;
    if (pdiv[n + 1] != n + 1) {
        cout << "-1";
        return 0;
    }
    
    ll ans = -1;
    for (ll i = x - 1; x - i <= 2 * n and i > 1; --i) {
        clog << db(i) << endl;
        if (!is_primitive_root(i, n + 1)) continue;
        ans = i;
        break;
    }
    cout << ans;
    
// #ifdef LOCAL 
    // cout << endl; 
    // ans = -1; 
    // rep(i, 1, x + 1) { 
        // if (!is_primitive_root(i, n + 1)) continue; 
        // ans = max(ans, 1ll * i); 
    // } 
    // cout << db(ans) << endl; 
// #endif 
    
    return 0;
}

// vim: foldmethod=marker