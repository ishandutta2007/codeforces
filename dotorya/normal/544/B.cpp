#include <stdio.h>
char ANS[105][105];
int main() {
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; i++) for(j = 0; j < N; j++) ANS[i][j] = 'S';

    // get ANS
    int n1 = 0, n2 = 0;
    for(i = 1; i <= K; i++) {
        if(n1 == N) break;
        ANS[n1][n2] = 'L';
        n2 += 2;
        if(n2 >= N) {
            n1++;
            n2 = n1%2;
        }
    }
    if(i != K+1) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) printf("%c", ANS[i][j]);
        printf("\n");
    }
    return 0;
}