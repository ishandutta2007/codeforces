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

ll exgcd(ll a, ll b, ll & x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    ll k;
    int n, m;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    int max_val = max(n, m) * 2;
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
        --b[i];
    }
    
    ll g, x, y;
    g = exgcd(n, m, x, y);
    const ll ng = n / g;
    const ll mg = m / g;
    clog << db(g) << db(x) << db(y) << db(ng) << db(mg) << endl;
    auto crt = [&](ll u, ll v) {
        ll nx = x * (v - u) % mg;
        if (nx < 0) nx += mg;
        return nx * ng + u;
    };
    
    vector<ll> pa(max_val, -1), pb(max_val, -1);
    rep(i, 0, n) pa[a[i]] = i;
    rep(i, 0, m) pb[b[i]] = i;
    
    vector<ll> pos;
    rep(i, 0, max_val) {
        if (pa[i] == -1 or pb[i] == -1) continue;
        if (pa[i] % g != pb[i] % g) continue;
        ll cur_pos = crt(pa[i] / g, pb[i] / g) * g + pa[i] % g;
        clog << db(i) << db(pa[i]) << db(pb[i]) << db(cur_pos) << endl;
        pos.push_back(cur_pos);
    }
    sort(all(pos));
    clog << db(pos) << endl;
    ll period = ng * m - sz(pos);
    assert(period);
    ll cycle = (k - 1) / period;
    ll ans = cycle * ng * m;
    k -= cycle * period;
    
    clog << db(period) << endl;
    clog << db(ans) << endl;
    ll prev = 0;
    int it = 0;
    pos.push_back(ng * m);
    clog << db(k) << endl;
    while (k) {
        ll cur = (pos[it] - prev);
        if (cur < 0) cur += ng * m;
        prev = pos[it ++] + 1;
        if (it == sz(pos)) it = 0;
        ll t = min(k, cur);
        clog << db(t) << endl;
        ans += t;
        k -= t;
        ans += !!k;
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker