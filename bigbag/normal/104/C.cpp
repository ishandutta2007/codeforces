#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int n, m, used[max_n], ff[max_n], fin, fff, qw;
vector<int> g[max_n], f[max_n], c;

bool dfs(int v, int p) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (f[v][i] == 1) {
            if (used[g[v][i]] == 0) {
                if (dfs(g[v][i], v)) {
                    if (fff) {
                        c.push_back(v);
                        if (v == fin) {
                            fff = 0;
                        }
                    }
                    return true;
                }
            } else if (g[v][i] != p && (used[g[v][i]] == 1 || (used[g[v][i]] == 2 && qw == 1))) {
                c.push_back(v);
                fin = g[v][i];
                fff = 1;
                return true;
            }
        }
    }
    used[v] = 2;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        f[u].push_back(1);
        g[v].push_back(u);
        f[v].push_back(1);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            if (dfs(i, -1)) {
                break;
            }
        }
    }
    if (c.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < c.size(); ++i) {
        ff[c[i]] = 1;
        //cout << c[i] << " ";
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (ff[g[i][j]] == 1) {
                f[i][j] = 0;
            }
        }
    }
    qw = 1;
    for (int i = 0; i < c.size(); ++i) {
        if (dfs(c[i], -1)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "FHTAGN!" << endl;
    return 0;
}