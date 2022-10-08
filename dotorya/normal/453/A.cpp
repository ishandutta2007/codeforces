#include <stdio.h>
int main() {
    int N, M, i, j;
    scanf("%d %d", &M, &N);
    double ANS = M;
    for(i = 1; i * N <= 30000000 && i < M; i++) {
        double t = 1;
        for(j = 1; j <= N; j++) t *= 1.0*(M-i)/M;
        ANS -= t;
    }
    printf("%.20lf", ANS);
    return 0;
}