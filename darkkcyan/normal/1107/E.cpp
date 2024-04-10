#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define be(a) (a).begin(), (a).end()
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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s; cin >> s;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    
    const int maxn = 111;
    const ll inf = 1e15; 
    static array<vector<ll>, 2> dp[maxn][maxn];
    rep(i, 0, n) rep(f, 0, n + 1) {
        dp[i][f][0].push_back(-inf);
        dp[i][f][1].push_back(-inf);
    }
    
    auto um = [&](ll& u, ll v) {
        if (v > u) u = v;
    };
    auto get = [&](vector<ll>& what, int id) -> ll& {
        while (len(what) <= id) what.push_back(0);
        return what[id];
    };
    rep(i, 0, n) {
        dp[i][i + 1][s[i] - '0'].push_back(0);
        dp[i][i + 1][0][0] = dp[i][i + 1][1][0] = a[1];
    }
    
    rep(length, 2, n + 1) {
        rep(left, 0, n - length + 1) {
            int right = left + length;
            auto& cur = dp[left][right];
            rep(mid, left + 1, right)
            rep(tl, 0, 2) rep(tr, 0, 2) {
                auto& vl = dp[left][mid][tl];
                auto& vr = dp[mid][right][tr];
                rep(cnt_l, 0, len(vl)) 
                rep(cnt_r, 0, len(vr))  {
                    ll x = vl[cnt_l] + vr[cnt_r];
                    um(get(cur[tl], cnt_l), x + a[cnt_r]);
                    um(get(cur[tr], cnt_r), x + a[cnt_l]);
                    if (tl == tr) {
                        um(get(cur[0], 0), x + a[cnt_r + cnt_l]);
                        um(get(cur[1], 0), x + a[cnt_r + cnt_l]);
                        um(get(cur[tl], cnt_l + cnt_r), x);
                    }
                }
            }
        }
    }
    
    cout << max(dp[0][n][0][0], dp[0][n][1][0]);
    
    return 0;
}

// vim: foldmethod=marker