#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

enum BLOCK_TREE_TYPE { BLOCK_CUT_TREE = 0, BRIDGE_TREE = 1 };

template<BLOCK_TREE_TYPE tree_type,
    class Graph = vector<int>[], int node_start_id = 1>
    
vector<vector<int>> build_block_tree(int n, const Graph& gr) {
    n += node_start_id;
    vector<int> low(n), num(n, -1), stk;
    vector<vector<int>> bc_tree(n);
    
    auto new_edge = [&](int u, int v) {
        bc_tree[u].push_back(v);
        bc_tree[v].push_back(u);
    };
    
    auto new_component = [&](int last_node = -1) {
        int comp_id = (int)bc_tree.size();
        bc_tree.emplace_back();
        for (; stk.size() and (!bc_tree.back().size() or bc_tree.back().back() != last_node); stk.pop_back())
            new_edge(comp_id, stk.back());
        return comp_id;
    };
    
    int counter = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        low[u] = num[u] = counter++;
        stk.push_back(u);
        for (auto v: gr[u]) {
            if (v == p) continue;
            if (num[v] != -1) {
                low[u] = min(low[u], num[v]);
                continue;
            }
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] < num[u] + tree_type) continue;
            int comp_id = new_component(v);
            new_edge(u, tree_type == BLOCK_CUT_TREE ? comp_id : v);
        }
    };
    
    for (int i = node_start_id; i < n; ++i) {
        if (num[i] == -1) {
            dfs(i, -1);
            new_component();
        }
        // make the component id to be the first element. can be removed if not needed
        for (int& f: bc_tree[i]) if (f > n) {
            swap(bc_tree[i][0], f);
            break;
        }
        // modification: move all non-bridge/cut point to the end for faster iterating through adj component.
    }
    return bc_tree;
}

template<BLOCK_TREE_TYPE tree_type>
void foreach_adj_comp(const vector<vector<int>>& bc_tree, int comp, function<void(int, int, int)> fn) {
    try {
        for (int elm: bc_tree[comp]) if (bc_tree[elm].size() > 1)
            for (int oelm: bc_tree[elm]) {
                if (oelm == comp) continue;
                int adj_comp = tree_type == BRIDGE_TREE ? bc_tree[oelm][0] : oelm;
                fn(adj_comp, elm, oelm);
            }
    } catch (bool break_signal) {}
}

const int maxn = 300010 * 2;
int n, m, k;
bitset<maxn> is_special;
int profit[maxn];
int cost[maxn];
map<pair<int, int>, int> cost_map;
vector<int> gr[maxn];

vector<vector<int>> bc; 
llong ans[maxn];
int cnt_special[maxn];

llong total_profit[maxn];
int get_cost(int u, int v) {
    auto it = cost_map.find({u, v});
    if (it == cost_map.end()) return 0;
    return it->second;
}

void up_cal_special(int u, int p) {
    cnt_special[u] = is_special[u];
    for (auto v: bc[u]) {
        if (v == p) continue;
        up_cal_special(v, u);
        cnt_special[u] += cnt_special[v];
    }
}

int total_special;
bool par_connecting_special(int u) {
    return cnt_special[u] and cnt_special[u] != total_special;
}

void up_dfs(int u, int p) {
    total_profit[u] = profit[u];
    for (auto v: bc[u]) {
        if (v == p) continue;
        up_dfs(v, u);
        llong w = get_cost(u, v);
        
        if (par_connecting_special(v)) {
            total_profit[u] += max(total_profit[v] - w, 0ll);
        } else {
            total_profit[u] += total_profit[v];
        }
    }
    deb(u, total_profit[u], cnt_special[u]);
}

void down_dfs(int u, int p) {
    deb(u, p, bc[u]);
    for (auto v: bc[u]) {
        if (v == p) continue ;
        llong w = get_cost(u, v);
        
        llong dec_profit;
        if (par_connecting_special(v))
            dec_profit = max(total_profit[v] - w, 0ll);
        else
            dec_profit = total_profit[v];
            
        llong addiprofit = total_profit[u] - dec_profit;
        deb(u, v, addiprofit, w, dec_profit);
        
        if (par_connecting_special(v))
            total_profit[v] += max(addiprofit - w, 0ll);
        else total_profit[v] += addiprofit;
        
        down_dfs(v, u);
    }
    deb(u, total_profit[u]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    deb(n, m, k);
    rep(i, k) {
        int u; cin >> u;
        is_special[u] = true;
    }
    
    rep1(i, n) cin >> profit[i];
    rep1(i, m) cin >> cost[i];
    
    rep1(i, m) {
        int u, v; cin >> u >> v;
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
        cost_map[{u, v}] = cost[i];
        cost_map[{v, u}] = cost[i];
    }
    
    bc = build_block_tree<BRIDGE_TREE>(n, gr);
    deb(bc);
    int root = n + 1;
    
    up_cal_special(root, root);
    total_special = cnt_special[root];
    up_dfs(root, root);
    down_dfs(root, root);
    
    rep1(i, n) {
        cout << total_profit[i] << ' ';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker