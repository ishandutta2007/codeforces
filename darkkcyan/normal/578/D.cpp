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

struct State {
    bool nothing;
    bool skipped;
    bool added;
    bool both;
    
    State(bool n, bool s, bool a, bool b): nothing(n), skipped(s), added(a), both(b) {}
    State(int s): nothing(s & 1), skipped(s & 2), added(s & 4), both(s & 8) {}
    operator int() const {
        return (both << 3) | (added << 2) | (skipped << 1) | nothing;
    }
    
    friend print_op(State) {
        // print as bitset
        return out << u.nothing << u.skipped << u.added << u.both;
    }
};

int n, m;
string s;

const int maxn = 101'010;

ll dp[maxn][16];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    
    auto get_ch = [&](int pos) {
        if (pos < 0 or pos >= n) return -1;
        return s[pos] - 'a';
    };
    
    dp[0][State(1, 0, 0, 0)] = 1;
    rep(i, 0, n) {
        rep(cur_s, 0, 16) {
            auto cur_dp = dp[i][cur_s];
            if (cur_dp == 0) continue;
            auto [nothing, skipped, added, both] = State(cur_s);
            rep(new_ch, 0, m) {
                auto new_nothing = nothing and (new_ch == get_ch(i));
                auto new_skipped = (nothing or skipped) and (new_ch == get_ch(i + 1));
                auto new_added = nothing or (added and new_ch == get_ch(i - 1));
                auto new_both = skipped or ((both or added) and (new_ch == get_ch(i)));
                dp[i + 1][State(new_nothing, new_skipped, new_added, new_both)] += cur_dp;
            }
        }
    }
    
    rep(i, 0, n + 1) {
        DB();
        clog << db(i) << endl;
        rep(cur_s, 0, 16) {
            clog << db(State(cur_s)) << db(dp[i][cur_s]) << endl;
        }
    }
    
    ll ans = 0;
    rep(cur_s, 0, 16) {
        auto [nothing, skipped, added, both] = State(cur_s);
        if (nothing) continue;
        if (skipped or added or both) ans += dp[n][cur_s];
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker