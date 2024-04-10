#include <bits/stdc++.h>
using namespace std;
 
// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i) 
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

const int maxn = 101010;
const ll inf = (ll)1e15;
int n, k;
vector<pair<int, ll>> gr[maxn];

struct bfs {
    vector<ll> dist;
    vector<int> trace;
    bfs(const vector<int>& start): dist(n + 1, -1), trace(n + 1, -1) {
        queue<int> qu;
        for (auto u: start) {
            dist[u] = 0;
            qu.emplace(u);
        }
        while (qu.size()) {
            auto u = qu.front();
            qu.pop();
            for (auto [v, c]: gr[u]) {
                if (dist[v] != -1) continue;
                auto new_d = c + dist[u];
                qu.emplace(v);
                trace[v] = u;
                dist[v] = new_d;
            }
        }
    }
    
    bfs(int start): bfs(vector{start}) {}
    
    int get_furthest() const {
        return (int)(ranges::max_element(dist) - dist.begin());
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        gr[u].emplace_back(v, c);
        gr[v].emplace_back(u, c);
    }
    
    auto dia1 = bfs(1).get_furthest();
    bfs b2(dia1);
    auto dist1 = b2.dist;
    auto dia2 = b2.get_furthest();
    auto trace1 = b2.trace;
    auto dist2 = bfs(dia2).dist;
    
    vector<bool> on_diag(n + 1);
    vector<int> diag;
    for (int u = dia2; u != -1; u = trace1[u]) {
        on_diag[u] = true;
        diag.push_back(u);
    }
    
    clog << db(diag) << endl;
    
    auto ok = [&](ll d) -> bool {
        int s1 = dia1, s2 = dia2;
        for (auto u: diag) {
            if (dist1[u] <= d and dist1[u] > dist1[s1]) s1 = u;
            if (dist2[u] <= d and dist2[u] > dist2[s2]) s2 = u;
        }
        if (dist1[s1] > dist1[s2]) return true;
        vector<int> start;
        for (auto u: diag) {
            if (dist1[s1] <= dist1[u] and dist1[u] <= dist1[s2]) start.push_back(u);
        }
        clog << db(d) << db(start) << endl;
        if (sz(start) > k) return false;
        
        bfs b(start);
        auto f = b.get_furthest();
        return b.dist[f] <= d;
    };
    
    ll l = 0, r = 1;
    while (!ok(r)) l = exchange(r, r * 2);
    
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    
    return 0;
}