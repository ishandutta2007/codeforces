#include <stdio.h>
int d[55][2];
int main() {
    int N, X, i, ANS = 0;
    scanf("%d %d", &N, &X);
    for(i = 1; i <= N; i++) scanf("%d %d", &d[i][0], &d[i][1]);
    ANS += (d[1][0]-1)%X;
    for(i = 1; i <= N; i++) {
        ANS += d[i][1] - d[i][0] + 1;
        if(i == N) break;
        ANS += (d[i+1][0]-d[i][1]-1)%X;
    }
    printf("%d", ANS);
    return 0;
}