#include <bits/stdc++.h>

using namespace std;

struct BCC {
    vector<pair<int, int>> edges;
    vector<vector<int>> G;
    vector<int> enter, stk, bias, ret;
    vector<map<int, int>> Q;

    BCC(int n) : G(n), enter(n, -1), bias(n, 0), Q(n) {}

    int AddEdge(int a, int b) {
        int ret = edges.size();
        edges.emplace_back(a, b);
        G[a].push_back(ret);
        G[b].push_back(ret);
        return ret;
    }

    void AddQuery(int a, int b, int i) {
        ret.push_back(0);
        if (a != b) {
            Q[a][i] = Q[b][i] = 0;
        }
    }

    void merge(int to, int from) {
        if (Q[to].size() < Q[from].size()) {
            swap(Q[to], Q[from]);
            swap(bias[to], bias[from]);
        }
        for (auto p : Q[from]) {
            auto it = Q[to].find(p.first);
            if (it != Q[to].end()) {
                ret[p.first] = p.second + it->second + bias[to] + bias[from];
                Q[to].erase(it);
            } else {
                Q[to][p.first] = bias[from] - bias[to] + p.second; 
            }
        }
    }

    template<typename Iter>
    void Callback(Iter bg, Iter en, int low) {
        set<int> nodes;
        for (auto it = bg; it != en; ++it) {
            nodes.insert(edges[*it].first);
            nodes.insert(edges[*it].second);    
        }
        assert(nodes.erase(low));
        if (nodes.size() == 1) {
            bias[*nodes.begin()] += 1;
        }
        for (auto node : nodes) {
            merge(low, node);
        }
    }

    vector<int> Solve() {
        for (int i = 0; i < (int)G.size(); ++i) {
            if (enter[i] == -1) {
                dfs(i, -1);
            }
        }
        return ret;
    }

    int timer = 0;
    int dfs(int node, int pei) {
        enter[node] = timer++;
        int ret = enter[node];

        for (auto ei : G[node]) if (ei != pei) {
            int vec = (edges[ei].first ^ edges[ei].second ^ node);
            if (enter[vec] != -1) {
                ret = min(ret, enter[vec]);
                if (enter[vec] < enter[node])
                    stk.push_back(ei);
            } else {
                int sz = stk.size(), low = dfs(vec, ei);
                ret = min(ret, low);
                stk.push_back(ei);
                if (low >= enter[node]) {
                    Callback(stk.begin() + sz, stk.end(), node);
                    stk.resize(sz);
                }
            }
        }
        return ret;
    }
};

int main() {
    int n, m; cin >> n >> m;
    BCC bcc(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        bcc.AddEdge(a - 1, b - 1);
    }
    int q; cin >> q; 
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        bcc.AddQuery(a - 1, b - 1, i);
    }

    for (auto x : bcc.Solve()) 
        cout << x << '\n';

    return 0;
}