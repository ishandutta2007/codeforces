#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> g;
vector<int> color;
vector<int> used;

bool Dfs(int v, int c) {
    used[v] = true;
    color[v] = c;
    for (int u : g[v]) {
        if (!used[u]) {
            if (!Dfs(u, 1 - c)) {
                return false;
            }
        } else {
            if (color[v] == color[u]) {
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
    vector<vector<int>> gi(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        gi[v1][v2] = gi[v2][v1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && !gi[i][j]) {
                g[i].push_back(j);
            }
        }
    }

    vector<bool> isB(n, false);
    for (int i = 0; i < n; ++i) {
        isB[i] = (g[i].size() == 0);
    }

    used.assign(n, false);
    color.resize(n);
    for (int i = 0; i < n; ++i) {
        if (isB[i]) {
            continue;
        }
        if (!Dfs(i, 0)) {
            cout << "No" << endl;
            return 0;
        }
        break;
    }

    for (int i = 0; i < n; ++i) {
        if (!isB[i] && !used[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (isB[i]) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (isB[j] || i == j || !gi[i][j]) {
                continue;
            }
            if (color[i] != color[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    string result;
    result.resize(n);
    for (int i = 0; i < n; ++i) {
        if (isB[i]) {
            result[i] = 'b';
        } else {
            if (color[i] == 0) {
                result[i] = 'a';
            } else {
                result[i] = 'c';
            }
        }
    }
    cout << result << endl;

    return 0;
}