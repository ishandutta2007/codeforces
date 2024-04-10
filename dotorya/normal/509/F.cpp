#include <stdio.h>
long long MOD = 1000000007;
long long dp[505][505];
int d[505];
int isLarger[505][505];
    int main() {
    int N, i, j, k;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);
    for(i = 1; i <= N; i++) {
        for(j = i; j <= N; j++) {
            if(d[i] < d[j]) isLarger[i][j] = 1;
        }
    }
    for(i = 2; i <= N; i++) dp[i][i-1] = dp[i][i] = 1;
    for(i = 1; i <= N-2; i++) {
        for(j = 2; j <= N-i; j++) {
            dp[j][i+j] = dp[j+1][j+i];
            for(k = j+1; k <= j+i; k++) {
                dp[j][i+j] += isLarger[j][k] * dp[j+1][k-1] * dp[k][j+i];
                dp[j][i+j] %= MOD;
            }
        }
    }
    if(N == 1) printf("1");
    else printf("%lld", dp[2][N]);
    return 0;
}