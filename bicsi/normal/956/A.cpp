#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<int> G[256], GT[256];
vector<int> rows, cols;

void DFS1(int node);

void DFS2(int node) {
    cols.push_back(node);
    auto go = GT[node];
    GT[node].clear();
    
    for (auto vec : go) {
        DFS1(vec);   
    }
}

void DFS1(int node) {
    rows.push_back(node);
    auto go = G[node];
    G[node].clear();

    for (auto vec : go) {
        DFS2(vec);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> mat(n);

    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == '#') {
                G[i].push_back(j);
                GT[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (G[i].size()) {
            DFS1(i);

            for (auto x : rows) {
                for (auto y : cols) {
                    if (mat[x][y] != '#') {
                        cout << "No\n";
                        return 0;
                    }    
                }
            }
            rows.clear();
            cols.clear();
        }
    }
    cout << "Yes\n";

    return 0;
}