#include <stdio.h>
int MOD;
int dp[2][505][505];
int A[505];

int main() {
    int N, M, B, i, j, k;
    scanf("%d %d %d %d", &N, &M, &B, &MOD);
    if(MOD == 1) {
        printf("0");
        return 0;
    }
    for(i = 1; i <= N; i++) scanf("%d", &A[i]);
    if(N == 1) {
        if(A[1] * M <= B) printf("1");
        else printf("0");
        return 0;
    }

    // DP
    for(i = 0; A[1]*i <= B && i <= M; i++) dp[1][i][A[1]*i] = 1;

    for(i = 2; i <= N; i++) {
        for(j = 0; j <= M; j++) {   
            for(k = 0; k <= B; k++) {
                if(j == 0 || k < A[i]) dp[i%2][j][k] = dp[(i+1)%2][j][k];
                else dp[i%2][j][k] = (dp[i%2][j-1][k-A[i]] + dp[(i+1)%2][j][k])%MOD;
            }
        }
    }
    long long ANS = 0;
    for(i = 0; i <= B; i++) ANS += dp[N%2][M][i];
    ANS %= MOD;
    printf("%lld", ANS);
    return 0;
}