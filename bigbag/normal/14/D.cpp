#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222;

int n, cnt, del_u, del_v, u[max_n], v[max_n], used[max_n], kol[max_n];
vector <int> g[max_n];

pair <int, int> dfs(int v) {
    used[v] = 1;
    pair <int, int> ret = make_pair(0, v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (v != del_u || g[v][i] != del_v) {
            if (v != del_v || g[v][i] != del_u) {
                if (used[g[v][i]] == 0) {
                    pair <int, int> x = dfs(g[v][i]);
                    ++x.first;
                    ret = max(ret, x);
                }
            }
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        ++kol[u[i]];
        ++kol[v[i]];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        del_u = u[i], del_v = v[i];
        int max1 = 0, max2 = 0;
        for (int j = 1; j <= n; ++j) {
            used[j] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            if (used[j] == 0 && kol[j] == 1) {
                pair <int, int> x = dfs(j);
                if (max1 == 0) {
                    max1 = x.second;
                } else {
                    max2 = x.second;
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            used[j] = 0;
        }
        max1 = dfs(max1).first, max2 = dfs(max2).first;
        ans = max(ans, max1 * max2);
    }
    cout << ans << endl;
    return 0;
}