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

using pll = pair<ll, ll>;

pll operator+(const pll& u, const pll& v) {
    return {u.first + v.first, u.second + v.second};
}
pll operator-(const pll& u, const pll& v) {
    return {u.first - v.first, u.second - v.second};
}

const int maxn = 1010100;
ll pref_sum[maxn], suff_sum[maxn];

int n;
int a[maxn], b[maxn];

pll contrib[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    b[1] = 0;
    
    contrib[1] = {1, -a[1]};
    rep(i, 2, n + 1) contrib[i] = {0, b[i] - a[i]};
    rep(i, 1, n + 1) {
        for (int f = i + i; f <= n; f += i) {
            contrib[f] = contrib[f] - contrib[i];
        }
    }
    
    ll neg1 = 0;
    rep(i, 1, n + 1) {
        if (contrib[i].first < 0) {
            contrib[i].first = -contrib[i].first;
            contrib[i].second = -contrib[i].second;
        }
        neg1 += abs(contrib[i].second - contrib[i].first);
        if (contrib[i].first == 0) {
            continue;
        }
        ll x = (-contrib[i].second) / contrib[i].first;
        clog << db(i) << db(contrib[i]) << db(x) << endl;
        if (x >= 0) {
            pref_sum[0] -= contrib[i].first;
            if (x + 1 < maxn) pref_sum[x + 1] += contrib[i].first * 2;
        } else {
            pref_sum[0] += contrib[i].first;
        }
    }
    rep(i, 0, 10) clog << db(i) << db(pref_sum[i]) << endl;
    rep(i, 1, maxn) pref_sum[i] += pref_sum[i - 1];
    pref_sum[0] += neg1;
    rep(i, 1, maxn) pref_sum[i] += pref_sum[i - 1];
    rep(i, 0, 10) clog << db(i) << db(pref_sum[i]) << endl;
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << pref_sum[x] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker