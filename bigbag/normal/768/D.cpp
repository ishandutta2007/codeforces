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

const int max_n = 1011, max_d = 11111, inf = 1011111111;
const long double eps = 1e-9;

int k, q, ans[max_n];
long double dp[2][max_n], v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        v[i] = ((long double) i) / 2000 - eps;
        ans[i] = inf;
    }
    cin >> k >> q;
    int q1 = 0, q2 = 1;
    dp[q1][0] = 1;
    for (int i = 0; i < max_d; ++i) {
        for (int j = 1; j < max_n; ++j) {
            if (dp[q1][k] >= v[j]) {
                ans[j] = min(ans[j], i);
            }
        }
        memset(dp[q2], 0, sizeof(dp[q2]));
        for (int j = 0; j <= k; ++j) {
            dp[q2][j] += (dp[q1][j] * j) / k;
            dp[q2][j + 1] += (dp[q1][j] * (k - j)) / k;
            //dp[q2][j] /= k;
        }
        swap(q1, q2);
    }
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}