#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Construct(vector<int> d) {
        if (d.empty()) {
                vector<vector<int>> adj(1);
                return adj;
        }
        if ((int) d.size() == 1) {
                vector<vector<int>> adj(d[0] + 1);
                for (int i = 0; i <= d[0]; i++) {
                        for (int j = 0; j <= d[0]; j++) {
                                if (i != j) {
                                        adj[i].push_back(j);
                                }
                        }
                }
                return adj;
        }
        vector<int> d2;
        for (int i = 1; i < (int) d.size() - 1; i++) {
                d2.push_back(d[i] - d[0]);
        }
        vector<vector<int>> adj = Construct(d2);
        for (int j = 1; j <= d[(int) d.size() - 1] - d[(int) d.size() - 2]; j++) {
                adj.push_back({});
        }
        int init = (int) adj.size();
        for (int j = 1; j <= d[0]; j++) {
                adj.push_back({});
                int pos = (int) adj.size() - 1;
                for (int k = 0; k < init; k++) {
                        adj[k].push_back(pos);
                        adj[pos].push_back(k);
                }
        }
        int l = init, r = (int) adj.size() - 1;
        for (int j = l; j <= r; j++) {
                for (int k = j + 1; k <= r; k++) {
                        adj[j].push_back(k);
                        adj[k].push_back(j);
                }
        }
        return adj;
}

int main() {
        int C;
        cin >> C;
        vector<int> d(C);
        for (int i = 0; i < C; i++) {
                cin >> d[i];
        }
        vector<vector<int>> adj = Construct(d);
        int E = 0;
        for (int i = 0; i < (int) adj.size(); i++) {
                E += (int) adj[i].size();
        }
        cout << E / 2 << "\n";
        for (int i = 0; i < (int) adj.size(); i++) {
                for (auto &j : adj[i]) {
                        if (i < j) {
                                cout << i + 1 << " " << j + 1 << "\n";
                        }
                }
        }
}