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

struct Job {
    int required;
    int gain;
    
    int min_level_after() const {
        return required + gain;
    }
};
const int maxn = 111;
const int inf = 101010;
int n, r;
Job a[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r;
    rep(i, 0, n) {
        cin >> a[i].required;
        cin >> a[i].gain;
    }
    
    vector<Job> pos, neg, zero;
    rep(i, 0, n) if (a[i].gain < 0) {
        neg.push_back(a[i]);
    } else if (a[i].gain > 0) {
        pos.push_back(a[i]);
    } else {
        zero.push_back(a[i]);
    }
    
    int ans = 0;
    while (sz(pos)) {
        int picked = -1;
        rep(i, 0, sz(pos)) {
            if (pos[i].required > r) continue;
            if (picked == -1 or pos[i].gain > pos[picked].gain) picked = i;
        }
        if (picked == -1) break;
        r += pos[picked].gain;
        swap(pos[picked], pos.back());
        pos.pop_back();
        ++ans;
    }
    
    for (auto i: zero) {
        if (i.required <= r) ++ans;
    }
    
    sort(all(neg), [&](const Job& u, const Job& v) {
            return max(0, u.min_level_after()) > max(0, v.min_level_after());
            });
    
    vector<int> cur_dp(r + 1, -inf);
    
    cur_dp[r] = 0;
    for (auto j: neg) {
        vector<int> new_dp = cur_dp;
        
        rep(prev_rat, max(j.required, -j.gain), r + 1) {
            new_dp[prev_rat + j.gain] = max(new_dp[prev_rat + j.gain], cur_dp[prev_rat] + 1);
        }
        
        swap(cur_dp, new_dp);
    }
    
    ans += *max_element(all(cur_dp));
    
    // cout << ans + *max_element(all(cur_dp)) << '\n'; 
    cout << (ans == n ? "YES" : "NO");
    
    return 0;
}

// vim: foldmethod=marker