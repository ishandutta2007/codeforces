#include <stdio.h>
#include <vector>
using namespace std;
const int INF = 123456789;
int dp[105][150000][3];
int d[105];
int P[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59}; // 17
int DIV[70];

int ANS_d[105];
int main() {
    int N, i, j, k;
    for(i = 1; i <= 59; i++) {
        int t = 1;
        for(j = 0; j < 17; j++) {
            if(i%P[j] == 0) DIV[i] += t;
            t *= 2;
        }
    }
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        for(j = 0; j < (1<<17); j++) dp[i][j][0] = INF;
    }

    // BIT DP
    for(i = 1; i <= 59; i++) {
        if(dp[1][DIV[i]][0] > abs(d[1]-i)) {
            dp[1][DIV[i]][0] = abs(d[1]-i);
            dp[1][DIV[i]][1] = i;
            dp[1][DIV[i]][2] = -1;
        }
    }

    for(i = 2; i <= N; i++) {
        for(j = 0; j < (1<<17); j++) {
            for(k = 1; k < 2*d[i]; k++) {
                if((j&DIV[k]) != 0) continue;
                if(dp[i][j|DIV[k]][0] > dp[i-1][j][0]+abs(d[i]-k)) {
                    dp[i][j|DIV[k]][0] = dp[i-1][j][0]+abs(d[i]-k);
                    dp[i][j|DIV[k]][1] = k;
                    dp[i][j|DIV[k]][2] = j;
                }
            }
        }
    }
    
    // Get ANS
    int ANS = 0;
    for(i = 1; i < (1<<17); i++) {
        if(dp[N][ANS][0] > dp[N][i][0]) ANS = i;
    }

    int st = ANS;
    for(i = N; i >= 1; i--) {
        ANS_d[i] = dp[i][st][1];
        st = dp[i][st][2];
    }
        
    for(i = 1; i <= N; i++) printf("%d ", ANS_d[i]);
    return 0;
}