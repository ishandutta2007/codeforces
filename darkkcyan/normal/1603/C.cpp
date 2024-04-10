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

#define defop(type, op) \
    friend inline type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ## =(const type& o)
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x((int)(xx % mod)) {}
    defop(modint, + ) {
        if ((x += o.x) >= mod) x -= mod;
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

using mint = modint<998'244'353>;

struct DP {
    int val;
    mint ans, cnt;
    friend print_op(DP) {
        return out << tuple{u.val, u.ans, u.cnt};
    }
};
mint solve(vector<int> a) {
    vector<DP> cur_dp {
        {INT_MAX, 0, 0}
    };
    mint ans = 0;
    for (int i = sz(a); i--; ) {
        DB();
        vector<DP> nxt_dp;
        
        int cur_div = 1;
        int ptr = 0;
        mint sum_ans = 0;
        mint sum_cnt = 0;
        while (cur_div <= a[i]) {
            DB();
            int ceil_d  = (a[i] + cur_div - 1) / cur_div;
            int floor_d = a[i] / cur_div;
            int nxt_div = a[i] / floor_d + (a[i] % floor_d != 0);
            if (ceil_d == floor_d) ++nxt_div;
            while (ptr < sz(cur_dp)  and cur_dp[ptr].val >= ceil_d) {
                sum_ans += cur_dp[ptr].ans;
                sum_cnt += cur_dp[ptr].cnt;
                ++ptr;
            }
            clog << db(cur_div) << db(nxt_div) << db(ceil_d) << db(floor_d) <<endl;
            clog << db(sum_ans) << db(sum_cnt) << endl;
            
            mint cur_cnt = sum_cnt + (cur_div == 1);
            mint cur_ans = cur_cnt * (cur_div - 1) + sum_ans;
            sum_cnt = 0;
            sum_ans = 0;
            clog << db(cur_cnt) << db(cur_ans) << endl;
            
            nxt_dp.push_back({floor_d, cur_ans, cur_cnt});
            
            cur_div = nxt_div;
            ans += cur_ans;
        }
        clog << db(i) << db(nxt_dp) << db(ans) << endl;
        
        swap(cur_dp, nxt_dp);
    }
    return ans;
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
        DB();
        clog << db(ntest) << endl;
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i: a) cin >> i;
        auto ans = solve(a);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker