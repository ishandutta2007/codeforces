#include <stdio.h>
int main() {
    int N, M,i;
    scanf("%d %d", &N, &M);
    for(i = M; i <= N; i+=M) {
        if(i <= N && i*2 >= N) break;
    }
    if(i <= N) printf("%d", i);
    else printf("-1");
    return 0;
}