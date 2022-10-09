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

const int maxn = 101010;
const int inf = maxn;
int n;
vector<int> gr[maxn];
struct DPval {
    int val;
    int bu, bv;
    
    operator int() const {
        return val;
    }
    
    // friend bool operator<(const DPval& u, const DPval& v) { 
        // return u.val < v.val; 
    // } 
    
    friend ostream& operator<<(ostream& out, const DPval& u) { 
        return out << "(" << u.val << ", " << u.bu << ", " << u.bv << ")" ;
    }
};
DPval dp[maxn][2];

void dfs(int u, int p) {
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    
    int sum_dp0 = 0;
    multiset<pair<int, int>> diff;
    for (auto v: gr[u]) {
        if (v == p) continue;
        sum_dp0 += dp[v][0];
        diff.emplace(dp[v][1] - dp[v][0], v);
        if (sz(diff) > 2) diff.erase(--diff.end());
    }
    
    dp[u][1] = {sum_dp0 + 1, -1, -1};
    for (auto v: gr[u]) {
        if (v == p) continue;
        dp[u][1] = min(dp[u][1], {sum_dp0 - dp[v][0] + dp[v][1], v, -1});
    }
    
    dp[u][0] = dp[u][1];
    if (sz(diff) > 1) {
        auto x = diff.begin();
        auto y = next(x);
        dp[u][0] = min(dp[u][0], {sum_dp0 + x->first + y->first - 1, x->second, y->second});
    }
    clog << db(u) << db(sum_dp0) << db(dp[u][0]) << db(dp[u][1]) << endl;
}

vector<pair<int, int>> rem_list, chain_list;
int trace(int u, bool state, int p, bool add) {
    clog << db(dp[u][state]) << endl;
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (v == dp[u][state].bu or v == dp[u][state].bv) continue;
        trace(v, 0, u, 1);
        rem_list.emplace_back(u, v);
    }
    
    if (dp[u][state].bu == -1) {
        if (add) chain_list.emplace_back(u, u);
        return u;
    }
    int bu = trace(dp[u][state].bu, 1, u, 0);
    if (dp[u][state].bv == -1) {
        if (add) {
            chain_list.emplace_back(u, bu);
            return -1;
        }
        return bu;
    }
    int bv = trace(dp[u][state].bv, 1, u, 0);
    assert(add);
    chain_list.emplace_back(bu, bv);
    return -1;
}

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
        cin >> n;
        rep(i, 1, n + 1) gr[i].clear();
        rep(i, 0, n - 1) {
            int u, v; cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1, 1);
        cout << (int)min(dp[1][0], dp[1][1]) - 1 << '\n';
        clog << db(dp[1][0]) << db(dp[1][1]) << endl;
        rem_list.clear();
        chain_list.clear();
        trace(1, bool(dp[1][0] > dp[1][1]), 1, 1);
        clog << db(rem_list) << endl;
        clog << db(chain_list) << endl;
        assert(sz(rem_list) == sz(chain_list) - 1);
        assert(sz(chain_list) == (int)min(dp[1][0], dp[1][1]));
        
        rep(i, 0, sz(rem_list)) {
            cout << rem_list[i].first << ' ' << rem_list[i].second << ' ';
            cout << chain_list[i].second << ' ' << chain_list[i + 1].first << '\n';
        }
    }
        
    return 0;
}

// vim: foldmethod=marker