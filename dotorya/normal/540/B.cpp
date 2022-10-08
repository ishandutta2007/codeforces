#include <stdio.h>
int main() {
    int N, K, P, X, Y, t, i;
    int cnt1 = 0, cnt2 = 0, sum = 0;
    scanf("%d %d %d %d %d", &N, &K, &P, &X, &Y);
    for(i = 1; i <= K; i++) {
        scanf("%d", &t);
        sum += t;
        if(t < Y) cnt1++;
        else cnt2++;
    }
    if(cnt2 > N/2+1) {
        sum += (N-cnt1-cnt2);
        if(sum > X) printf("-1");
        else for(i = 1; i <= N-cnt1-cnt2; i++) printf("1 ");
        return 0;
    }
    if(cnt1 > N/2) {
        printf("-1");
        return 0;
    }
    sum += (N/2-cnt1)*1 + (N/2+1-cnt2)*Y;
    if(sum > X) {
        printf("-1");
        return 0;
    }
    for(i = 1; i <= N/2-cnt1; i++) printf("1 ");
    for(i = 1; i <= N/2+1-cnt2; i++) printf("%d ", Y);
    return 0;
}