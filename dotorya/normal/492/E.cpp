#include <stdio.h>
int cnt[1000050];
int main() {
    long long N, M, dx, dy, t, t1, t2, i;
    scanf("%lld %lld %lld %lld", &N, &M, &dx, &dy);
    for(i = 1; i <= N; i++) {
        if((dx*i-dy)%N == 0) break;
    }
    t = N-i;
    for(i = 1; i <= M; i++) {
        scanf("%lld %lld", &t1, &t2);
        cnt[(t1*t+t2)%N]++;
    }
    int mx = 0;
    for(i = 1; i < N; i++) {
        if(cnt[i] > cnt[mx]) mx = i;
    }
    printf("0 %d", mx);
    return 0;
}