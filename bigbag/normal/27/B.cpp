#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2222, inf = 111111111;

int n, cnt, used[max_n], num[max_n], u[max_n], v[max_n];
vector <int> g[max_n], a[max_n], t;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    num[v] = cnt;
    ++cnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n * (n - 1) / 2; ++i) {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        a[u[i]].push_back(v[i]);
        a[v[i]].push_back(u[i]);
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() != n - 1) {
            if (x == 0) {
                x = i;
            } else {
                y = i;
            }
        }
    }
    g[x].push_back(y);
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 1; i < n * (n - 1) / 2; ++i) {
        if (num[u[i]] < num[v[i]]) {
            cout << y << ' ' << x << endl;
            return 0;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}