#include <bits/stdc++.h>
using namespace std;
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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
 
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto& i: a) cin >> i;
        for (auto& i: b) cin >> i;
        
        ll ans = LLONG_MAX;
        auto connect = [&](int a1, int an, int b1, int bn) {
            set<pair<int, int>> edges;
            edges.emplace(0, a1);
            edges.emplace(n - 1, an);
            edges.emplace(b1, 0);
            edges.emplace(bn, n - 1);
            ll cur_ans = 0;
            for (auto& [u, v]: edges) {
                cur_ans += abs(a[u] - b[v]);
            }
            ans = min(ans, cur_ans);
        };
        
        vector<pair<ll, int>> min_a1 = {{LLONG_MAX, -1}, {LLONG_MAX, -1}};
        auto min_an = min_a1;
        auto min_b1 = min_a1;
        auto min_bn = min_a1;
        
        auto upd = [&](vector<pair<ll, int>>& cont, pair<ll, int> val) {
            cont.push_back(val);
            sort(all(cont));
            if (cont.size() > 2) cont.pop_back();
        };
        
        rep(i, 0, n) {
            upd(min_a1, {abs(b[i] - a[0]), i});
            upd(min_an, {abs(b[i] - a[n - 1]), i});
            upd(min_b1, {abs(a[i] - b[0]), i});
            upd(min_bn, {abs(a[i] - b[n - 1]), i});
        }
        min_a1.push_back({abs(b[0] - a[0]), 0});
        min_an.push_back({abs(b[0] - a[n - 1]), 0});
        min_b1.push_back({abs(a[0] - b[0]), 0});
        min_bn.push_back({abs(a[0] - b[n - 1]), 0});
        min_a1.push_back({abs(b[n - 1] - a[0]), n - 1});
        min_an.push_back({abs(b[n - 1] - a[n - 1]), n - 1});
        min_b1.push_back({abs(a[n - 1] - b[0]), n - 1});
        min_bn.push_back({abs(a[n - 1] - b[n - 1]), n - 1});
        for (auto [va1, a1]: min_a1)
        for (auto [van, an]: min_an)
        for (auto [vb1, b1]: min_b1)
        for (auto [vbn, bn]: min_bn)
            connect(a1, an, b1, bn);
        cout << ans << '\n';
    }
    
    return 0;
}