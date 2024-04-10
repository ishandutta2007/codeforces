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

const int maxn = 201010;
int n;
int a[maxn];
vector<int> gr[maxn];

map<int, int> cnt, cnt_same, last_same;
int bad_branch[maxn];

bool up_good[maxn], down_good[maxn];

void dfs1(int u, int p) {
    DB(u);
    int pref_cnt = cnt[a[u]]++;
    up_good[u] = true;
    bad_branch[u] = 0;
    for (auto v: gr[u]) {
        if (v == p) continue;
        int last_cnt = cnt[a[u]];
        dfs1(v, u);
        if (!up_good[v]) up_good[u] = false;
        if (last_cnt == cnt[a[u]]) continue;
        if (bad_branch[u] == -1) continue;
        clog << db(v) << db(bad_branch[u]) << endl;
        if (bad_branch[u] == 0) bad_branch[u] = v;
        else bad_branch[u] = -1;
    }
    cnt_same[u] = cnt[a[u]] - pref_cnt;
    if (cnt_same[u] != 1) up_good[u] = false;
}

void dfs2(int u, int p) {
    DB(u);
    if (up_good[u] and cnt[a[u]] == 1) {
        down_good[u] = true;
        clog << db(u) << endl;
    }
    clog << db(cnt_same[u]) << db(bad_branch[u]) << endl;
    if (cnt_same[u] != cnt[a[u]]) return ;
    if (bad_branch[u] == -1) return ;
    
    int bad = bad_branch[u] > 0 ? bad_branch[u] : -1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        if (up_good[v]) continue;
        if (bad != -1 and bad != v) return ;
        bad = v;
    }
    clog << db(bad) << endl;
    if (bad != -1) {
        dfs2(bad, u);
        return ;
    }
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

int solve() {
    memset(up_good, 0, sizeof(up_good));
    memset(down_good, 0, sizeof(down_good));
    cnt.clear();
    cnt_same.clear();
    dfs1(1, 1);
    dfs2(1, 1);
    return (int)count(down_good, down_good + 1 + n, 1);
}

int brute() {
    set<int> has;
    int ans = 0;
    function<bool (int, int)> dfs = [&](int u, int p) -> bool {
        DB(u);
        if (u == 5) {
            clog << db(u) << db(has) << endl;
        }
        if (has.count(a[u])) return false;
        has.insert(a[u]);
        for (auto v: gr[u]) {
            if (v == p) continue;
            if (!dfs(v, u)) return false;
        }
        has.erase(a[u]);
        return true;
    };
    
    rep1(i, n) {
        has.clear();
        if (dfs(i, i)) {
            clog << db(i) << endl;
            ++ans;
        }
    }
    return ans;
}

int main(void) {
#ifdef testing
    while (true) {
        n = rand() % 5 + 1;
        rep1(i, n) gr[i].clear();
        vector<int> par(n);
        rep(i, n) par[i] = i + 1;
        shuffle(par.begin(), par.end(), rng);
        ofstream inp("main.inp");
        inp << n << '\n';
        rep1(i, n) {
            a[i] = rand() % 20 + 1;
            inp << a[i] << ' ';
        }
        inp << '\n';
        rep1(i, n - 1) {
            int p = par[rand() % i];
            inp << p << ' ' << par[i] << '\n';
            gr[p].push_back(par[i]);
            gr[par[i]].push_back(p);
        }
        
        auto ans = solve();
        auto exp = brute();
        if (ans == exp) {
            cout << "nice" << endl;
            continue;
        }
        cout << "failed" << endl;
        inp << ans << endl << exp << endl;
        return 0;
    }
#endif
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) {
        cin >> a[i];
    }
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    cout << solve() << endl; 
    // cout << brute() << endl; 
    
    
    return 0;
}

// vim: foldmethod=marker