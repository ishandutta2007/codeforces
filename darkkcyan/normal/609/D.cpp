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

const int maxn = 202020;
const ll inf = 1e15;
int n, m, k;
ll s;
ll a[maxn], b[maxn];
vector<pair<ll, int>> g[2];
ll pref_sum[2][maxn];

int try_buy(ll dollar, ll pound) {
    rep(c0, 0, k + 1) {
        int c1 = k - c0;
        if (pref_sum[0][c0] * dollar + pref_sum[1][c1] * pound <= s) return c0;
    }
    return -1;
}

bool ok(int day) {
    ll mi_a = *min_element(a, a + day + 1);
    ll mi_b = *min_element(b, b + day + 1);
    
    return try_buy(mi_a, mi_b) != -1;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k >> s;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, m) {
        int t;
        ll c;
        cin >> t >> c;
        g[t - 1].emplace_back(c, i);
    }
    sort(all(g[0]));
    sort(all(g[1]));
    
    rep(t, 0, 2) {
        rep(i, 0, sz(g[t]))
            pref_sum[t][i + 1] = pref_sum[t][i] + g[t][i].first;
        rep(i, sz(g[t]), k + 1)
            pref_sum[t][i + 1] = inf;
    }
    
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    
    if (l == n) {
        cout << "-1\n";
    } else {
        cout << l + 1 << '\n';
        auto mi_a = min_element(a, a + l + 1);
        auto mi_b = min_element(b, b + l + 1);
        
        int c0 = try_buy(*mi_a, *mi_b);
        rep(i, 0, c0) {
            cout << g[0][i].second + 1 << ' ' << mi_a - a + 1 << '\n';
        }
        rep(i, 0, k - c0) {
            cout << g[1][i].second + 1 << ' ' << mi_b - b + 1 << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker