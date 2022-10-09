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

const int maxn = 1010100;

struct Node {
    int val, pos;
    Node(): val(INT_MIN), pos(-1) {}
    Node(int v, int p): val(v), pos(p) {}
    Node(const Node& u, const Node& v) {
        pos = INT_MAX;
        val = max(u.val, v.val);
        if (u.val == val) pos= u.pos;
        if (v.val == val) pos = min(pos, v.pos);
    }
};

int n;
vector<int> gr[maxn];

Node it[2 * maxn];
void build() {
    rep(i, 0, n) {
        it[i + n] = {0, i};
    }
    for (int i = n; i--; ) it[i] = Node(it[2 * i], it[2 * i + 1]);
}
void inc(int pos, int delta) {
    it[pos + n].val += delta;
    for (pos += n; pos > 0; pos >>= 1)
        it[pos >> 1] = Node(it[pos], it[pos ^ 1]);
}

Node get(int l, int r) {
    Node ans;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = Node(ans, it[l++]);
        if (r & 1) ans = Node(ans, it[--r]);
    }
    return ans;
}

int depth[maxn], cnt[maxn];
void dfs(int u, int p) {
    cnt[u] = 1;
    for (auto& v: gr[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

void inc(int u, int p, int delta) {
    inc(depth[u], delta);
    for (auto v: gr[u]) {
        if (v == p) continue;
        inc(v, u, delta);
    }
}

int ans[maxn];
void cal_ans(int u, int p) {
    int big = -1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (big == -1 or cnt[big] < cnt[v]) big = v;
    }
    for (auto v: gr[u]) {
        if (v == p or v == big) continue;
        cal_ans(v, u);
        inc(v, u, -1);
    }
    if (big != -1) cal_ans(big, u);
    inc(depth[u], 1);
    for (auto v: gr[u]) {
        if (v == big or v == p) continue;
        inc(v, u, 1);
    }
    ans[u] = get(0, n).pos - depth[u];
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n- 1) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    build();
    dfs(1, 1);
    cal_ans(1, 1);
    rep(i, 1, n + 1) cout << ans[i] << '\n';
    
    return 0;
}

// vim: foldmethod=marker