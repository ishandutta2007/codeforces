#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, u[max_n], v[max_n];
map <int, vector <int> > g;
map <int, int> m2, used;
map <int, vector <int> > m1;

void dfs(int v) {
    cout << v << ' ';
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!used.count(g[v][i])) {
            dfs(g[v][i]);
            return;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        m1[u[i]].push_back(i);
        m2[u[i]]++;
        m1[v[i]].push_back(i);
        m2[v[i]]++;
    }
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (m2[u[i]] == 1) {
            x = u[i];
            break;
        }
        if (m2[v[i]] == 1) {
            x = v[i];
            break;
        }
    }
    dfs(x);
    return 0;
}