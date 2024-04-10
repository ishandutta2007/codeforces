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

const int maxn = 2020;
int n, m;
ll a[maxn], b[maxn];

struct AnsT {
    ll val;
    vector<pair<int, int>> sw_idx;
};

bool operator<(const AnsT& u, const AnsT& v) {
    return abs(u.val) < abs(v.val);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cin >> m;
    rep(i, 0, m) cin >> b[i];
    
    ll sa = accumulate(a, a + n, 0ll);
    ll sb = accumulate(b, b + m, 0ll);
    ll diff = sa - sb;
    
    AnsT ans{diff, {}};
    
    rep(i, 0, n) rep(f, 0, m) {
        clog << db(i) << db(f) << db(diff - 2 * a[i] + 2 * b[f]) << endl;
        ans = min(ans, {diff - 2 * a[i] + 2 * b[f], {{i, f}}});
    }
    
    vector<tuple<ll, int, int>> pb;
    rep(i, 0, m) rep(f, i + 1, m) {
        pb.emplace_back(2 * b[i] + 2 * b[f], i, f);
    }
    
    sort(all(pb));
    clog << db(pb) << endl;
    
    rep(i, 0, n) rep(f, i + 1, n) {
        ll cur = diff - 2 * a[i] - 2 * a[f];
        auto it = lower_bound(all(pb), tuple{- cur, -1, -1});
        if (it != pb.end()) {
            ans = min(ans, {cur + get<0>(*it), {{i, get<1>(*it)}, {f, get<2>(*it)}}});
        }
        if (it != pb.begin()) {
            --it;
            ans = min(ans, {cur + get<0>(*it), {{i, get<1>(*it)}, {f, get<2>(*it)}}});
        }
    }
    cout << abs(ans.val) << '\n';
    cout << ans.sw_idx.size() << '\n';
    clog << db(ans.val) << endl;
    clog << db(ans.sw_idx) << endl;
    for (auto [u, v]: ans.sw_idx) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker