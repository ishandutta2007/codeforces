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

const int maxn = 201010;
int n;
vector<int> gr[maxn];

int fib_id[maxn];
vector<int> fib;
void precal() {
    fib.push_back(1);
    fib.push_back(1);
    while (fib.back() < maxn) {
        fib.push_back(fib.back() + fib.end()[-2]);
    }
    memset(fib_id, -1, sizeof(fib_id));
    fib.pop_back();
    rep1(i, len(fib) - 1) fib_id[fib[i]] = i;
}

int cnt[maxn], par[maxn];
vector<int> comp;
void dfs(int u, int p) {
    par[u] = p;
    cnt[u] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    comp.push_back(u);
}


bool check(int root) {
    DB();
    clog << db(root) << endl;
    comp.clear();
    dfs(root, root);
    clog << db(comp) << endl;
    int cur_id = fib_id[len(comp)];
    if (cur_id == -1) return false;
    if (cur_id == 1 or cur_id == 2) return true;
    int cut = -1;
    for (auto v: comp) {
        if (fib_id[cnt[v]] != cur_id - 1 and fib_id[cnt[v]] != cur_id - 2) continue;
        cut = v;
        break;
    }
    clog << db(cut) << endl;
    
    if (cut == -1) return false;
    int p = par[cut];
    clog << db(p) << endl;
    gr[cut].erase(find(be(gr[cut]), p));
    gr[p].erase(find(be(gr[p]), cut));
    return check(p) and check(cut);
}

void print_ans(bool ans) {
    cout << (ans ? "YES" : "NO") << '\n';
}

int main(void) {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    print_ans(check(1));
    
    return 0;
}

// vim: foldmethod=marker