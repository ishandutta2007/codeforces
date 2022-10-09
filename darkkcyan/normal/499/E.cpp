#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define db(x) "[" #x " = " << (x) << "] "

#define clog if (0) cout

const int maxn = 111;
const int max_val = (int)1e9;
const int inf = maxn * maxn;

struct MaxFlow {
    int n;
    vector<vector<int>> cap, flow;
    vector<vector<int>> gr;
    MaxFlow(int n_): n(n_), cap(n, vector<int>(n)), flow(cap), gr(n) {}
    
    void add_edge(int u, int v, int c) {
        cap[u][v] = c;
        gr[u].push_back(v);
        gr[v].push_back(u);
        clog << u << ' ' << v << ' ' << c << endl;
    }
    
    vector<int> dist, trace;
    int max_flow(int s, int t) {
        dist.resize(n);
        trace.resize(n);
        int ans = 0;
        while (bfs(s, t)) {
            clog << string(10, '-') << endl;
            int new_flow = INT_MAX;
            for (int u = t; u != s; u = trace[u])
                new_flow = min(new_flow, cap[trace[u]][u] - flow[trace[u]][u]);
            clog << db(new_flow) << endl;
            ans += new_flow;
            for (int u = t; u != s; u = trace[u]) {
                flow[trace[u]][u] += new_flow;
                flow[u][trace[u]] -= new_flow;
                clog << db(trace[u]) << db(u) << endl;
            }
        }
        return ans;
    }
    
    bool bfs(int s, int t) {
        trace.assign(n, -1);
        queue<int> qu;
        for (qu.push(s), trace[s] = s; qu.size(); qu.pop()) {
            int u = qu.front();
            clog << db(u) << endl;
            if (u == t) return true;
            for (auto v: gr[u]) {
                if (flow[u][v] == cap[u][v]) continue;
                if (trace[v] != -1) continue;
                clog << db(v) << db(flow[u][v]) << db(cap[u][v]) << db(trace[v]) << endl;
                trace[v] = u;
                qu.push(v);
            }
        }
        return false;
    }
};

vector<pair<int, int>> factorize(int num) {
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i) continue;
        auto& it = ans.emplace_back(i, 0);
        while (num % i == 0) {
            ++it.second;
            num /= i;
        }
    }
    if (num > 1) ans.emplace_back(num, 1);
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    
    struct Node {
        int pdiv, cnt, id;
    };
    vector<vector<Node>> inner_nodes;
    int node_id = 0;
    rep(i, 0, n) {
        auto& cur_nodes = inner_nodes.emplace_back();
        for (auto [pdiv, cnt]: factorize(a[i])) {
            cur_nodes.push_back({pdiv, cnt, node_id++});
        }
    }
    
    int s = node_id++;
    int t = node_id++;
    MaxFlow mf(node_id);
    
    rep(i, 0, n) {
        for (auto [pdiv, cnt, id]: inner_nodes[i]) {
            if (i & 1) mf.add_edge(id, t, cnt);
            else mf.add_edge(s, id, cnt);
        }
    }
    
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u & 1) swap(u, v);
        for (auto [pd1, c1, id1]: inner_nodes[u]) {
            for (auto [pd2, c2, id2]: inner_nodes[v]) {
                if (pd1 != pd2) continue;
                mf.add_edge(id1, id2, inf);
            }
        }
    }
    
    cout << mf.max_flow(s, t);
    
    return 0;
}