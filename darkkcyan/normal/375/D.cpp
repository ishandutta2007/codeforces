#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

struct Counter {
    vector<int> cnt, pos, sorted_val, beg;
    Counter() = default;
    Counter(int sz): cnt(sz), pos(sz), sorted_val(sz), beg(sz, sz) {
        iota(be(pos), 0);
        sorted_val = pos;
        beg[0] = 0;
    }
    
    void add(int val) {
        int last = sorted_val[beg[cnt[val] + 1] - 1];
        swap(sorted_val[pos[last]], sorted_val[pos[val]]);
        swap(pos[last], pos[val]);
        ++cnt[val];
        --beg[cnt[val]];
    }
    
    void rem(int val) {
        int first = sorted_val[beg[cnt[val]]];
        swap(sorted_val[pos[first]], sorted_val[pos[val]]);
        swap(pos[first], pos[val]);
        ++beg[cnt[val]];
        --cnt[val];
    }
    
    int count_leq(int k) {
        return len(pos) - beg[k];
    }
};

struct Query {
    int node, k;
    int ans;
};

const int maxn = 101010;
int n, q;
int color[maxn];
vector<int> gr[maxn];
Query qr[maxn];
vector<Query*> qr_of[maxn];

Counter counter(maxn);
int sub_cnt[maxn];
void dfs_sub(int u, int p) {
    sub_cnt[u] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs_sub(v, u);
        sub_cnt[u] += sub_cnt[v];
    }
}

template<bool delta> void dfs_add(int u, int p) {
    if constexpr (delta) counter.add(color[u]);
    else counter.rem(color[u]);
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs_add<delta>(v, u);
    }
}

void dfs(int u, int p, bool keep) {
    DB();
    clog << db(u) << db(p) << endl;
    sub_cnt[u] = 1;
    int big = -1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (big == -1 or sub_cnt[big] < sub_cnt[v]) big = v;
    }
    
    for (auto v: gr[u]) {
        if (v == p or v == big) continue;
        dfs(v, u, false);
    }
    
    if (big != -1) dfs(big, u, true);
    for (auto v: gr[u]) {
        if (v == p or v == big) continue;
        dfs_add<true>(v, u);
    }
    
    counter.add(color[u]);
    for (auto& cur_qr: qr_of[u]) {
        clog << db(cur_qr - qr) << endl;
        cur_qr->ans = counter.count_leq(cur_qr->k);
    }
    if (!keep) dfs_add<false>(u, p);
}

int get() {
    int ch;
    while (isspace(ch = getchar()));
    int ans = ch - '0';
    while (isdigit(ch = getchar())) ans = ans * 10 + ch - '0';
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cin >> n >> q; 
    n = get();
    q = get();
    
    rep1(i, n) {
        // cin >> color[i]; 
        color[i] = get();
    }
    rep(i, n - 1) {
        int u, v;
        // cin >> u >> v; 
        u = get();
        v = get();
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    rep(i, q) {
        // cin >> qr[i].node >> qr[i].k; 
        qr[i].node = get();
        qr[i].k = get();
        qr_of[qr[i].node].push_back(qr + i);
    }
    
    dfs_sub(1, 1);
    dfs(1, 1, true);
    
    rep(i, q) {
        cout << qr[i].ans << '\n';
    }
    
    
    return 0;
}

// vim: foldmethod=marker