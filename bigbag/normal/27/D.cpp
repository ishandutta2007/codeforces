#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, m, u[max_n], v[max_n], clr[max_n], used[max_n];
vector <int> g[max_n];

void dfs(int v, int cl) {
    used[v] = 1;
    clr[v] = cl;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], (cl + 1) % 2);
        } else {
            if (cl == clr[g[v][i]]) {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
    }
}

bool per(int a, int b, int c, int d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    if (c < a && a < d && d < b) {
        return true;
    }
    if (a < c && c < b && b < d) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (per(u[i], v[i], u[j], v[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    /*for (int i = 0; i < m; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            cout << i << ' ' << g[i][j] << endl;
        }
    }*/
    for (int i = 0; i < m; ++i) {
        if (used[i] == 0) {
            dfs(i, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (clr[i] == 0) {
            cout << 'i';
        } else {
            cout << 'o';
        }
    }
    return 0;
}