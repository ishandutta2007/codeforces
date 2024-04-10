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

const int maxn = 301010;
int n;

vector<int> gr[maxn];

vector<int> dp_sing[maxn];
void dfs(int u, int p) {
    vector<vector<int>> groups(sz(gr[u]) - (u != p) + 1);
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        rep(i, 1, min(sz(dp_sing[v]), sz(groups))) {
            groups[i].push_back(dp_sing[v][i]);
        }
    }
    
    dp_sing[u].resize(sz(groups));
    rep(i, 1, sz(dp_sing[u])) {
        if (sz(groups[i]) < i) {
            dp_sing[u][i] = 2;
        } else {
            nth_element(groups[i].begin(), groups[i].begin() + i - 1, groups[i].end(), greater<int>());
            dp_sing[u][i] = groups[i][i - 1] + 1;
        }
    }
}

struct DP {
    ll cur_ans;
    vector<int> val;
    DP(): cur_ans(0), val{} {}
    void update(const vector<int>& other) {
        val.resize(max(sz(val), sz(other)));
        rep(i, 0, sz(other)) {
            cur_ans -= val[i];
            val[i] = max(val[i], other[i]);
            cur_ans += val[i];
        }
    }
    void update(const DP& other) {
        update(other.val);
    }
};

DP dp[maxn];
ll dfs2(int u, int p) {
    DB();
    clog << db(u) << db(p) << endl;
    ll ans = 0;
    int big = -1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        ans += dfs2(v, u);
        if (big == -1 or sz(dp[big].val) < sz(dp[v].val)) big = v;
    }
    clog << db(big) << endl;
    if (big != -1) {
        dp[u] = move(dp[big]);
    }
    dp[u].update(dp_sing[u]);
    for (auto v: gr[u]) {
        if (v == p or v == big) continue;
        dp[u].update(dp[v]);
    }
    ans += dp[u].cur_ans;
    ans += n - sz(dp[u].val) + 1;
    clog << db(dp_sing[u]) << db(dp[u].cur_ans) << endl;
    clog << db(dp[u].val) << endl;
    clog << db(ans) << endl;
    clog << db(u) << db(p) << endl;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, 1);
    ll ans = dfs2(1, 1);
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker