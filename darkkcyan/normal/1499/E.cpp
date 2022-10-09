#include <bits/stdc++.h>
using namespace std;

#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define def_op(op, uop) \
    inline self_t& operator uop(const self_t& o) { CONCAT(op_helper, __LINE__)(o); return *this; } \
    friend inline self_t operator op (self_t lhs, const self_t & rhs) { return lhs uop rhs; } \
    inline void CONCAT(op_helper, __LINE__)(const self_t& o)
#define def_cmp_op(op, body) friend inline bool operator op(const self_t& u, const self_t& v) { return body; }
template<int mod>
struct ModInt {
    using self_t = ModInt<mod>;
    int x;
    ModInt(): x(0) {}
    ModInt(int v): x(v >= mod ? v - mod : v < 0 ? v + mod : v) {}
    ModInt(long long v): ModInt((int)(v % mod)) {}
    def_op(+, +=) {x += o.x; if (x >= mod) x -= mod;}
    def_op(-, -=) {x -= o.x; if (x < 0) x += mod;}
    def_op(*, *=) {x = (int)(1ll * x * o.x % mod); }
    def_op(/, /=) {x = o.pow(mod - 2, x).x; }
    self_t pow(long long exp, self_t ans = 1) const {
        self_t base = *this;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ans *= base;
            base *= base;
        }
        return ans;
    }
    def_cmp_op(==, u.x == v.x;)
    def_cmp_op(!=, u.x != v.x;) 
    def_cmp_op(<, u.x < v.x;) 
    friend ostream& operator<<(ostream& out, const self_t& u) { return out << u.x; }
};

using mint = ModInt<998'244'353>;


using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

const int maxn = 1010;
string a, b;
mint dp[maxn][maxn][2];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    
    // dp[1][0][0] = dp[0][1][1] = 1;  
    // for (int i = 2; i <= len(a); ++i) {  
        // if (a[i - 1] != a[i - 2]) dp[i][0][0] = dp[i - 1][0][0];  
        // dp[i][0][0] += 1;  
    // }  
    // for (int i = 2; i <= len(b); ++i) {  
        // if (b[i - 1] != b[i - 2]) dp[0][i][1] = dp[0][i - 1][1];  
        // dp[0][i][1] += 1;  
    // }  
    
    auto cal_max_diff = [&](const string& str) {
        vector<int> ans(len(str));
        ans[0] = 1;
        rep1(i, len(str) - 1) {
            if (str[i] != str[i - 1]) ans[i] = ans[ i - 1];
            ++ans[i];
        }
        return ans;
    };
    vector<int> max_diff_a = cal_max_diff(a), max_diff_b = cal_max_diff(b);
    
    mint ans = 0;
    rep1(i, len(a))
    rep1(f, len(b)) 
    rep(cur_end, 2) {
        char cur = cur_end ? b[f - 1] : a[i - 1];
        int pi = i - (cur_end == 0), pf = f - (cur_end == 1);
        rep(prev_end, 2) {
            if (prev_end == 0 and pi == 0) continue;
            if (prev_end == 1 and pf == 0) continue;
            char prv = prev_end ? b[pf - 1] : a[pi - 1];
            if (prv == cur) continue;
            // clog << db(i) << db(f) << db(pi) << db(pf) << db(cur_end) << db(prev_end) << db(cur) << db(prv) << endl; 
            dp[i][f][cur_end] += dp[pi][pf][prev_end];
        }
        dp[i][f][cur_end] += (a[i - 1] != b[f - 1]) * (cur_end ? max_diff_a[i - 1] : max_diff_b[f - 1]);
    }
    rep(i, len(a) + 1) {
        rep(f, len(b) + 1) ans += dp[i][f][0] + dp[i][f][1];
    }
    
    cout << ans;
    
#ifdef LOCAL
    rep(i, len(a) + 1) {
        rep(f, len(b) + 1) {
            cerr << dp[i][f][0] << ":" << dp[i][f][1] << ' ';
        }
        cerr << endl;
    }
#endif
    
    return 0;
}

// vim: foldmethod=marker