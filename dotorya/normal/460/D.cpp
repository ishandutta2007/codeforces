#include <stdio.h>
long long L, R, K;
int main() {
    scanf("%lld %lld %lld", &L, &R, &K);
    if(K >= 5 || (K == 4 && R-L >= 4)) {
        printf("0\n4\n");
        if(L % 2 == 1) printf("%lld %lld %lld %lld", L+1, L+2, L+3, L+4);
        else printf("%lld %lld %lld %lld", L, L+1, L+2, L+3);
        return 0;
    }
    if(K == 4) {
        if(L % 2 == 0) printf("0\n4\n%lld %lld %lld %lld", L, L+1, L+2, L+3);
        else {
            if((L^(L+1)^(L+2)^(L+3)) >= L && (L^(L+1)^(L+2)^(L+3)) <= L+3) {
                long long chk = L^(L+1)^(L+2)^(L+3) - L;
                printf("0\n3\n");
                for(int i = 0; i <= 3; i++) {
                    if(chk == i) continue;
                    printf("%lld ", L+i);
                }
            }
            else printf("1\n2\n%lld %lld", L+1, L+2);
            return 0;
        }
    }
    if(K == 1) {
        printf("%lld\n1\n%lld", L, L);
        return 0;
    }
    if(K == 2) {
        if(R-L >= 2) {
            printf("1\n2\n");
            if(L % 2 == 0) printf("%lld %lld", L, L+1);
            else printf("%lld %lld", L+1, L+2);
            return 0;
        }
        else {
            if(L <= (L^R)) {
                printf("%lld\n1\n%lld", L, L);
            }
            else {
                printf("%lld\n2\n%lld %lld", L^R, L, R);
            }
            return 0;
        }
    }
    if(K == 3) {
        long long t = 1;
        while(t * 2 <= L) {
            t *= 2;
        }
        if(t*3 <= R) {
            printf("0\n3\n");
            printf("%lld %lld %lld", L, 3*t, (3*t)^L);
        }
        else {
            printf("1\n2\n");
            if(L % 2 == 0) printf("%lld %lld", L, L+1);
            else printf("%lld %lld", L+1, L+2);
        }
    }
    return 0;
}