#include <stdio.h>
int dp[15][15];
int main() {
    int i, j, N;
    for(i = 1; i <= 10; i++) dp[i][1] = dp[1][i] = 1;
    for(i = 2; i <= 10; i++) {
        for(j = 2; j <= 10; j++) {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    scanf("%d", &N);
    printf("%d", dp[N][N]);
    return 0;
}