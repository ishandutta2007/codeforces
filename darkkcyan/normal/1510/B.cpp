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

using vi = vector<int>;
const int inf = INT_MAX / 100;
const int magic_small_prio_lim = 30;  // not magic tho, because the max path is only like 10 or 11 (d or d + 1)

template<class T>
struct SmallPrioQueue {
    vector<vector<T>> qu;
    int ptr;
    SmallPrioQueue(int lim): qu(lim), ptr(0) {}
    SmallPrioQueue(): SmallPrioQueue(magic_small_prio_lim) {}
    void push(int cost, const T& val) {
        ptr= min(ptr, cost);
        qu[cost].push_back(val);
    }
    int inc() {
        while (ptr < sz(qu) and qu[ptr].empty()) ++ptr;
        if (ptr == sz(qu)) return -1;
        return ptr;
    }
    pair<int, T> pop() {
        if (inc() == -1) return {-1, T()};
        auto ans = qu[ptr].back();
        qu[ptr].pop_back();
        return {ptr, ans};
    }
};

struct MCMF {
    int n;
    vector<vi> cap, flow, cost;
    vector<vi> gr;
    MCMF(int n_)
    : n(n_), cap(n, vi(n)), flow(cap), cost(cap), gr(n) { }
    
    void add_edge(int u, int v, int ecap, int ecost) {
        clog << "add edge" << db(u) << db(v) << db(ecap) << db(ecost) << endl;
        gr[u].push_back(v);
        gr[v].push_back(u);
        cap[u][v] = ecap;
        cost[u][v] = ecost;
        cost[v][u] = -ecost;
    }
        
    vector<int> par;
    vector<int> dist;
    vector<bool> vis;
    bool path(int s, int t) {
        DB(); clog << "path" << endl;
        par.assign(n, -1);
        dist.assign(n, inf);
        vis.assign(n, false);
        par[s] = s;
        dist[s] = 0;
        SmallPrioQueue<int> prio;
        prio.push(0, s);
        while (prio.inc() != -1) {
            auto [d, u] = prio.pop();
            if (dist[u] < d) continue;
            clog << db(u) << db(d) << db(par[u]) << endl;
            vis[u] = true;
            if (u == t) break;
            for (auto v: gr[u]) {
                if (vis[v]) continue;
                if (cap[u][v] == flow[u][v]) continue;
                int nd = dist[u] + cost[u][v];
                if (nd >= dist[v]) continue;
                clog << "add " << db(v) << db(nd) << endl;
                par[v] = u;
                dist[v] = nd;
                prio.push(nd, v);
            }
        }
        return par[t] != -1;
    }
    
    int inc_flow(int s, int t, int lim = inf) {
        DB(); clog << "inc flow" << endl;
        clog << db(s) << db(t) << db(lim) << endl;
        int flow_inc = 0;
        while (lim and path(s, t)) {
            DB(); clog << "flow " << endl;
            int cur_flow = lim;
            for (int u = t; u != s; u = par[u])
                cur_flow = min(cur_flow, cap[par[u]][u] - flow[par[u]][u]);
            clog << db(cur_flow) << endl;
            for (int u = t; u != s; u = par[u]) {
                clog << db(u) << db(par[u]) << db(cap[par[u]][u]) << db(flow[par[u]][u])<< endl;
                flow[par[u]][u] += cur_flow;
                flow[u][par[u]] -= cur_flow;
            }
            lim -= cur_flow;
            flow_inc += cur_flow;
        }
        return flow_inc;
    }
    
    int get_cost() { 
        int ans = 0;
        rep(i, 0, n) rep(f, 0, n) {
            if (cost[i][f] > 0) {
                ans += flow[i][f] * cost[i][f];
                if (flow[i][f]) clog << db(i) << db(f) << db(flow[i][f]) <<endl;
            }
        }
        return ans;
    } 
};

int d, n;
vector<int> term;
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d >> n;
    term.resize(n);
    for(auto& i: term) {
        string s; cin >> s;
        i = 0;
        rep(bit, 0, d) i |= (s[bit] == '1') << bit;
    }
    term.push_back(0);
    sort(all(term), [&](int u, int v) { return __builtin_popcount(u) < __builtin_popcount(v); });
    
    ++n;
    MCMF mcmf(2 * n + 1);
    int sink = 2 * n;
    
    rep(i, 0, n) rep(f, 0, i) {
        if ((term[i] & term[f]) == term[f]) {
            mcmf.add_edge(2 * i, 2 * f + 1, 1, __builtin_popcount(term[i] ^ term[f]));
        }
    }
    
    mcmf.add_edge(1, sink, n, 1);  // cost == 1 for reset
    rep(i, 1, n) mcmf.add_edge(2 * i + 1, sink, 1, 0);
    
    rep(i, 1, n) {
        int inced = mcmf.inc_flow(2 * i, sink, 1);
        clog << db(i) << db(inced) << db(mcmf.get_cost()) << endl;
    }
    
    vector<int> path;
    function<bool(int)> dfs = [&](int u) {
        if (u == 0) {
            path.push_back(0);
            return true;
        }
        for (auto virtual_v: mcmf.gr[2 * u]) {
            int v = virtual_v / 2;
            if (v == n or mcmf.flow[2 * u][virtual_v] == 0) continue;
            if (dfs(v)) {
                path.push_back(u);
                mcmf.flow[2 * u][virtual_v] --;
                return true;
            }
        }
        return false;
    };
    
    vector<int> ans;
    for (int i = n; i-- > 1; ) {
        path.clear();
        if (!dfs(i)) continue;
        if (sz(ans)) ans.push_back(-1);
        int prev = 0;
        for (auto f: path) {
            int u = term[f];
            int diff = prev ^ u;
            prev ^= diff;
            rep(bit, 0, d)
                if ((diff >> bit) & 1) ans.push_back(bit);
        }
    }
    cout << sz(ans) << '\n';
    for (auto i: ans) {
        if (i == -1) cout << "R ";
        else cout << i << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker