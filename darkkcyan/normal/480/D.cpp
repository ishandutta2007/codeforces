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

struct parcel {
    int in, out, w, s, v;
};

const int maxn = 555;
const int maxs = 2000;
int n, s;
parcel a[maxn];

vector<int> contains[maxn];

ll dp[maxn][maxs];

ll cal(int pid, int cap_left) {
    ll& ans = dp[pid][cap_left];
    if (ans != -1) return ans;
    ans = 0;
    for (auto u: contains[pid]) {
        if (a[u].w > cap_left) continue;
        int new_cap = min(cap_left - a[u].w, a[u].s);
        cal(u, new_cap);
    }
    
    static vector<ll> cur_dp;
    cur_dp.assign(2 * n + 1, 0);
    static vector<vector<int>> out_pos(2 * n + 1);
    for (auto u: contains[pid]) {
        if (a[u].w > cap_left) continue;
        out_pos[a[u].out].push_back(u);
    }
    rep(i, a[pid].in, a[pid].out + 1) {
        if (i) cur_dp[i] = max(cur_dp[i], cur_dp[i - 1]);
        for (auto u: out_pos[i]) {
            int new_cap = min(cap_left - a[u].w, a[u].s);
            cur_dp[i] = max(cur_dp[i], cur_dp[a[u].in] + cal(u, new_cap));
        }
        out_pos[i].clear();
        ans = max(ans, cur_dp[i]);
    }
    ans += a[pid].v;
    return ans;
}
        
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> s;
    rep(i, 0, n) {
        cin >> a[i].in >> a[i].out >> a[i].w >> a[i].s >> a[i].v;
    }
    
    a[n].in = 0;
    a[n].out = 2 * n;
    a[n].s = s;
    
    rep(i, 0, n + 1) {
        rep(f, 0, n) {
            if (i == f) continue;
            if (a[i].in <= a[f].in and a[f].out <= a[i].out) 
                contains[i].push_back(f);
        }
        sort(all(contains[i]), [&](int u, int v) {
                if (a[u].out == a[v].out) return a[u].in < a[v].in;
                return a[u].out < a[v].out;
                });
    }
    
    memset(dp, -1, sizeof(dp));
    cout << cal(n, s);
    
    return 0;
}

// vim: foldmethod=marker