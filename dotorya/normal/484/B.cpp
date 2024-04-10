#include <stdio.h>
int d[200050];
int isLarger[2000050];
int chk[1000050];
int main() {
    int N, i, j, tmp, ans = 0;
    scanf("%d", &N);
    if(N == 1) {
        printf("0");
        return 0;
    }
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        chk[d[i]] = 1;
    }
    for(i = 1; i <= 1000000; i++) {
        if(chk[i] == 0) continue;
        d[++d[0]] = i;
    }
    for(i = 1; i <= d[0]; i++) {
        for(j = d[i]; j < d[i+1]; j++) isLarger[j] = i;
    }
    for(j = d[d[0]]; j <= 2000000; j++) isLarger[j] = d[0];
    for(i = 1; i <= d[0]; i++) {
        for(j = 2; (j-1)*d[i] <= 1000000; j++) {
            if(ans < d[isLarger[j*d[i]-1]] % d[i]) ans = d[isLarger[j*d[i]-1]] % d[i];
        }
    }
    printf("%d", ans);
    return 0;
}