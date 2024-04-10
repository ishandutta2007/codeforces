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

const int maxn = 101010;
const int bs = 350;
const int maxlogn = 20;
int n;
int gen[maxn];
int fav[maxn];

vector<int> gr[maxn];

vector<int> euler_tour;
int eu_start[maxn], eu_end[maxn];
int depth[maxn], up[maxlogn][maxn];
void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    up[0][u] = p;
    rep(i, 1, maxlogn) up[i][u] = up[i - 1][up[i - 1][u]];
    eu_start[u] = sz(euler_tour);
    euler_tour.push_back(u);
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    eu_end[u] = sz(euler_tour);
    euler_tour.push_back(u);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int d = depth[u] - depth[v], i = 0; d > 0; d >>= 1, ++i)
        if (d & 1) u = up[i][u];
    if (u == v) return u;
    for (int i = maxlogn; i--; ) {
        if (up[i][u] == up[i][v]) continue;
        u = up[i][u];
        v = up[i][v];
    }
    return up[0][u];
}

bool in_path[maxn];
int cnt[maxn][2];

ll cur_ans = 0;
void add_fav(int g, int num) {
    cur_ans += cnt[num][!g];
    cnt[num][g] ++;
}
void rem_fav(int g, int num) {
    cnt[num][g] --;
    cur_ans -= cnt[num][!g];
}
void toggle(int u) {
    in_path[u] = !in_path[u];
    if (in_path[u]) add_fav(gen[u], fav[u]);
    else rem_fav(gen[u], fav[u]);
    clog << db(u) << db(cur_ans) << endl;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    rep(i, 1, n + 1) cin >> gen[i];
    rep(i, 1, n + 1) cin >> fav[i];
    
    vector<int> fv(fav + 1, fav + n + 1);
    sort(all(fv));
    fv.erase(unique(all(fv)), fv.end());
    rep(i, 1, n + 1) {
        fav[i] = (int)(lower_bound(all(fv), fav[i]) - fv.begin());
    }
    
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    dfs(1, 1);
    clog << db(euler_tour) << endl;
    int q; cin >> q;
    struct Query {
        int a, b, left, right, id;
        Query() {}
        Query(int a_, int b_, int id_): a(a_), b(b_), id(id_) {
            if (a == b) {
                left = right = 0;
                return; 
            }
            if (eu_start[a] > eu_start[b]) swap(a, b);
            if (eu_end[a] > eu_end[b]) {
                left = eu_start[a];
            } else {
                left = eu_end[a];
            }
            right = eu_start[b] + 1;
        }
    };
    
    vector<Query> qr(q);
    rep(i, 0, q) {
        int u, v;
        cin >> u >> v;
        qr[i] = Query(u, v, i);
    }
    
    sort(all(qr), [&](const Query& u, const Query& v) {
            int blu = u.left / bs;
            int blv = v.left / bs;
            if (blu != blv) return blu < blv;
            if (blu & 1) return u.right > v.right;
            return u.right < v.right;
            });
    
    int l = 0, r = 0;
    vector<ll> ans(q);
    for (auto cur_q: qr) {
        DB();
        clog << db(cur_q.left) << db(cur_q.right) << db(cur_q.id) << endl;
        if (cur_q.a == cur_q.b) continue;
        while (l > cur_q.left) toggle(euler_tour[--l]);
        while (r < cur_q.right) toggle(euler_tour[r++]);
        while (l < cur_q.left) toggle(euler_tour[l++]);
        while (r > cur_q.right) toggle(euler_tour[--r]);
        
        if (eu_end[cur_q.a] < eu_end[cur_q.b]) {
            int cur_lca = lca(cur_q.a, cur_q.b);
            toggle(cur_lca);
            ans[cur_q.id] = cur_ans;
            toggle(cur_lca);
        } else {
            ans[cur_q.id] = cur_ans;
        }
    }
    rep(i, 0, q) cout << ans[i] << '\n';
    
    return 0;
}

// vim: foldmethod=marker