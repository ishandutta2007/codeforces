#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
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

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

const int maxn = 2010;
const ll inf = (ll)1e17;
int n, m;
ll w;
int a[maxn * maxn];

struct Cell {
    int r, c;
    operator int() {
        return r * m + c;
    }
    
    bool inside() const {
        return r >= 0 and r < n and c >= 0 and c < m;
    }
};

vector<ll> bfs(Cell src) {
    vector<ll> dst(n * m, inf);
    dst[src] = 0;
    queue<Cell> qu;
    for (qu.push(src); sz(qu); qu.pop()) {
        auto u = qu.front();
        rep(dir, 0, 4) {
            Cell v{u.r + dr[dir], u.c + dc[dir]};
            if (!v.inside()) continue;
            if (a[v] == -1) continue;
            if (dst[v] != inf) continue;
            dst[v] = dst[u] + w;
            qu.push(v);
        }
    }
    return dst;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> w;
    rep(i, 0, n) rep(f, 0, m) cin >> a[Cell{i, f}];
    
    auto du = bfs({0, 0});
    auto dv = bfs({n - 1, m - 1});
    ll ans = dv[Cell{0, 0}];
    ll min_du = inf, min_dv = inf;
    rep(i, 0, n) rep(f, 0, m) {
        auto u = Cell{i, f};
        auto cur = a[u];
        if (cur <= 0) continue;
        min_du = min(min_du, cur + du[u]);
        min_dv = min(min_dv, cur + dv[u]);
    }
    
    ans = min(ans, min_du + min_dv);
    if (ans >= inf) cout << "-1";
    else cout << ans;
    
    return 0;
}

// vim: foldmethod=marker