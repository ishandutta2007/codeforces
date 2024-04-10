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

const int maxn = 301010;
int n;
vector<int> g1[maxn], g2[maxn];
int eu_start[maxn], eu_end[maxn], timer;
void dfs_find_eu2(int u) {
    eu_start[u] = timer;
    for (auto v: g2[u]) {
        dfs_find_eu2(v);
    }
    if (sz(g2[u]) == 0) ++timer;
    eu_end[u] = timer;
}

bool is_cover(const pair<int, int>& outer, const pair<int, int>& inner) {
    return outer.first <= inner.first and inner.second <= outer.second;
}

map<int, int> moments;
pair<pair<int, int>, bool> change(int u) {
    auto it = moments.lower_bound(eu_start[u]);
    if (it != moments.end() and is_cover({eu_start[u], eu_end[u]}, *it)) return {{-1, -1}, false};
    
    pair<int, int> ans{-1, -1};
    it = moments.upper_bound(eu_start[u]);
    if (it != moments.begin()) {
        --it;
        if (is_cover(*it, {eu_start[u], eu_end[u]})) {
            ans = *it;
            moments.erase(it);
        }
    }
    moments[eu_start[u]] = eu_end[u];
    return {ans, true};
}

int dfs_find_ans1(int u) {
    auto [rem, added] = change(u);
    int ans = sz(moments);
    for (auto v: g1[u]) {
        ans = max(ans, dfs_find_ans1(v));
    }
    
    if (added) {
        moments.erase(eu_start[u]);
    }
    if (rem.first != -1) {
        moments.insert(rem);
    }
    
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, 1, n + 1) {
            g1[i].clear();
            g2[i].clear();
        }
        
        rep(i, 2, n + 1) {
            int p; cin >> p;
            g1[p].push_back(i);
        }
        rep(i, 2, n + 1) {
            int p; cin >> p;
            g2[p].push_back(i);
        }
        timer = 0;
        moments.clear();
        dfs_find_eu2(1);
        int ans = dfs_find_ans1(1);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker