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

const int max_n = 1111, inf = 1111111111;

int n, k, dp[max_n], a[6][max_n], poz[6][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            poz[i][a[i][j]] = j;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            int f = 0;
            for (int q = 1; q < k; ++q) {
                if (poz[q][a[0][i]] < poz[q][a[0][j]]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}