#include <stdio.h>
long long d[100050][3];
long long N[100050];
int m;
int b_s(long long t) {
    int ans;
    int st = 1, en = m, mi;
    while(st <= en) {
        mi = (st+en)/2;
        if(t <= N[mi]) {
            ans = mi;
            en = mi-1;
        }
        else {
            st = mi+1;
        }
    }
    return ans;
}
int main() {
    int n, i, p;
    long long t;
    scanf("%d", &m);
    for(i = 1; i <= m; i++) {
        scanf("%I64d %I64d", &d[i][0], &d[i][1]);
        if(d[i][0] == 1) N[i] = N[i-1]+1;
        if(d[i][0] == 2) {
            scanf("%I64d", &d[i][2]);
            N[i] = N[i-1]+d[i][1]*d[i][2];
        }
    }
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%I64d", &t);
        while(1) {
            p = b_s(t);
            if(d[p][0] == 1) {
                printf("%I64d ", d[p][1]);
                break;
            }
            t = (t-N[p-1]-1)%d[p][1]+1;
        }
    }
    return 0;
}