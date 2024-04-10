#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
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

const int maxn = 101010;
int n, m, k;
vector<int> gr[maxn];

void read() {
    cin >> n >> m >> k;
    rep1(i, n) gr[i].clear();
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}

enum AnsState {
    NO_ANS = -1, HAS_CLIQUE = 2, HAS_SET = 1
};
pair<AnsState, vector<int>> solve() {
    if (k > 500) return {NO_ANS, {}};
    vector<int> deg(n + 1);
    vector<bool> removed(n + 1);
    rep1(i, n) deg[i] = len(gr[i]);
    vector<vector<int>> maybe_clique;
    
    set<pair<int, int>> prio;
    rep1(i, n) prio.insert({deg[i], i});
    clog << db(prio) << endl;
    while (len(prio)) {
        int u = prio.begin()->second;
        clog << db(u) << db(deg[u]) << endl;
        if (deg[u] >= k) {
            vector<int> ans;
            for (auto [d, v]: prio) ans.push_back(v);
            return {HAS_SET, ans};
        }
        prio.erase(prio.begin());
        if (deg[u] == k - 1) { 
            vector<int> need_check = {u};
            for (auto v: gr[u]) {
                if (!removed[v]) need_check.push_back(v);
            }
            maybe_clique.push_back(move(need_check));
        }
        removed[u] = true;
        for (auto v: gr[u]) {
            if (!removed[v]) {
                prio.erase({deg[v], v});
                deg[v]--;
                prio.emplace(deg[v], v);
            }
        }
    }
    vector<vector<int>> check_list(n + 1);
    rep(i, len(maybe_clique)) {
        for (auto u: maybe_clique[i])
            check_list[u].push_back(i);
    }
    
    vector<int> cnt(len(maybe_clique));
    for (auto& cl: maybe_clique) {
        clog << db(cl) << endl;
    }
    
    vector<bool> mark(n + 1);
    rep1(u, n) {
        for (auto v: gr[u]) mark[v]= true;
        mark[u] = true;
        for (auto i: check_list[u]) {
            bool ok = true;
            for (auto v: maybe_clique[i]) {
                if (!mark[v]) {
                    ok = false;
                    break;
                }
            }
            cnt[i] += ok;
        }
        
        for (auto v: gr[u]) mark[v]= false;
        mark[u] = false;
    }
    rep(i, len(maybe_clique)) {
        if (cnt[i] == k) return {HAS_CLIQUE, maybe_clique[i]};
    }

    return {NO_ANS, {}};
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        read();
        auto [as, ans] = solve();
        cout << as << ' ';
        if (as == HAS_SET) cout << len(ans);
        cout << '\n';
        if (as != NO_ANS) {
            for (auto i: ans) cout << i << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker