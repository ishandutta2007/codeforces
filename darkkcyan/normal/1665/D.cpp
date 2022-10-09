#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main
 
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
 
struct Solver {
    virtual ll ask(ll a, ll b) = 0;
    virtual void answer(ll answer) = 0;
    
    void solve() {
        ll ans = 0;
        rep(i, 0, 29) {
            ll bit = 1ll << i;
            ll a = 2 * bit - ans;
            ll b = a + 2 * bit;
            ll t = ask(a, b);
            if (t != 2 * bit) ans |= bit;
        }
        ll u = ans;
        ll v = ans | (1ll << 29);
        if (ask(1, v + 2) == v + 1) {
            ans = v;
        } else {
            ans = u;
        }
        answer(ans);
    }
};

struct FixedAnsSolver: public Solver {
    ll x;
    int cnt_qr = 0;
    FixedAnsSolver(ll x_): x(x_) {
        cout << "== Test " << db(x) << db(bitset<30>(x)) << endl;
    }
    virtual ll ask(ll a, ll b) override {
        assert(cnt_qr < 30);
        ++cnt_qr;
        assert(a <= (ll)2e9);
        assert(b <= (ll)2e9);
        cout << ">> Ask " << db(a) << db(b) << endl;
        ll ans = __gcd(x + a, x + b);
        cout << "<< answer: " << db(ans) << endl;
        return ans;
    }
    
    virtual void answer(ll answer) override {
        cout << ">> Answer: " << db(answer) << db(bitset<30>(answer)) << endl;
        cout << "<< True ans: " << db(x) << endl;
        assert(x == answer);
    }
};

mt19937_64 rng;
ll next(ll l, ll r) {
    return l + (ll)(rng() % (r - l + 1));
}

struct RandomAnsSolver: public FixedAnsSolver {
    RandomAnsSolver(): FixedAnsSolver(next((ll)1, (ll)100)) {}
};

struct IOSolver: public Solver {
    virtual ll ask(ll a, ll b) override {
        cout << "? " << a << ' ' << b << endl;
        ll ans;
        cin >> ans;
        return ans;
    }
    
    virtual void answer(ll answer) override {
        cout << "! " << answer << endl;
    }
};

int jalsol_orz() {
#ifdef LOCAL
    // while (true) RandomAnsSolver().solve();
    FixedAnsSolver(4).solve();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        IOSolver().solve();
    }
    
    return 0;
}