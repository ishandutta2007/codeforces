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

int n, m;

struct modint {
    int x; 
    modint(int x_ = 0) : x(x_) {}
    modint(ll x_) : x((int)(x_ % m)) {}
    
#define fr friend
#define op operator
    fr modint op+(modint u, modint v) {
        u.x += v.x;
        if (u.x >= m) u.x -= m;
        return u;
    }
    fr modint op-(modint u, modint v) {
        u.x -= v.x;
        if (u.x < 0) u.x += m;
        return u;
    }
    
    fr modint op*(modint u, modint v) {
        return 1ll * u.x * v.x;
    }
    
    fr ostream& op<<(ostream& out, modint t) {
        return out << t.x;
    }
};

const int maxn = 444;

modint comb[maxn][maxn];
modint fac[maxn];
modint p2[maxn];
void precal() {
    comb[0][0] = 1;
    rep(i, 1, maxn) {
        comb[i][0] = 1;
        rep(f, 1, i + 1)
            comb[i][f] = comb[i - 1][f] + comb[i - 1][f - 1];
    }
    
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    p2[0] = 1;
    rep(i, 1, maxn) p2[i] = p2[i - 1] * 2;
}

modint dp[maxn][maxn];
modint cal(int len, int cnt_op) {
    DB();
    if (len <= 0 or cnt_op < 0) return 0;
    if (cnt_op > len) return 0;
    
    auto& ans = dp[len][cnt_op];
    if (ans.x != -1) return ans;
    ans = (cnt_op == len ? p2[len - 1] : 0);
    rep(head, 1, len + 1) {
        auto based_ans = p2[head - 1];
        int rest = len - head - 1;
        int rest_op = cnt_op - head;
        if (rest_op < 0) continue;
        ans = ans + comb[cnt_op][rest_op] * cal(rest, rest_op) * based_ans;
    }
    clog << db(ans) << endl;
    return ans;
}

modint cal(int x) {
    modint ans = 0;
    rep(i, 0, x + 1) ans = ans + cal(x, i);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; 
    // m = 1e9 + 7; 
    precal();
    
    
    memset(dp, -1, sizeof(dp));  
    // rep(i, 1, 100) {  
        // cout << db(i) << db(cal(i))  << endl; 
    // }  
    
    cout << cal(n) << endl; 
    
    return 0;
}

// vim: foldmethod=marker