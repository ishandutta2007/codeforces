#include <stdio.h>
int main() {
    int N, K, i;
    scanf("%d %d", &N, &K);
    printf("%d\n", (6*N-1)*K);
    for(i = 0; i < N; i++) printf("%d %d %d %d\n", (6*i+1)*K, (6*i+2)*K, (6*i+3)*K, (6*i+5)*K);
    return 0;
}