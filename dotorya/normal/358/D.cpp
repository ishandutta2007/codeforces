#include <stdio.h>
int dp[3050][2];
int A[3050];
int B[3050];
int C[3050];
int MAX(int a, int b) {
    return (a<b)?b:a;
}
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &A[i]);
    for(i = 1; i <= N; i++) scanf("%d", &B[i]);
    for(i = 1; i <= N; i++) scanf("%d", &C[i]);

    // DP
    dp[1][0] = A[1];
    dp[1][1] = B[1];
    for(i = 2; i <= N; i++) {
        dp[i][0] = MAX(dp[i-1][1]+A[i], dp[i-1][0]+B[i]);
        dp[i][1] = MAX(dp[i-1][1]+B[i], dp[i-1][0]+C[i]);
    }
    printf("%d", dp[N][0]);
    return 0;
}