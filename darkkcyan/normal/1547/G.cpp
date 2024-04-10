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

const int maxn = 401010 * 2;
int n, m;
vector<int> gr[maxn], rgr[maxn];

int ans[maxn];
bool in_strong[maxn];

int low[maxn], num[maxn], timer;
bool in_stack[maxn];
vector<int> st, topo;
void dfs1(int u) {
    st.push_back(u);
    in_stack[u] = true;
    low[u] = num[u] = ++timer;
    for (auto v: gr[u]) {
        if (!num[v]) {
            dfs1(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(num[v], low[u]);
        }
    }
    
    clog << db(u) << db(low[u]) << db(num[u]) << endl;
    if (low[u] == num[u]) {
        vector<int> cur_comp;
        while (true) {
            int v = st.back();
            st.pop_back();
            cur_comp.push_back(v);
            in_stack[v] = false;
            if (v == u) break;
        }
        clog << db(cur_comp) << endl;
        if (sz(cur_comp) > 1) {
            for (auto x: cur_comp) in_strong[x] = true;
        }
    }
    topo.push_back(u);
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
        cin >> n >> m;
        rep(i, 1, 2 * n + 1) {
            gr[i].clear();
            rgr[i].clear();
            low[i] = num[i] = 0;
            in_strong[i] = 0;
            in_stack[i] = 0;
            ans[i] = 0;
        }
        timer = 0;
        st.clear();
        topo.clear();
        
        rep(i, 0, m) {
            int u, v; cin >> u >> v;
            if (u == v) {
                gr[u].push_back(u + n);
                gr[u + n].push_back(u);
                rgr[u].push_back(u + n);
                rgr[u + n].push_back(u);
            } else {
                gr[u].push_back(v);
                rgr[v].push_back(u);
            }
        }
        
        dfs1(1);
        topo.pop_back();
        reverse(all(topo));
        if (in_strong[1]) {
            ans[1] = -1;
        } else {
            ans[1] = 1;
        }
        for (auto u: topo) {
            if (in_strong[u]) {
                ans[u] = -1;
                continue;
            }
            ans[u] = 0;
            for (auto v: rgr[u]) {
                if (ans[v] == -1) {
                    ans[u] = -1;
                    break;
                }
                ans[u] += ans[v];
            }
            if (ans[u] > 1) ans[u] = 2;
        }
        rep(i, 1, n + 1) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker