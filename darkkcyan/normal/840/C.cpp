#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
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


#define def_op(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op##=(const type& o)

template<int mod_>
struct modint {
    static constexpr int mod = mod_;
    int x;
    modint(int xx=0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    def_op(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    def_op(modint, -) {
        if ((x -= o.x) < 0) x += mod;
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
    
    friend bool operator ==(const modint& u, const modint& v) {
        return u.x == v.x;
    }
    friend ostream& operator<<(ostream& out, const modint& u) {
        return out << u.x;
    }
};
using mint = modint<(int)1e9 + 7>;
const int maxn = 696;

mint comb[maxn][maxn];
mint fac[maxn];
void precal() {
    rep(i, 0, maxn) {
        comb[i][0] = 1;
        rep(f, 1, i + 1) {
            comb[i][f] = comb[i - 1][f] + comb[i - 1][f - 1];
        }
    }
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
}

int reduce_factor(int num) {
    int ans = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i) continue;
        // clog << db(num) << db(i) << endl; 
        int cnt = 0;
        while (num % i == 0) {
            num /= i;
            cnt ^= 1;
        }
        if (cnt) ans *= i;
    }
    if (num > 1) ans *= num;
    return ans;
}

mint brute(const vector<int>& a) {
    auto is_perfect_sqr = [&](ll num) {
        ll x = (ll)round(sqrt(num));
        return x * x == num;
    };
    
    vector<int> pos(sz(a));
    rep(i, 0, sz(a)) pos[i] = i;
    mint ans = 0;
    do {
        bool ok = true;
        rep(i, 0, sz(a) - 1) {
            if (!is_perfect_sqr(1ll * a[pos[i]] * a[pos[i + 1]])) continue;
            ok = false;
            break;
        }
        ans += ok;
    } while (next_permutation(all(pos)));
    return ans;
}

mint solve(const vector<int>& a) {
    map<int, int> cnt;
    for (auto i: a) {
        int rd = reduce_factor(i);
        clog << db(i) << db(rd) << endl;
        cnt[rd]++;
    }
    
    // clog << db(cnt) << endl; 
    
    vector<mint> dp = {1};
    int cnt_have = 0;
    
    for (auto [val, cur_cnt]: cnt) {
        DB();
        clog << db(val) << db(cur_cnt) << endl;
        vector<mint> new_dp(sz(a) + 2);
        
        auto cur_fac = fac[cur_cnt];
        rep(prev_same_pos, 0, sz(dp)) {
            if (dp[prev_same_pos] == 0) continue;
            int prev_res_pos = cnt_have + 1 - prev_same_pos;
            rep(cnt_group, 1, cur_cnt + 1) {
                DB();
                clog << db(cnt_group) << endl;
                int add_same_pos = cur_cnt - cnt_group;
                
                rep(choose_same_pos, 0, prev_same_pos + 1) {
                    int choose_res_pos = cnt_group - choose_same_pos;
                    if (choose_res_pos < 0) break;
                    if (choose_res_pos > prev_res_pos) continue;
                    int new_same_pos = prev_same_pos + add_same_pos - choose_same_pos;
                    mint cur_ans =
                        comb[prev_same_pos][choose_same_pos] *
                        comb[prev_res_pos][choose_res_pos] *
                        // comb[cnt_group][choose_same_pos] * 
                        comb[cur_cnt - 1][cnt_group - 1] * 
                        dp[prev_same_pos];
                    clog << db(choose_same_pos) << db(new_same_pos) << db(cur_ans) << endl;
                    
                    new_dp[new_same_pos] += cur_fac * cur_ans;
                }
            }
        }
        swap(dp, new_dp);
        while (dp.size() and dp.back() == 0) dp.pop_back();
        cnt_have += cur_cnt;
        clog << db(dp) << endl;
        clog << db(cnt_have) << endl;
    }
    return dp[0];
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        int n = rand() % 5 + 1;
        vector<int> a(n);
        rep(i, 0, n) a[i] = rand() % 100 + 1;
        ofstream inp("main.inp");
        inp << n << endl;
        rep(i, 0, n) inp << a[i] << ' ';
        inp << endl;
        auto ans = solve(a);
        auto exp = brute(a);
        inp << db(ans) << db(exp) << endl;
        inp.close();
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    // cout << brute(a); 
    cout << solve(a) << endl;
    
    return 0;
}

// vim: foldmethod=marker