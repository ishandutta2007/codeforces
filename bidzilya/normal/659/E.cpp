#include <iostream>
#include <vector>
using namespace std;

bool Dfs(int v, int pr, const vector<vector<int>>& g, vector<bool>& used) {
    used[v] = true;
    bool result = false;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        if (used[u]) {
            result = true;
        } else {
            if (Dfs(u, v, g, used)) {
                result = true;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int result = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (!Dfs(i, -1, g, used)) {
                ++result;
            }
        }
    }
    cout << result << endl;

    return 0;
}