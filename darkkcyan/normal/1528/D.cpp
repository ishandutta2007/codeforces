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

const int maxn = 666;
const ll inf = (ll)1e16;
int n, m;
struct mod_int {
    int x;
    void normalize() {
        if (x < 0) x += n;
        if (x >= n) x -= n;
    }
    mod_int(int x_ = 0): x(x_ % n) {
        normalize();
    }
    mod_int(ll x_) : x((int)(x_ % n)) {
        normalize();
    }
    
#define op(p) friend mod_int operator p (mod_int u, mod_int v)
    op(+) {
        u.x += v.x;
        if (u.x >= n) u.x -= n;
        return u;
    }
    
    op(-) {
        u.x -= v.x;
        if (u.x < 0) u.x += n;
        return u;
    }
    
    friend bool operator !=(mod_int u, mod_int v) {
        return u.x != v.x;
    }
};

struct Canon {
    mod_int init;
    ll cost;
    
    friend bool operator<(const Canon& u, const Canon& v) {
        if (u.cost == v.cost) return u.init.x < v.init.x;
        return u.cost < v.cost;
    }
    
    ll cal_cost(mod_int dest, ll init_rot) const {
        mod_int cur_rot = init_rot + init;
        auto rot = dest - cur_rot;
        return init_rot + (ll)rot.x + cost;
    }
    
    friend ostream& operator<<(ostream& out, const Canon& u) {
        return out << "(" << u.init.x << ", " << u.cost << ")";
    }
};

vector<Canon> gr[maxn];
ll cal_cost[maxn][maxn];

void precal() {
    rep(src, 0, n) {
        DB();
        clog << db(src) << endl;
        auto& canons = gr[src];
        sort(all(canons), [&](const auto& u, const auto& v) {
                return u.init.x < v.init.x;
                });
        rotate(canons.begin(), min_element(all(canons)), canons.end());
        int last = 0;
        rep(i, 1, sz(canons)) {
            auto cur_cost = canons[i].cal_cost(canons[i].init, 0);
            auto prev_cost = canons[last].cal_cost(canons[i].init, 0);
            if (cur_cost > prev_cost) continue;
            canons[++last] = canons[i];
        }
        canons.resize(last + 1);
        clog << db(canons) << endl;
        auto prev = canons.back();
        for (auto& c: canons) {
            for (auto i = prev.init; ; ) {
                cal_cost[src][i.x] = prev.cal_cost(i, 0);
                i = i + 1;
                if (i.x == c.init.x) break;
            }
            prev = c;
        }
        clog << db(vector<ll>(cal_cost[src], cal_cost[src] + n)) << endl;
    }
}
ll ans[maxn];
bool vis[maxn];

void sssp(int s) {
    DB();
    clog << db(s) << endl;
    rep(i, 0, n) {
        ans[i] = inf;
        vis[i] = false;
    }
    ans[s] = 0;
    
    while (true) {
        int u = -1;
        rep(i, 0, n) {
            if (vis[i]) continue;
            if (u == -1 or ans[i] < ans[u]) u = i;
        }
        if (u == -1) break;
        DB();
        clog << db(u) << db(ans[u]) << endl;
        vis[u] = true;
        if (gr[u].empty()) continue;
        
        mod_int shift = ans[u];
        rep(v, 0, n) {
            if (vis[v]) continue;
            ans[v] = min(ans[v], ans[u] + cal_cost[u][(v - shift).x]);
            clog << db(v) << db(ans[v]) << endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        gr[a].push_back({b, c});
    }
    
    precal();
    
    rep(src, 0, n) {
        sssp(src);
        rep(i, 0, n) cout << ans[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker