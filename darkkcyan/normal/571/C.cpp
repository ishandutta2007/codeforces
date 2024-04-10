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

const int maxn = 202020;

int n, m;
vector<int> in_clauses[maxn * 4];

vector<pair<int, int>> gr[maxn * 2];
bool ans[maxn];

int state[maxn];
int find_in_cycle(int u, int in_e = -1) {
    if (state[u] == 1) return u;
    if (state[u] == 2) return -1;
    state[u] = 1;
    for (auto [v, eid]: gr[u]) {
        if (eid / 2 == in_e) continue;
        int x = find_in_cycle(v, eid / 2);
        if (x == -1) continue;
        return x;
    }
    return -1;
}

int low[maxn], timer = 0;

void assign_edge(int u, int in_e = -1) {
    DB();
    low[u] = ++timer;
    clog << db(u) << db(in_e) << endl;
    state[u] = 3;
    for (auto [v, eid]: gr[u]) {
        if (eid / 2 == in_e) continue;
        if (low[v] > low[u]) continue;
        clog << db(v) << db(eid) << db(eid / 2) << db(!(eid & 1)) << endl;
        ans[eid / 2] = !(eid & 1);
        if (state[v] == 3) continue;
        assign_edge(v, eid / 2);
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 0, n) {
        int k;
        cin >> k;
        rep(f, 0, k) {
            int x;
            cin >> x;
            int val = abs(x) - 1;
            if (x < 0) {
                in_clauses[2 * val + 1].push_back(i);
            } else {
                in_clauses[2 * val].push_back(i);
            }
        }
    }
    
    int v1 = n;
    int v2 = n + 1;
    int v3 = n + 2;
    auto add_edge = [&](int u, int v, int eid) {
        clog << u << ' ' << v << ' ' << eid << endl;
        // clog << db(u) << db(v) << db(eid) << endl; 
        gr[u].emplace_back(v, eid);
        gr[v].emplace_back(u, eid ^ 1);
    };
    add_edge(v1, v2, 2 * m);
    add_edge(v2, v3, 2 * m + 2);
    add_edge(v3, v1, 2 * m + 4);
    
    int temp_var = m + 3;
    
    rep(i, 0, m) {
        assert(sz(in_clauses[2 * i]) + sz(in_clauses[2 * i + 1]) <= 2);
        if (sz(in_clauses[2 * i]) == 0 and sz(in_clauses[2 * i + 1]) == 0) continue;
        if (sz(in_clauses[2 * i]) == 0) {
            ans[i] = 0;
            for (auto cl: in_clauses[2 * i + 1]) {
                add_edge(v1, cl, 2 * (temp_var++));
            }
            continue;
        }
        if (sz(in_clauses[2 * i + 1]) == 0) {
            ans[i] = 1;
            for (auto cl: in_clauses[2 * i]) {
                add_edge(v1, cl, 2 * (temp_var++));
            }
            continue;
        }
        int u = in_clauses[2 * i][0];
        int v = in_clauses[2 * i + 1][0];
        add_edge(u, v, 2 * i + 1);
    }
    
    rep(i, 0, n + 3) {
        if (state[i] == 3) continue;
        int root = find_in_cycle(i);
        clog << db(i) << db(root) << endl;
        if (root == -1) {
            cout << "NO";
            return 0;
        }
        assign_edge(root);
    }
    cout << "YES\n";
    rep(i, 0, m) cout << ans[i];
    
    
    return 0;
}

// vim: foldmethod=marker