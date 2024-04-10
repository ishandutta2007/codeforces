#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> color;

bool TryColor(int v, int c) {
    color[v] = c;
    for (int u : g[v]) {
        int nc = 1 - c;

        if (color[u] == -1) {
            if (!TryColor(u, nc)) {
                return false;
            }
        } else {
            if (color[u] != nc) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    color.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!TryColor(i, 0)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> a[2];
    for (int i = 0; i < n; ++i) {
        a[color[i]].push_back(i);
    }
    for (int i = 0; i < 2; ++i) {
        cout << a[i].size() << endl;
        for (int j : a[i]) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}