#include <stdio.h>
int chk[1000];
int ghost[305];
int main() {
    int M, T, R, i, j, C, ans = 0;
    scanf("%d %d %d", &M, &T, &R);
    for(i = 1; i <= M; i++) {
        scanf("%d", &ghost[i]);
        ghost[i] += T;
    }
    if(T < R) {
        printf("-1");
        return 0;
    }
    for(i = 1; i <= M; i++) {
        C = 0;
        for(j = ghost[i]-T; j <= ghost[i]-1; j++) C += chk[j];
        for(j = 1; j <= R-C; j++) chk[ghost[i]-j] = 1;
    }
    for(j = ghost[1]-T; j <= ghost[M]; j++) ans += chk[j];
    printf("%d", ans);
    return 0;
}