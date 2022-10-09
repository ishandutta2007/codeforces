#include <bits/stdc++.h>
using namespace std;


#define jalsol_orz main   // I did this for a meme :D


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

const int maxn = 201010;
int n, m, k;
vector<pair<int, int>> gr[maxn];

int dist[maxn];
void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    queue<int> qu;
    dist[s] = 0;
    for (qu.push(s); qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto [v, eid]: gr[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            qu.push(v);
        }
    }
}

vector<string> ans;
void print_ans() {
    cout << sz(ans) << '\n';
    for (auto& s: ans) {
        cout << s << '\n';
    }
}
string cur_ans;
void backtrack(int node) {
    if (node > n) {
        ans.push_back(cur_ans);
        if (sz(ans) == k) {
            print_ans();
            exit(0);
        }
        return ;
    }
    for (auto [v, eid]: gr[node]) {
        if (dist[v] + 1 == dist[node]) {
            cur_ans[eid] = '1';
            backtrack(node + 1);
            cur_ans[eid] = '0';
        }
    }
}

int jalsol_orz() {
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
        gr[u].emplace_back(v, i);
        gr[v].emplace_back(u, i);
    }
    bfs(1);
    cur_ans.assign(m, '0');
    backtrack(2);
    print_ans();
    
    return 0;
}

// vim: foldmethod=marker