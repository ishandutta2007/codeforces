#include <bits/stdc++.h>

using namespace std;

struct EulerWalk {
    int n;
    vector<multiset<int>> G;
    vector<int> deg;

    EulerWalk(int n) : n(n), G(n + 1), deg(n + 1, 0) {}

    void AddEdge(int a, int b) {
        G[b].insert(a);
        deg[a] += 1; deg[b] -= 1;
        // G[a].insert(b);
    }

    vector<int> walk;
    void dfs(int node) {
        while (G[node].size()) {
            auto vec = *G[node].begin();
            G[node].erase(G[node].begin());
            // G[vec].erase(G[vec].find(node))
            dfs(vec);
        }
        walk.push_back(node);
    }

    template<typename Callback>
    void Solve(Callback cb) {
        for (int i = 1; i <= n; ++i) {
            while (deg[i] < 0) AddEdge(i, n);
            while (deg[i] > 0) AddEdge(n, i);
            // if (deg[i] % 2) AddEdge(i, n);
        }
        // Paths
        vector<int> buff; dfs(n);
        for (auto node : walk) {
            if (node < n) buff.push_back(node);
            else if (buff.size()) {
                cb(buff); buff.clear();
            }
        }
        // Cycles
        for (int i = 0; i < n; ++i) {
           walk.clear(); dfs(i);
           if (walk.size() > 1) cb(walk);
        }
    }
};

int main() {
    const int kSigma = 256;
    int n; cin >> n;
    EulerWalk euler(kSigma * kSigma);

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int a = s[0] * kSigma + s[1];
        int b = s[1] * kSigma + s[2];
        euler.AddEdge(a, b);
    }

    cerr << "DONE" << endl;

    int total = 0;
    string ans;
    euler.Solve([&](vector<int> path) {
        total += 1;
        ans += path[0] / kSigma;
        for (auto x : path) {
            assert(ans.back() == x / kSigma);
            ans += x % kSigma;
        } 
    });

    if (total != 1) {
        cout << "NO\n";
    } else {
        cout << "YES" << endl << ans << endl;
    }
    return 0;
}