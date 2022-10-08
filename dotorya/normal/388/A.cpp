#include <stdio.h>
int d[105];
int d2[105];
int main() {
    int n, t, i;
    int ans = 1;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &t);
        d[t]++;
    }
    for(i = 0; i <= 100; i++) {
        t = 1;
        while(d[i] != 0) {
            if(d2[t] <= i) {
                d[i]--;
                d2[t]++;
            }
            else {
                t++;
                if(t > ans) ans = t;
            }
        }
    }
    printf("%d", ans);
    return 0;
}