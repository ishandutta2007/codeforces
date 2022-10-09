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
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

#define def_op(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op## =(const type& o) 
template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    def_op(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    def_op(modint, -) {
        if ((x -= o.x) < mod) x += mod;
        return *this;
    }
    def_op(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    modint pow(ll exp) const {
        modint base = *this, ans = 1;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    def_op(modint, /) {
        return *this *= o.pow(mod - 2);
    }
};

const int maxn = 401010;
using mint = modint<(int)1e9 + 7>;
mint fac[maxn], ifac[maxn];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = 1 / fac[maxn - 1];
    for (int i = maxn - 1; i--; ) ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int n, int k) {
    if (n < k or k < 0) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n, l, r;
        cin >> n >> l >> r;
        
        if (1 - l > r - n) {
            tie(l, r) = pair{1 - (r - n), n + (1 - l)};
        }
        clog << db(l) << db(r) << endl;
        
        mint ans = 0;
        
        {
            int first_neg_cnt = 1 - l;
            int last_pos_cnt = r - n;
            mint choices = min(first_neg_cnt, last_pos_cnt);
            clog << db(choices.x) << endl;
            auto cur_ans = choose(n, n / 2) * choices;
            // cur_ans += choose(n - 1, n / 2); 
            if (n & 1) {
                cur_ans += choose(n, n - n / 2) * choices;
                // cur_ans += choose(n - 1, n - n / 2); 
            }
            clog << db(cur_ans.x) << endl;
            ans += cur_ans;
        }
        
        int neg_val = l - 1;
        int last_pos = n;
        rep(first_neg, 2, n + 1) {
            DB();
            --neg_val;
            int pos_val = -neg_val;
            while (last_pos >= 1 and r - last_pos < pos_val) -- last_pos;
            // if (last_pos < first_neg) break;  
            DB();
            mint cur_ans = 0;
            int cnt_fix = n - last_pos;
            int cnt_var = last_pos - first_neg + 1;
            cur_ans += choose(cnt_var, n / 2 - cnt_fix);
            if (n & 1) cur_ans += choose(cnt_var, n - n / 2 - cnt_fix);
            clog << db(first_neg) << db(cnt_var) << db(cnt_fix) << db(cur_ans.x) << endl;
            clog << db(last_pos) << endl;
            clog << db(neg_val) << db(pos_val) << endl;
            ans += cur_ans;
        }
        // ans += 1; 
        cout << ans.x << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker