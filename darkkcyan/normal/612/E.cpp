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
const int maxlg = 21;
int n;
int p[maxn];
int q[maxn];

int up[maxlg][maxn];
void cal_binlift() {
    copy_n(p, n + 2, up[0]);
    rep(lv, 1, maxlg) {
        rep(i, 1, n + 1) up[lv][i] = up[lv - 1][up[lv - 1][i]];
    }
}

int lift(int u, int d) {
    for (int i = 0; d > 0; d >>= 1, ++i)
        if (d & 1) u = up[i][u];
    return u;
}

bool vis[maxn];
int cache_chain[maxn];


void process_chain(int u) {
    if (vis[u]) return ;
    int chain_length = 0;
    do {
        vis[u] = 1;
        u = p[u];
        ++chain_length;
    } while (! vis[u]);
    
    if (chain_length % 2 == 0) {
        if (cache_chain[chain_length] == -1) {
            cache_chain[chain_length] = u;
            return ;
        }
        int v = cache_chain[chain_length];
        cache_chain[chain_length] = -1;
        while (chain_length--) {
            q[u] = v;
            q[v] = p[u];
            u = p[u];
            v = p[v];
        }
        return ;
    }
    
    int d = chain_length / 2 + 1;
    int r = u;
    do {
        q[u] = lift(u, d);
        u = p[u];
    } while (u != r);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> p[i];
    cal_binlift();
    clog << db(vector<int>(up[0], up[0] + n + 1)) << endl;
    
    fill_n(cache_chain, n + 1, -1);
    rep(i, 1, n + 1) process_chain(i);
    clog << db(vector<int>(q + 1, q + n + 1)) << endl;
    if (find(q + 1, q + n + 1, 0) != q + n + 1) {
        cout << "-1\n";
        return 0;
    }
    
    rep(i, 1, n + 1) cout << q[i] << ' ';
    
    return 0;
}

// vim: foldmethod=marker