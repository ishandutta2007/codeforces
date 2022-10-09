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

const int maxn = 201000;
int n;
vector<int> gr[maxn];

int used[maxn], timer = 0;
vector<int> par[2];
void dfs(int u, int p, int d = 0) {
    par[d].push_back(u);
    for (auto& v: gr[u]) {
        if (v == p) continue;
        dfs(v, u, !d);
    }
}

int ans[maxn];
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
        cin >> n;
        rep(i, 1, n + 1) gr[i].clear();
        rep(i, 0, n- 1) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        par[0].clear();
        par[1].clear();
        dfs(1, 1);
        auto& s = par[0].size() < par[1].size() ? par[0] : par[1];
        
        clog << db(s) << endl;
        ++timer;
        auto it = s.begin();
        for (int bit = 0; (1 << bit) <= sz(s); ++bit) {
            if ((sz(s) >> bit) & 1) {
                rep(f, (1 << bit), (1 << bit) << 1) {
                    ans[*it++] = f;
                    used[f] = timer;
                }
            }
        }
        
        int cur = 1;
        for (auto i: (&s == &par[0] ? par[1] : par[0])) {
            while (used[cur] == timer) ++cur;
            used[cur] = timer;
            ans[i] = cur;
        }
        rep(i, 1, n + 1) cout << ans[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker