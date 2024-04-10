#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-10;
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

const int maxm = (int)1e5 + 100;
ld log_fac[maxm];
void precal() {
    log_fac[0] = log(1);
    rep(i, 1, maxm) log_fac[i] = log_fac[i - 1] + log(i);
}

inline ld fac(int n) {
    if (n < 0) return 0;
    return exp(log_fac[n]);
}

inline ld log_perm(int n, int k) {
    assert(n >= k and k >= 0);
    return log_fac[n] - log_fac[n - k];
}

inline ld perm(int n, int k) {
    if (k < 0 or n < k) return 0;
    return exp(log_perm(n, k));
}

inline ld log_choose(int n, int k) {
    assert(n >= k and k >= 0);
    return log_fac[n] - log_fac[k] - log_fac[n - k];
}

inline ld choose(int n, int k) {
    if (n < k or k < 0) return 0;
    return exp(log_choose(n, k));
}

const ld too_big = 1e99;
// const ld log2 = log(2); 

const int maxn = 333;
int n, m, k;

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    ld log_all_cases = log_perm(m, n * n) + log_choose(m, k);
    clog << db(log_all_cases) << db(exp(log_all_cases)) << endl;
    ld ans = 0;
    {
        DB();
        rep(full_r, 0, n + 1) {
            rep(full_c, 0, n + 1) {
                // if ((full_r == n) != (full_c == n)) continue; 
                int cnt_must = n * (full_r + full_c) - full_r * full_c;
                if (cnt_must > k) continue; 
                int cell_left = n * n - cnt_must;
                int val_left = m - cnt_must;
                auto cur_ans = log_choose(m, k) + log_perm(k, cnt_must);
                cur_ans += log_perm(val_left, cell_left);
                cur_ans -= log_all_cases; 
                ld cur_log_choose = log_choose(n, full_r) + log_choose(n, full_c);
                ans += exp(cur_log_choose + cur_ans);
                if (ans > too_big) {
                    cout << "1e99";
                    return 0;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << min(ans, too_big) << endl;
    
    return 0;
}

// vim: foldmethod=marker