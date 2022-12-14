#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int A[105], B[105];
int dp[105][10005], pp[105][10005];
int main() {
    scanf("%d", &n);
    int sumA = 0, sumB = 0;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &A[i], &B[i]);
        memcpy(pp, dp, sizeof(dp));
        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < i; j++) {
            for (int a = 0; a <= sumA; a++) {
                if (pp[j][a] == -1) continue;
                dp[j][a] = max(dp[j][a], pp[j][a]);
                dp[j + 1][a + A[i]] = max(dp[j + 1][a + A[i]], pp[j][a] + B[i]);
            }
        }
        sumA += A[i];
        sumB += B[i];
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j <= sumA; j++) {
            if (dp[i][j] == -1) continue;
            ans = max(ans, min(2 * j, dp[i][j] + sumB));
        }
        printf("%.1f ", ans / 2.0);
    }
}