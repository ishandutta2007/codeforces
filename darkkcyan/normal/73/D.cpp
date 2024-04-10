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

const int maxn = 1010101;
int n, m, k;
vector<int> gr[maxn];
bool vis[maxn];

int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int cnt = 1;
    for (auto v: gr[u]) cnt += dfs(v);
    return cnt;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<int> comp_sz; 
    rep(i, 1, n + 1) {
        if (vis[i]) continue;
        comp_sz.push_back(dfs(i));
    }
    
    if (k == 0) cout << sz(comp_sz) - 1;
    else if (k == 1) cout << max(0, sz(comp_sz) - 2);
    else {
        int ans = 0;
        int cnt_con = 0;
        int cnt_single = 0;
        for (auto u: comp_sz) {
            u = min(u, k);
            if (u == 1) cnt_single ++;
            else cnt_con += u - 2;
        }
        if (cnt_single > 1) {
            --cnt_single;
        }
        if (cnt_single > 1) {
            --cnt_single;
        }
        int rem = max(0, cnt_single - cnt_con);
        clog << db(rem) << endl;
        ans += (rem + 1) / 2;
        cout << ans;
    }
    
    return 0;
}

// vim: foldmethod=marker