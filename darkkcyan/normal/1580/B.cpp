#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;


#define jalsol_orz main   // I did this for a meme :D


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

#define defop(type, op) \
    friend inline type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o) 
int mod;
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    
    defop(modint, +) {
        if ((x += o.x) >= mod) x-= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
    
    friend print_op(modint) {
        return out << u.x;
    }
};

const int maxn = 111;
using mint = modint;

int n, m, k;
mint dp[maxn][maxn][maxn];

mint fac[maxn];
mint choose[maxn][maxn];

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> k >> mod;
    
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    rep(i, 0, maxn) {
        choose[i][0] = 1;
        rep(f, 1, i + 1) {
            choose[i][f] = choose[i - 1][f] + choose[i - 1][f - 1];
        }
    }
    
    rep(cur_m, 1, m + 1) dp[0][cur_m][0] = 1;
    
    rep(cur_len, 1, n + 1) {
        DB();
        clog << db(cur_len) << endl;
        rep(left_len, 0, cur_len) {
            int right_len = cur_len - left_len - 1;
            clog << db(left_len) << db(right_len) << endl;
            rep(pref_m, 0, m) {
                auto &cur_dp_layer = dp[cur_len][pref_m + 1];
                auto& left_dp_layer = dp[left_len][pref_m];
                rep(left_cnt, 0, left_len + 1) {
                    auto left_dp = left_dp_layer[left_cnt] * choose[cur_len - 1][left_len];
                    if (left_dp.x == 0) continue;
                    auto &right_dp_layer = dp[right_len][pref_m];
                    rep(right_cnt, 0, right_len + 1) {
                        // dp[cur_len][pref_m + 1][left_cnt + right_cnt] += ( 
                            // dp[left_len][pref_m][left_cnt]* 
                            // dp[right_len][pref_m][right_cnt] 
                        // ) * choose[cur_len - 1][left_len]; 
                        // dp[cur_len][pref_m + 1][left_cnt + right_cnt] += (  
                            // left_dp *  
                            // dp[right_len][pref_m][right_cnt]  
                        // ); 
                        cur_dp_layer[left_cnt + right_cnt] += left_dp * right_dp_layer[right_cnt];
                    }
                }
            }
        }
        dp[cur_len][1][1] += fac[cur_len];
    }
    
    rep(i, 0, n + 1) {
        DB();
        rep(cm, 0, m + 1) {
            rep(cnt, 0, n + 1) {
                if (dp[i][cm][cnt].x)
                    clog << db(i) << db(cm) << db(cnt) << db(dp[i][cm][cnt]) << endl;
            }
        }
    }
    
    cout << dp[n][m][k];
    
    return 0;
}

// vim: foldmethod=marker