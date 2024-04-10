#include <stdio.h>
int d[100050];
int chk[100050];
int main() {
    int N, M, W, i, st = 1000000001, en, mi, ans;
    long long tmp, sum;
    scanf("%d %d %d", &N, &M, &W);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        if(st > d[i]) st = d[i];
    }
    en = st+M, ans = st;
    while(st <= en) {
        tmp = 0;
        sum = 0;
        mi = (st+en)/2;
        for(i = 1; i <= N; i++) {
            if(i > W) sum -= chk[i-W];
            if(sum+d[i] < mi) chk[i] = mi-sum-d[i];
            else chk[i] = 0;
            sum += chk[i];
        }
        sum = 0;
        for(i = 1; i <= N; i++) sum += chk[i];
        if(sum > M) en = mi-1;
        else {
            ans = mi;
            st = mi+1;
        }
    }
    printf("%d", ans);
    return 0;
}