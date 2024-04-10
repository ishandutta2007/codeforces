#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;
const int max_log = 20;

ll x[max_n], y[max_n];
int pr[max_n];
vector<vector<int> > g;
int up[max_n][max_log];
int tin[max_n], tout[max_n], t;
int n;

void dfs(int v, int pr) {
    up[v][0] = pr;
    for (int i = 1; i < max_log; ++i) 
        up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = t;
    ++t;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u == pr) continue;
        dfs(u, v);
    }
    tout[v] = t;
    ++t;
}

int is_a(int v, int a) {
    return tin[a] <= tin[v] && tout[a] >= tout[v];
}

int lca(int v1, int v2) {
    if (is_a(v1, v2)) return v2;
    if (is_a(v2, v1)) return v1;
    for (int i = max_log - 1; i >= 0; --i)
        if (!is_a(v2, up[v1][i])) {
            v1 = up[v1][i];
        }
    return up[v1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];
        g.clear();
        g.resize(n);
        pr[n - 1] = -1;
        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (pr[j] != -1) {
                int k = pr[j];
                if ((y[j] - y[i]) * (x[k] - x[i]) < (x[j] - x[i]) * (y[k] - y[i])) {
                    j = k;
                } else {
                    break;
                }
            }
            pr[i] = j;
            g[i].push_back(j);
            g[j].push_back(i);
        }

        t = 0;
        dfs(n - 1, n - 1);
        
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            --v1; --v2;
            cout << lca(v1, v2) + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}