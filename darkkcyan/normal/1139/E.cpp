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

const int maxn = 5050;
vector<int> gr[maxn];
int match[maxn];
int used[maxn], timer;

bool dfs(int u) {
    if (used[u] == timer) return false;
    DB();
    clog << db(u) << endl;
    used[u] = timer;
    for (auto v: gr[u]) {
        clog << db(v) << db(match[v]) << endl;
        if (match[v] == -1 or dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int n, m, d;
int p[maxn], c[maxn];
bool rem[maxn];
vector<int> rem_list;
int ans[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) cin >> p[i];
    rep(i, n) {
        cin >> c[i];
        --c[i];
    }
    
    cin >> d;
    rem_list.resize(d);
    rep(i, d) {
        cin >> rem_list[i];
        --rem_list[i];
        rem[rem_list[i]] = true;
    }
    
    rep(i, n) {
        if (rem[i]) continue;
        gr[p[i]].push_back(c[i]);
    }
    
    memset(match, -1, sizeof(match));
    
    int cur_ans = 0;
    auto inc_ans = [&] {
        while (1) {
            clog << db(cur_ans) << endl;
            ++timer;
            if (dfs(cur_ans)) ++cur_ans;
            else break;
        }
    };
    
    for (int i = d; i--; ) {
        DB();
        clog << db(i) << endl;
        inc_ans();
        ans[i] = cur_ans;
        gr[p[rem_list[i]]].push_back(c[rem_list[i]]);
    }
    
    rep(i, d) cout << ans[i] << '\n';
    
    return 0;
}

// vim: foldmethod=marker