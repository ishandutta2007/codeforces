#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
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
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> p(n + 1);
        vector<vector<int>> children(n + 1);
        vector<vector<int>> level(n + 1);
        vector<int> depth(n + 1);
        for (int i = 2; i <= n; ++i) {
            cin >> p[i];
            children[p[i]].push_back(i);
        }
        for (int i = 2; i <= n; ++i) cin >> a[i];
        {
            depth[1] = 0;
            vector<int> st;
            for (st.push_back(1); len(st); ) {
                int u = st.back();
                st.pop_back();
                for (auto v: children[u]) {
                    depth[v] = depth[u] + 1;
                    level[depth[v]].push_back(v);
                    st.push_back(v);
                }
            }
        }
        clog << db(depth) << endl;
        
        const ll inf = 1e16;
        vector<ll> dp(n + 1, -inf);
        dp[1] = 0;
        
        int max_level = *max_element(be(depth));
        clog << db(max_level) << endl;
        for (int lv = 1; lv <= max_level; ++lv) {
            DB();
            clog << db(lv) << endl;
            sort(be(level[lv]), [&](int u, int v) { return a[u] < a[v]; });
            clog << db(level[lv]) << endl;
            
            set<pair<ll, int>> upper, lower;
            for (auto u: level[lv]) {
                upper.emplace(dp[p[u]] + a[u], u);
            }
            for (auto u: level[lv]) {
                for (auto v: {level[lv][0], level[lv].back()}) {
                    ll cur_cost = dp[p[u]] + abs(a[u] - a[v]);
                    dp[u] = max(dp[u], cur_cost);
                }
                if (len(upper)) dp[u] = max(dp[u], (--upper.end())->first - a[u]);
                if (len(lower)) dp[u] = max(dp[u], a[u] + (--lower.end())->first);
                upper.erase({dp[p[u]] + a[u], u});
                lower.emplace(dp[p[u]] - a[u], u);
            }
        }
        
        cout << *max_element(be(dp)) << '\n';
    }
    
    
    return 0;
}

// vim: foldmethod=marker