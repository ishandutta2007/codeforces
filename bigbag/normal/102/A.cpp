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

int n, m, c[max_n], a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u - 1][v - 1] = a[v - 1][u - 1] = 1;
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i][j] && a[i][k] && a[j][k]) {
                    ans = min(c[i] + c[j] + c[k], ans);
                }
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}