#include <stdio.h>
double dp[105][105][105][3];
int main() {
    int i, j, k, l, R, S, P;
    scanf("%d %d %d", &R, &S, &P);

    //Initialize
    for(i = 1; i <= R; i++) dp[i][0][0][0] = 1.0;
    for(i = 1; i <= S; i++) dp[i][0][0][1] = 1.0;
    for(i = 0; i <= P; i++) dp[i][0][0][2] = 1.0;
    for(i = 1; i <= R; i++) for(j = 1; j <= S; j++) dp[i][j][0][0] = 1.0;
    for(i = 1; i <= S; i++) for(j = 1; j <= P; j++) dp[0][i][j][1] = 1.0;
    for(i = 1; i <= R; i++) for(j = 1; j <= P; j++) dp[i][0][j][2] = 1.0;

    // DP
    for(i = 1; i <= R; i++) {
        for(j = 1; j <= S; j++) {
            for(k = 1; k <= P; k++) {
                for(l = 0; l <= 2; l++) {
                    dp[i][j][k][l] = (dp[i-1][j][k][l] * i * k + dp[i][j-1][k][l] * i * j + dp[i][j][k-1][l] * j * k) / (i*j+j*k+i*k);
                }
            }
        }
    }

    printf("%.20lf %.20lf %.20lf", dp[R][S][P][0], dp[R][S][P][1], dp[R][S][P][2]);
    return 0;
}