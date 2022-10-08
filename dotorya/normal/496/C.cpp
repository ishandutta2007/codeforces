#include <stdio.h>
char d[105][105];
char d2[105][105];
int main() {
    int N, M, i, j, k, ans = 0, chk;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%s", d[i]);
    for(i = 0; i < M; i++) {
        for(j = 1; j <= N; j++) {
            d2[j][ans] = d[j][i];
        }
        for(j = 1; j < N; j++) {
            chk = 0;
            for(k = 0; k <= ans; k++) {
                if(d2[j+1][k] < d2[j][k]) {
                    chk = 1;
                    break;
                }
                if(d2[j+1][k] > d2[j][k]) break;
            }
            if(chk == 1) break;
        }
        if(j == N) ans++;
    }
    printf("%d", M-ans);
    return 0;
}