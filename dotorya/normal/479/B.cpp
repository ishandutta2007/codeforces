#include <stdio.h>
int d[105];
int ans[1005][3];
int main() {
    int i, j, N, K, mx, mn;
    scanf("%d %d", &N, &K);
    mx = mn = 1;
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        if(d[mx] < d[i]) mx = i;
        if(d[mn] > d[i]) mn = i;
    }
    ans[0][0] = mx, ans[0][1] = mn;
    if(d[mx]-d[mn] == 0) {
        printf("0 0");
        return 0;
    }
    for(i = 1; i <= K; i++) {
        mx = mn = 1;
        for(j = 2; j <= N; j++) {
            if(d[mx] < d[j]) mx = j;
            if(d[mn] > d[j]) mn = j;
        }
        if(mx == mn) break;
        ans[i][0] = mx, ans[i][1] = mn, ans[i-1][2] = d[mx]-d[mn];
        d[mx]--;
        d[mn]++;
    }
    if(i != K+1) {
        printf("0 %d\n", i-1);
        for(j = 1; j <= i-1; j++) printf("%d %d\n", ans[j][0], ans[j][1]);
        return 0;
    }
    mx = mn = 1;
    for(i = 2; i <= N; i++) {
        if(d[mx] < d[i]) mx = i;
        if(d[mn] > d[i]) mn = i;
    }
    for(i = K-1; i >= 0; i--) {
        if(d[mx]-d[mn] != ans[i][2]) break;
    }
    K = i+1;
    printf("%d %d\n", d[mx]-d[mn], K);
    for(j = 1; j <= K; j++) printf("%d %d\n", ans[j][0], ans[j][1]);
    return 0;
}