#include <stdio.h>
#include <algorithm>
int dp[30050][605];
int value[30050];
int max(int a, int b) {
    if(a<b) return b;
    else return a;
}
int min(int a, int b) {
    if(a>b) return b;
    else return a;
}
int main() {
    int N, D, i, j, MIN, t;
    scanf("%d %d", &N, &D);
    if(D >= 300) MIN = 1;
    else MIN = 301-D;
    for(j = 0; j <= 30000; j++) for(i = MIN-1; i <= 600; i++) dp[j][i] = INT_MIN;
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        value[t]++;
    }
    dp[D][300] = value[D];
    for(i = D+1; i <= 30000; i++) {
        for(j = MIN; j <= 600; j++) {
            t = INT_MIN;
            if(i-j-D+300 < 0) continue;
            if(j != MIN) t = max(t, dp[i-j-D+300][j-1]);
            t = max(t, dp[i-j-D+300][j]);
            if(j != 600) t = max(t, dp[i-j-D+300][j+1]);        
            if(t < 0) continue;
            dp[i][j] = t + value[i];
        }
    }
    int ANS = 0;
    for(j = 0; j <= 30000; j++) for(i = MIN-1; i <= 600; i++) if(ANS < dp[j][i]) ANS = dp[j][i];
    printf("%d", ANS);
    return 0;
}