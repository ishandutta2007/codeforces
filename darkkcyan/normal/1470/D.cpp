#ifdef LOCAL
#define testing  
#endif
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int maxn = 301010;
int n, m;
vector<int> gr[maxn];
void read() {
    cin >> n >> m;
    rep1(i, n) gr[i].clear();
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

struct DSU {
    vector<int> dsu;
    DSU(int sz) : dsu(sz, -1) {}
    
    int find_set (int u) {
        return dsu[u] < 0 ? u : dsu[u] = find_set(dsu[u]);
    }
    
    void join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return ;
        if (-dsu[u] < -dsu[v]) swap(u, v);
        dsu[u] += dsu[v];
        dsu[v] = u;
    }
    
    int count_comp(int u) {
        return -dsu[find_set(u)];
    }
};

bool check(const vector<int>& picked) {
    vector<bool> mark(n + 1);
    DSU dsu(n + 1);
    
    for (auto u: picked) {
        if (mark[u]) {
            // clog << db(u) << endl; 
            return false;
        }
        mark[u] = true;
        for (auto v: gr[u]) {
            mark[v] = true;
            dsu.join(u, v);
        }
    }
    
    // clog << db(dsu.count_comp(1)) << endl; 
    return dsu.count_comp(1) == n;
}

optional<vector<int>> brute() {
    rep(mask, (1 << n)) {
        vector<int> picked;
        rep(i, n) {
            if ((mask >> i) & 1) picked.push_back(i + 1);
        }
        if (check(picked)) return {picked};
    }
    return {};
}

void print_ans(const optional<vector<int>>& ans) {
    if (!ans) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    cout << ans->size() << '\n';
    for (auto u: *ans) cout << u << ' ';
    cout << '\n';
}

optional<vector<int>> solve() {  
    vector<int> state(n + 1, -1);
    int cnt_vis = 0;
    queue<int> qu;
    state[1] = 0;
    for (qu.push(1); qu.size(); qu.pop()) {
        int u = qu.front();
        ++cnt_vis;
        for (auto v: gr[u]) {
            if (state[v] != -1) {
                if (state[u] == 0) state[v] = 1;
                continue;
            }
            state[v] = 1 - state[u];
            qu.push(v);
        }
    }
    if (cnt_vis != n) return {};
    
    vector<bool> mark(n + 1);
    vector<int> ans;
    rep1(u, n) {
        if (state[u]) continue;
        clog << u << endl;
        bool ok = true;
        for (auto v: gr[u]) {
            if (!mark[v]) continue;
            ok = false;
            break;
        }
        if (!ok) continue;
        mark[u] = true;
        ans.push_back(u);
    }
    return {ans};
}  

void gen() {
    n = rand() % 10 + 2;
    m = rand() % 10 + 1;
    rep1(i, n) gr[i].clear();
    ofstream inp("main.inp");
    inp << 1 << endl;
    inp << n << ' ' << m << '\n';
    rep(i, n) {
        int u = rand() % n + 1;
        int v = u;
        while (u == v) {
            v = rand() % n + 1;
        }
        
        gr[u].push_back(v);
        gr[v].push_back(u);
        inp << u << ' ' << v << '\n';
    }
}

int main(void) {
#ifdef testing
    while (true) { 
        gen(); 
        auto exp = brute(); 
        auto ans =  solve();
        if (!!exp != !!ans) {
            cout << "FAILED diff" << endl;
            return 0;
        }
        if (ans and !check(*ans)) {
            cout << "FAILED" << endl;
            return 0;
        }
        cout << "OK" << endl;
    } 
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        read();
        // auto ans = brute();  
        auto ans = solve(); 
        print_ans(ans);
        // assert(check(*ans));  
    }
    
    return 0;
}

// vim: foldmethod=marker