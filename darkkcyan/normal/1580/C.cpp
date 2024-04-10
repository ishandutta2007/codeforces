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

const int maxn = 202020;
const int bs = 500;

int n, m;
int x[maxn], y[maxn];
int added_day[maxn];

int cur_day;

int small_count[bs][bs];
int big_delta[maxn];
int cur_sum_big;

inline auto change_delta(ll pos, int delta) {
    if (pos >= maxn) return; 
    big_delta[pos] += delta;
}

void add_big(int i) {
    for (ll pos = cur_day; pos <= m; pos += 1ll * x[i] + y[i]) {
        change_delta(pos + x[i], 1);
        change_delta(pos + x[i] + y[i], -1);
    }
    added_day[i] = cur_day;
}

void rem_big(int i) {
    for (ll pos = added_day[i]; pos <= m; pos += 1ll * x[i] + y[i]) {
        change_delta(pos + x[i], -1);
        change_delta(pos + x[i] + y[i], 1);
    }
    
    ll dist = (cur_day - added_day[i]) % (1ll * x[i] + y[i]);
    cur_sum_big -= dist >= x[i];
}

void add_small(int i) {
    // DB(); 
    int period = x[i] + y[i];
    // clog << "add small" << db(i) << db(x[i]) << db(y[i]) << db(period) << endl; 
    auto& cur_cnt = small_count[period];
    
    int cur_pos = (cur_day + x[i]) % period;
    rep(pos, x[i], period) {
        cur_cnt[cur_pos] ++;
        ++cur_pos;
        if (cur_pos >= period) cur_pos = 0;
    }
    added_day[i] = cur_day;
}

void rem_small(int i) {
    // DB(); 
    int period = x[i] + y[i];
    // clog << "rem small" << db(i) << db(x[i]) << db(y[i]) << db(period) << endl; 
    auto& cur_cnt = small_count[period];
    
    int cur_pos = (added_day[i] + x[i]) % period;
    rep(pos, x[i], period) {
        cur_cnt[cur_pos]-- ;
        ++cur_pos;
        if (cur_pos >= period) cur_pos = 0;
    }
}

inline int get_ans() {
    int ans = cur_sum_big;
    rep(i, 1, bs) {
        ans += small_count[i][cur_day % i];
    }
    return ans;
}

int jalsol_orz() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }
    
    for (cur_day = 0; cur_day < m; ++cur_day) {
        cur_sum_big += big_delta[cur_day];
        int op, k;
        cin >> op >> k;
        --k;
        bool is_big = (x[k] + y[k]) >= bs;
        if (is_big) {
            if (op == 1) add_big(k);
            else rem_big(k);
        } else {
            if (op == 1) add_small(k);
            else rem_small(k);
        }
        
        auto ans = get_ans();
        cout << ans << '\n';
        if (k == 0) {
            clog << db(cur_day) << endl;
        }
    }
    
    return 0;
}

// vim: foldmethod=marker