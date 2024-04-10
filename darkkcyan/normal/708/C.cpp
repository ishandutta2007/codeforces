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

const int maxn = 401010;
int n;
vector<int> gr[maxn];
int cnt_child[maxn];
void dfs(int u, int p) {
    cnt_child[u] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt_child[u] += cnt_child[v];
    }
}

pair<int, int> find_cen() {
    dfs(1, 1);
    int u = 1, p = 1;
    while (true) {
        int big_child = -1;
        for (auto v: gr[u]) {
            if (v == p) continue;
            if (big_child == -1 or cnt_child[big_child] < cnt_child[v])
                big_child = v;
        }
        if (big_child == -1) break;
        if (cnt_child[big_child] * 2 > n) {
            p = u;
            u = big_child;
        } else break;
    }
    return {u, p};
}

int ans[maxn];
void fill_ans(int u, int p, int cut_branch) {
    if ((n - cnt_child[u] - cut_branch) * 2 > n) return; 
    ans[u] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        fill_ans(v, u, cut_branch);
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    bool is_test = false;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        if (i == 0 and n == 400000 and u ==  110776  and v == 198641) is_test = true;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    auto [cen, cen_par] = find_cen();
    if (cen_par != cen) {
        dfs(cen_par, cen);
        cnt_child[cen] = n;
    }
    
    if (is_test) {
        // cout << cen << ' ' << cen_par << endl; 
    }
    
    clog << db(cen) << db(cen_par) << endl;
    multiset<int> cnt_se;
    for (auto v: gr[cen]) {
        cnt_se.insert(cnt_child[v]);
    }
    
    auto big = *cnt_se.rbegin();
    int snd_big = (n - big) * 2 <= n ? n - big : sz(cnt_se) >= 2 ? *next(cnt_se.rbegin()) : n - big;
    clog << db(big) << db(snd_big) << endl;
    ans[cen] = 1;
    for (auto v: gr[cen]) {
        if (cnt_child[v] != big) fill_ans(v, cen, big);
        else fill_ans(v, cen, snd_big);
    }
    
    rep(i, 1, n + 1) cout << ans[i] << ' ';
        
    
    return 0;
}

// vim: foldmethod=marker