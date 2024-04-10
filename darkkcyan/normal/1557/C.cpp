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

#define defop(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx) : x((int)(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    modint pow(ll exp) const {
        modint ans = 1, base = * this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) {
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;
const mint inv2 = mint(1) / 2;

const int maxn = 201010;
mint pw2[maxn];
void precal() {
    pw2[0] = 1;
    rep(i, 1, maxn) pw2[i] = pw2[i - 1] + pw2[i - 1];
}

mint solve(ll n, ll k) {
    DB();
    mint ans = 1;
    mint prv = 1;
    rep(pos, 0, k) {
        mint cur = 0;
        if (n & 1) {
            mint head = pw2[n - 1];
            cur += head * prv;
            clog << db(head) << db(pw2[n - 1]) << endl;
        } else {
            mint head = pw2[n - 1] - 2;
            cur += head * prv;
            cur += pw2[pos].pow(n);
            clog << db(head) << db(pw2[n - 1]) << endl;
        }
        
        ans += cur;
        clog << db(pos) << db(ans) << db(prv) << db(cur) << endl;
        prv += cur;
    }
    return ans;
}

mint brute(ll n, ll k) {
    auto mx = 1 << k;
    --mx;
    vector<ll> vals(n);
    auto inc = [&] {
        rep(i, 0, n) {
            if (vals[i] == mx) {
                vals[i] = 0;
            } else {
                ++vals[i];
                return true;
            }
        }
        return false;
    };
    
    mint ans = 0;
    do {
        ll an = vals[0], xr = vals[0];
        rep(i, 1, n) {
            an &= vals[i];
            xr ^= vals[i];
        }
        ans += an >= xr;
    } while (inc());
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (1) {
        ll n = rand() % 5 + 1;
        ll k = rand() % 5;
        auto ans = solve(n, k);
        auto exp = brute(n, k);
        if (ans.x == exp.x) {
            cout << "OK" << endl;
            continue;
        }
        ofstream inp("main.inp");
        inp << "1\n" << n << ' ' << k << endl;
        inp << db(ans) << db(exp) << endl;
        inp.close();
        cout << "FAILED" << endl;
        exit(0);
    }
}

int main() {
    precal();
    // check();    
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int ntest; 
    cin >> ntest;
    while (ntest--) {
        ll  n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
#ifdef LOCAL
        cout << db(brute(n, k)) << endl;
#endif
    }
    
    return 0;
}

// vim: foldmethod=marker