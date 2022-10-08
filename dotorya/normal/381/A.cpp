#include <stdio.h>
int d[1050];
int ans[2];
int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &d[i]);
    int st = 1, en = n, chk = 0;
    while(st <= en) {
        if(d[st] < d[en]) {
            ans[chk%2] += d[en];
            en--;
        }
        else {
            ans[chk%2] += d[st];
            st++;
        }
        chk++;
    }
    printf("%d %d", ans[0], ans[1]);
    return 0;
}