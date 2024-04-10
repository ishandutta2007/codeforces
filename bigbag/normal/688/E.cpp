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

const int max_n = 555, inf = 1111111111;

int n, k, dp[2][max_n][max_n];

int main() {
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int q1 = 0, q2 = 1;
    dp[q1][0][0] = 1;
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = k; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[q2][i][j] = dp[q1][i][j];
            }
        }
        for (int i = k - x; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[q1][i][j]) {
                    dp[q2][i + x][j] = 1;
                    dp[q2][i + x][j + x] = 1;
                }
            }
        }
        swap(q1, q2);
    }
    vector<int> ans;
    for (int i = 0; i <= k; ++i) {
        if (dp[q1][k][i]) {
            ans.push_back(i);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}