#include <stdio.h>
long long d[2][2];
int main() {
    int chk; 
    long long C, i, ans = 0;
    scanf("%lld %lld %lld %lld %lld", &C, &d[0][0], &d[1][0], &d[0][1], &d[1][1]);
    if(d[0][1] >= 500) {
        for(i = 0; i*d[0][1] <= C; i++) {
            if(i*d[0][0]+((C-i*d[0][1])/d[1][1])*d[1][0] > ans) ans = i*d[0][0]+((C-i*d[0][1])/d[1][1])*d[1][0];
        }
        printf("%lld", ans);
        return 0;
    }
    if(d[1][1] >= 500) {
        for(i = 0; i*d[1][1] <= C; i++) {
            if(i*d[1][0]+((C-i*d[1][1])/d[0][1])*d[0][0] > ans) ans = i*d[1][0]+((C-i*d[1][1])/d[0][1])*d[0][0];
        }
        printf("%lld", ans);
        return 0;
    }
    if(d[0][0]*d[1][1] >= d[0][1]*d[1][0]) chk = 1;
    else chk = 0;
    for(i = 0; i < d[1-chk][1] && d[chk][1]*i <= C; i++) {
        if(i*d[chk][0]+((C-i*d[chk][1])/d[1-chk][1])*d[1-chk][0] > ans) ans = i*d[chk][0]+((C-i*d[chk][1])/d[1-chk][1])*d[1-chk][0];
    }
    printf("%lld", ans);
    return 0;
}