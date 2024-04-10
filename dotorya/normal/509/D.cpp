#include <stdio.h>
long long d1[305];
long long d2[305];
long long diff[305];
const long long NONE = -1234567890123456789L;
long long ans[305];
long long ABS(long long x) {
    if(x>0) return x;
    else return -x;
}
int main() {
    int i, j, N, M, tmp;
    long long mx = 0, t1, t2, mod = NONE;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%lld", &d1[i]);
        if(mx < d1[i]) mx = d1[i];
    }
    ans[1] = 0;
    for(i = 2; i <= N; i++) {
        t1 = t2 = NONE;
        for(j = 1; j <= M; j++) {
            scanf("%lld", &d2[j]);
            if(mx < d2[i]) mx = d2[j];
            diff[j] = d2[j]-d1[j];
            if(diff[j] != t1) {
                if(t1 == NONE) t1 = diff[j];
                else if(t2 == NONE) t2 = diff[j];
                else if(t2 == diff[j]) continue;
                else break;
            }
        }
        if(j != M+1) break;
        if(t2 == NONE) {
            ans[i] = t1;
            continue;
        }
        if(mod == NONE) {
            mod = ABS(t1-t2);
            ans[i] = t1;
            continue;
        }
        if(mod != ABS(t1-t2)) break;
        else ans[i] = t1;
    }
    if(mod == NONE) mod = 1000000000000000000L;
    if(i != N+1 || mx >= mod) {
        printf("NO");
        return 0;
    }
    for(i = 1; i <= N; i++) {
        if(ans[i] < 0) ans[i] += mod;
    }
    printf("YES\n%lld\n", mod);
    for(i = 1; i <= N; i++) printf("%lld ", ans[i]);
    printf("\n");
    for(i = 1; i <= M; i++) printf("%lld ", d1[i]);
    return 0;
}