#include <stdio.h>
long long ans1[105][105];
long long ans2[105][105];
int main() {
    int N, K, D, i, j, k;
    scanf("%d %d %d", &N, &K, &D);
    for(i = 1; i <= K; i++) ans1[1][i] = 1;
    for(i = 2; i <= N; i++) {
        for(j = i; j <= N; j++) {
            for(k = 1; k <= K && k <= j; k++) {
                ans1[i][j] = (ans1[i-1][j-k]+ans1[i][j]) % 1000000007;
            }
        }
    }
    for(i = 1; i <= D-1; i++) ans2[1][i] = 1;
    for(i = 2; i <= N; i++) {
        for(j = i; j <= N; j++) {
            for(k = 1; k <= D-1 && k <= j; k++) {
                ans2[i][j] = (ans2[i][j]+ans2[i-1][j-k]) % 1000000007;
            }
        }
    }
    long long ans = 0;
    for(i = 1; i <= N; i++) ans += ans1[i][N];
    for(i = 1; i <= N; i++) ans -= ans2[i][N];
    ans %= 1000000007;
    if(ans < 0) ans += 1000000007;
    printf("%lld", ans);
    return 0;
}