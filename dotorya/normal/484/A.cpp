#include <stdio.h>
typedef long long ll;
ll pow2[64];
int main() {
    int N, i, j;
    ll t1, t2;
    pow2[0] = 1;
    for(i = 1; i <= 60; i++) pow2[i] = pow2[i-1]*2;

    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%lld %lld", &t1, &t2);
        if(t1 == t2) {
            printf("%lld\n", t1);
            continue;
        }
        ll ANS = 0;
        for(j = 60; j >= 1; j--) {
            if(t2 < pow2[j]-1) continue;
            if(t1 <= pow2[j]-1) break;
            else {
                t2 -= pow2[j];
                t1 -= pow2[j];
                ANS += pow2[j];
            }
        }
        printf("%lld\n", ANS+pow2[j]-1);
    }
    return 0;
}