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

const int maxn = 101010;
struct cloud {
    ll x;
    int v;
    
    friend print_op(cloud) {
        return out << pair{u.x, u.v};
    }
};
int n;
ll l, wm;

ll ceil_div(ll u, ll v) {
    assert(v != 0);
    ll ans = u / v;
    while (ans * v < u) ++ans;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l >> wm;
    vector<cloud> a;
    rep(i, 0, n) {
        cloud cur;
        cin >> cur.x >> cur.v;
        a.push_back(cur);
    }
    
    if (wm == 1) {
        ll u = 0, v = 0;
        for (auto c: a) {
            if (c.v > 0) {
                u += c.x < 0;
            } else {
                v += c.x + l > 0;
            }
        }
        cout << u * v << '\n';
        return 0;
    }
    sort(all(a), [](cloud u, cloud v) { return u.x < v.x; });
    vector<ll> pos, neg;
    for (auto x: a) {
        if (x.v > 0) pos.push_back(x.x);
        else neg.push_back(x.x);
    }
    
    ll ans = 0;
    
    clog << db(pos) << endl;
    for (auto u: neg) {
        ll mx1 = ceil_div((u + l) * (wm - 1), (wm + 1));
        ll mx2 = ceil_div((u + l) * (wm + 1), (wm - 1));
        // ll mi1 = floor_div((u * (wm - 1)), (wm + 1)) - l; 
        // ll mi2 = floor_div((u * (wm + 1)), (wm - 1)) - l; 
        ll cur_ans = lower_bound(all(pos), min(mx1, mx2)) - pos.begin();
        clog << db(u) << db(cur_ans) << db(mx1) << db(mx2) << endl;
        ans += cur_ans;
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker