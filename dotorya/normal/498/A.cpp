#include <stdio.h>
long long d[350][3];
int main() {
    long long x1, y1, x2, y2;
    int N, i, ans = 0, cnt;
    scanf("%I64d %I64d %I64d %I64d", &x1, &x2, &y1, &y2);
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        cnt = 0;
        scanf("%I64d %I64d %I64d", &d[i][0], &d[i][1], &d[i][2]);
        if(x1*d[i][0]+x2*d[i][1]+d[i][2] > 0) cnt++;
        if(y1*d[i][0]+y2*d[i][1]+d[i][2] > 0) cnt++;
        if(cnt == 1) ans++;
    }
    printf("%d", ans);
    return 0;
}