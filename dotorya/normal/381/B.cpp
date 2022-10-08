#include <stdio.h>
int d[5050];
int main() {
    int n, i, a, ans, mx;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a);
        d[a]++;
    }
    for(i = 5000; i >= 1; i--) {
        if(d[i] != 0) {
            mx = i;
            break;
        }
    }
    ans = 1;
    for(i = mx-1;i>=1;i--) {
        if(d[i] >= 2) ans += 2;
        else ans += d[i];
    }
    printf("%d\n", ans);
    for(i = 1; i < mx; i++) if(d[i] >= 1) printf("%d ", i);
    printf("%d ", mx);
    for(i = mx-1; i >= 1; i--) if(d[i] >= 2) printf("%d ", i);
    return 0;
}