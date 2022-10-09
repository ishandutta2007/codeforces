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

const int maxn = 201010;
int n, m;
vector<pair<int, int>> gr[maxn], rgr[maxn];

int comb_id[maxn];
int state[maxn];

vector<int> topo;
void dfs1(int u) {
    state[u] = 1;
    for (auto [v, c]: rgr[u]) {
        if (state[v] == 1) continue;
        dfs1(v);
    }
    topo.push_back(u);
}

ll depth[maxn];
ll comb_gcd[maxn];

void dfs2(int u, int comb) {
    DB();
    clog <<db(u) << db(depth[u]) << endl;
    comb_id[u] = comb;
    state[u] = 1;
    for (auto [v, c]: gr[u]) {
        if (comb_id[v] != -1 and comb_id[v] != comb) continue;
        if (state[v]) {
            ll cycle = abs(depth[u] - depth[v] + c);
            clog << db(comb) << db(cycle) << endl;
            comb_gcd[comb] = gcd(comb_gcd[comb], cycle);
            continue;
        }
        depth[v] = depth[u] + c;
        dfs2(v, comb);
    }
    state[u] = 2;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c;
        gr[u].emplace_back(v, c);
        rgr[v].emplace_back(u, c);
    }
    
    rep(i, 1, n + 1) {
        if (state[i] == 1) continue;
        dfs1(i);
    }
    memset(state, 0, sizeof(state));
    int cur_comb = 0;
    reverse(all(topo));
    memset(comb_id, -1, sizeof(comb_id));
    for (auto i: topo) {
        if (state[i]) continue;
        DB();
        clog << db(cur_comb) << endl;
        dfs2(i, cur_comb++);
    }
    
    int q; cin >> q;
    while (q--) {
        int v;
        ll s;
        ll t;
        cin >> v >> s >> t;
        
        if (s % gcd(t, comb_gcd[comb_id[v]])) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    
    return 0;
}

// vim: foldmethod=marker