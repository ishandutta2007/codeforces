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
 
#define defop(type, op) \
    friend inline type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o)

template<int mod>
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_) : x(int(x_ % mod)) {}
    
    defop(modint, +) { return ((x += o.x) >= mod) and (x -= mod), *this; }
    defop(modint, -) { return ((x -= o.x) < 0) and (x += mod), *this; }
    defop(modint, *) { return *this = modint(1ll * x * o.x); }
    defop(modint, /) { return *this *= o.pow(mod - 2); }
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    bool operator<=>(const modint& o) const = default;
    friend print_op(modint) { return out << u.x; }
};

using mint = modint<998'244'353>;

const int maxn = 101010;
mint fac[maxn], ifac[maxn];

void precal() {
    fac[0] = 1;
    rep(i, 1, maxn)
        fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = mint(1) / fac[maxn - 1];
    for (int i = maxn - 1; i--; ) 
        ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int n, int k) {
    if (n < k or k < 0) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

int n;
int a[maxn];

mint solve_(int l, int r);
mint solve(int l, int r) {
    DB();
    clog << db(l) << db(r) << endl;
    auto ans = solve_(l, r);
    clog << db(l) << db(r) << db(ans) << endl;
    return ans;
}

// [l, r)
mint solve_(int l, int r) {
    if (r - l <= 1) return 1;
    
    ll sum_left = 0;
    ll sum_right = 0;
    if (a[l] > 0) {
        sum_left = a[l++];
    } else if (a[r - 1] > 0) {
        sum_right = a[--r];
    } else {
        ++l;
        --r;
    }
    while (l < r and sum_left != sum_right) {
        while (l < r and sum_left < sum_right) {
            sum_left += a[l++];
        }
        while (l < r and sum_right < sum_left) {
            sum_right += a[--r];
        }
    }
    
    clog << db(l) << db(r) << db(sum_left) << db(sum_right) << endl;
    
    if (sum_left != sum_right) {
        return 1;
    }
    
    int cnt0_left = 0;
    int cnt0_right = 0;
    while (l < r and a[l] == 0) {
        cnt0_left ++;
        ++l;
    }
    if (l == r) {
        return mint(2).pow(cnt0_left + 1);
    }
    
    while (l < r and a[r - 1] == 0) {
        cnt0_right++;
        --r;
    }
    
    auto part_left = cnt0_left + 1;
    auto part_right = cnt0_right + 1;
    
    auto rec_ans = solve(l, r);
    mint ans = 0;
    rep(split, 0, min(part_left, part_right) + 1) {
        ans += rec_ans * choose(part_left, split) * choose(part_right, split);
    }
    return ans;
}

mint brute() {
    mint ans = 0;
    rep(split_mask, 0, (1ll << (n - 1))) {
        vector<ll> sum;
        int prv = 0;
        rep(i, 0, n - 1) {
            if (!((split_mask >> i) & 1)) continue;
            ll& cur_sum = sum.emplace_back(0);
            rep(f, prv, i + 1) {
                cur_sum += a[f];
            }
            prv = i + 1;
        }
        
        ll& cur_sum = sum.emplace_back(0);
        rep(f, prv, n) {
            cur_sum += a[f];
        }
        clog << db(split_mask) << db(sum) << endl;
        auto t = sum;
        ranges::reverse(t);
        ans += t == sum;
    }
    return ans;
}

mt19937 rng;
int rand(int l, int r) {
    return l + (int)(rng() % (r - l + 1));
}
void check() {
    n = rand(1, 6);
    rep(i, 0, n) a[i] = rand(0, 10);
    ofstream inp("main.inp");
    inp << 1 << endl;
    inp << n << endl;
    rep(i, 0, n) inp << a[i] << ' ';
    auto ans = solve(0, n);
    auto exp = brute();
    inp << endl;
    inp << db(ans) << db(exp) << endl;
    inp.close();
    assert(ans == exp);
    cout << "OK" << endl;
}

int main() {
    precal();
#ifdef LOCAL
    // while (true) check();
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        DB();
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        cout << solve(0, n) << '\n';
#ifdef LOCAL
        cout << db(brute()) << endl;
#endif
    }
    
    
    return 0;
}