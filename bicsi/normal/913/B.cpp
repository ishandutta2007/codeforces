#include <bits/stdc++.h>

using namespace std;

vector<int> G[5005];
bool ok = true;

void DFS(int node) {
    int leafs = 0;
    for (auto vec : G[node]) {
        if (G[vec].empty()) leafs += 1;
        else DFS(vec);
    }

    ok &= (leafs >= 3);
}

int main() {
    int n; cin >> n;
    vector<int> par(n);
    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        G[par[i] - 1].push_back(i);
    }

    DFS(0);
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}