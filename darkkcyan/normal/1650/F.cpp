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
 
const ll inf = (ll)1e15;
struct DP {
    ll min_time;
    int trace;
};

struct Options {
    ll t;
    int p;
    int id;
};

bool operator<(const DP& u, const DP& v) {
    return u.min_time < v.min_time;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (auto& i: a) cin >> i;
        vector<vector<Options>> opts(n);
        rep(i, 0, m) {
            int e, p;
            ll t;
            cin >> e >> t >> p;
            opts[e - 1].push_back({t, p, i});
        }
        
        ll cur_time = 0;
        vector<int> actions;
        rep(i, 0, n) {
            auto& cur_opts = opts[i];
            vector<vector<DP>> dp(sz(cur_opts) + 1, vector<DP>(101, {inf, -1}));
            dp[0][0].min_time = 0;
            
            rep(f, 0, sz(cur_opts)) {
                rep(per, 0, 101) 
                    dp[f + 1][per].min_time = dp[f][per].min_time;
                rep(prev_per, 0, 101) {
                    if (dp[f][prev_per].min_time >= inf) continue;
                    auto& cd = dp[f + 1][min(prev_per + cur_opts[f].p, 100)];
                    ll new_time = dp[f][prev_per].min_time + cur_opts[f].t;
                    if (new_time < cd.min_time) {
                        cd = {new_time, prev_per};
                    }
                }
            }
            if (cur_time + dp.back()[100].min_time > a[i]) {
                actions.clear();
                break;
            }
            cur_time += dp.back()[100].min_time;
            int cur_per = 100;
            for (int f = sz(cur_opts); f--; ) {
                if (dp[f + 1][cur_per].trace == -1) continue;
                actions.push_back(cur_opts[f].id);
                cur_per = dp[f + 1][cur_per].trace;
            }
        }
        if (actions.empty()) {
            cout << "-1\n";
            continue;
        }
        cout << actions.size() << '\n';
        for (auto& i: actions) cout << i + 1 << ' ';
        cout << '\n';
    }
    
    
    return 0;
}