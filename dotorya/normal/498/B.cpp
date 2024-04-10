#include <stdio.h>
double P[5050];
int time[5050];
double dp[2][5050];
double prob[5050];
double tot_prob[5050];
int main() {
    int N, T, i, j, k, t1, t2;
    double t3;
    scanf("%d %d", &N, &T);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &t1, &time[i]);
        P[i] = t1*1.0/100;
    }
    dp[1][1] = P[1];
    for(i = 2; i < time[1]; i++) {
        dp[1][i] = dp[1][i-1] * (1-P[1]);
    }
    if(time[1] == 1 || P[1] < 0.00001) dp[1][time[1]] = 1;
    else dp[1][time[1]] = dp[1][time[1]-1] * (1-P[1])/P[1];
    for(i = 1; i <= T; i++) tot_prob[1] += dp[1][i];
    for(i = 2; i <= N; i++) {
        prob[1] = P[i];
        for(j = 2; j < time[i]; j++) {
            prob[j] = prob[j-1]*(1-P[i]);
        }
        if(time[i] == 1 || P[i] < 0.00001) prob[time[i]] = 1;
        else prob[time[i]] = prob[time[i]-1]*(1-P[i])/P[i];
        dp[i%2][i] = t3 = dp[(i+1)%2][i-1] * prob[1];
        for(j = i; j < T; j++) {
            if(j >= time[i]) t3 -= prob[time[i]]*dp[(i+1)%2][j-time[i]];
            if(j+1 >= time[i]) t3 -= prob[time[i]-1]*dp[(i+1)%2][j+1-time[i]];
            t3 *= (1-P[i]);
            if(j+1 > time[i]) t3 += prob[time[i]]*dp[(i+1)%2][j+1-time[i]];
            if(time[i] != 1) t3 += prob[1]*dp[(i+1)%2][j];
            dp[i%2][j+1] = t3;
        }
        for(j = i; j <= T; j++) tot_prob[i] += dp[i%2][j];
        for(j = 0; j <= i-1; j++) dp[i%2][j] = 0;
    }
    double ANS = 0;
    for(i = 1; i <= N; i++) ANS += (tot_prob[i]-tot_prob[i+1])*i;
    printf("%.12lf", ANS);
    return 0;
}