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

const int max_n = 111, inf = 111111111;

int n, m, k, a[max_n][max_n], ans[max_n], used[max_n], f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        memset(used, 0, sizeof(used));
        for (int j = 0; j < n; ++j) {
            if (ans[j] == 0) {
                if (f[a[j][i]] == 1) {
                    ans[j] = i + 1;
                } else {
                    ++used[a[j][i]];
                }
            }
        }
        for (int j = 1; j <= k; ++j) {
            if (used[j] > 1) {
                f[j] = 1;
                for (int q = 0; q < n; ++q) {
                    if (ans[q] == 0 && a[q][i] == j) {
                        ans[q] = i + 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}