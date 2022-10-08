#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1034567891;

int A[105];
int B[105];
int Bt[105];
int dp[2][105][10050];
int main() {
    int N, i, j, k, s = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", A+i);
        s += A[i];
    }
    for(i = 1; i <= N; i++) {
        scanf("%d", B+i);
        Bt[i] = B[i];
    }
    sort(Bt+1, Bt+N+1);

    int s2 = 0, c = 0;
    for(i = N; i >= 1; i--) {
        s2 += Bt[i];
        if(s2 >= s) break;
    }
    c = N+1-i;
    printf("%d ", N+1-i);

    for(i = 0; i <= N; i++) for(j = 0; j <= 100*N; j++) dp[0][i][j] = -INF;
    dp[0][0][0] = 0;
    for(i = 1; i <= N; i++) {
        int t = i%2;
        for(j = 0; j <= i; j++) {
            for(k = 0; k <= 100*N; k++) {
                dp[t][j][k] = -INF;
                if(j != i) dp[t][j][k] = dp[1-t][j][k];
                if(j != 0 && k >= B[i]) dp[t][j][k] = max(dp[t][j][k], dp[1-t][j-1][k-B[i]] + A[i]);
            }
        }
    }

    int ans = 0;
    for(i = s; i <= 100*N; i++) ans = max(ans, dp[N%2][c][i]);
    printf("%d\n", s - ans);
    return 0;
}