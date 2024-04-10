#include <stdio.h>
long long dp[1005][105];
long long pow_10[1005][2];
int main() {
    int N, K, M;
    long long i, j, k;
    long long tmp;
    scanf("%d %d %d", &N, &K, &M);
    pow_10[0][0] = pow_10[0][1] = 1;
    for(i = 1; i <= 1000; i++) {
        pow_10[i][0] = (pow_10[i-1][0]*10)%K;
        pow_10[i][1] = (pow_10[i-1][1]*10)%M;
    }
    if(N == 1) {
        int cnt = 0;
        for(i = 1; i <= 9; i++) {
            if(i%K == 0) cnt++;
        }
        printf("%d", cnt%M);
        return 0;
    }
    for(i = 1; i <= 9; i++) dp[1][i%K]++;
    for(i = 2; i <= N; i++) {
        for(j = 0; j <= 9; j++) {
            if(i == N && j == 0) continue;
            tmp = (j*pow_10[i-1][0])%K;
            for(k = 1; k <= K-1; k++) {
                dp[i][(k+tmp)%K] = (dp[i][(k+tmp)%K] + dp[i-1][k])%M;
            }
            if(j != 0) dp[i][tmp]++;
        }
    }
    long long ANS = dp[N][0];
    for(i = N-1; i >= 1; i--) {
        ANS = (ANS + dp[i][0]*pow_10[N-1-i][1]*9)%M;
    }
    printf("%lld", ANS);
    return 0;
}