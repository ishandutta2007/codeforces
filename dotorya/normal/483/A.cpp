#include <stdio.h>
int main() {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if(r-l <= 1) {
        printf("-1");
        return 0;
    }
    else if(r-l >= 3) {
        if(l % 2 == 0) printf("%lld %lld %lld", l, l+1, l+2);
        else printf("%lld %lld %lld", l+1, l+2, l+3);
        return 0;
    }
    if(l % 2 == 0) printf("%lld %lld %lld", l, l+1, l+2);
    else printf("-1");
    return 0;
}