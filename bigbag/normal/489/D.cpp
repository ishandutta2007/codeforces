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

const int max_n = 3033, inf = 1111111111;

long long ans, x;
int n, m, a[max_n][max_n];
vector<int> g[max_n], rg[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        for (int j = 0; j < g[v].size(); ++j) {
            ++a[u][g[v][j]];
            //cout <<"!" << u << " " << g[v][j] << endl;
        }
        for (int j = 0; j < rg[u].size(); ++j) {
            ++a[rg[u][j]][v];
            //cout << "!" << rg[u][j] << " " << v << endl;
        }
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                x = a[i][j];
                //cout << i << " " << j << " " << x << endl;
                ans += (x * (x - 1)) / 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}