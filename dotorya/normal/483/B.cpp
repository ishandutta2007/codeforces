#include <stdio.h>
int main() {
    long long cnt1, cnt2, x, y, cnt, m;
    scanf("%lld %lld %lld %lld", &cnt1, &cnt2, &x, &y);
    cnt = cnt1+cnt2;
    m = x*y;
    long long st = 1, en = 1234567891234, mi, ans = 1234567891235;
    while(st <= en) {
        mi = (st+en)/2;
        if(mi - mi/x >= cnt1 && mi - mi/y >= cnt2 && mi - mi/m >= cnt) {
            ans = mi;
            en = mi-1;
        }
        else st = mi+1;
    }
    printf("%lld", ans);
    return 0;
}