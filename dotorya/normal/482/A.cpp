#include <stdio.h>
int main() {
    int N, K, i;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= K+1; i++) {
        if(i % 2 == 1) printf("%d ", (i+1)/2);
        else printf("%d ", K+2-i/2);
    }
    for(i = K+2; i <= N; i++) printf("%d ", i);
    return 0;
}