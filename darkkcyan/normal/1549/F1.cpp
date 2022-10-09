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

const int maxn = 6060;
#define xx first
#define yy second
ll choose(ll n, ll k) {
    if (k < 0 or n < k) return 0;
    ll ans = 1;
    rep(i, 0, k) ans *= n - i;
    rep(i, 1, k + 1) ans /= i;
    return ans;
}

int n;
pair<int, int> a[maxn];

ll solve_d1() {
    int cnt[4][4] = {0};
    rep(i, 0, n) {
        cnt[a[i].xx & 3][a[i].yy & 3]++;
    }
    
    vector<pair<int, int>> pos_cases = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    int cnt_cases[4][4] = {0};
    
    auto mod4 = [&](const pair<int, int>& u, const pair<int, int>& v) {
        return u == v ? 0 : 2;
    };
    
    ll ans = 0;
    for (auto x: pos_cases) {
        ++cnt_cases[x.xx][x.yy];
        for (auto y: pos_cases) {
            if (y < x) continue;
            ++cnt_cases[y.xx][y.yy];
            for (auto z: pos_cases) {
                if (z < y) continue;
                int m4 = mod4(x, y) + mod4(y, z) + mod4(z, x);
                if (m4 & 3) continue;
                ++cnt_cases[z.xx][z.yy];
                ll cur_ans = 1;
                for (auto way: pos_cases) {
                    cur_ans *= choose(cnt[way.xx][way.yy], cnt_cases[way.xx][way.yy]);
                }
                ans += cur_ans;
                --cnt_cases[z.xx][z.yy];
            }
            --cnt_cases[y.xx][y.yy];
        }
        --cnt_cases[x.xx][x.yy];
    }
    return ans;
}

ll solve_d2() {
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    bool is_d1 = true;
    rep(i, 0, n) {
        cin >> a[i].xx >> a[i].yy;
        if (a[i].xx & 1) is_d1 = false;
        if (a[i].yy & 1) is_d1 = false;
    }
    
    if (is_d1) {
        cout << solve_d1();
    } else {
        cout << solve_d2();
    }
    
    return 0;
}

// vim: foldmethod=marker