#include <stdio.h>
int d[100050];
int main() {
    int N, i, ans = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        ans += d[i];
    }
    if(ans == 0) {
        printf("0");
        return 0;
    }
    for(i = 1; i <= N; i++) {
        if(d[i] == 0) continue;
        ans++;
        while(i < N) {
            if(d[i+1] == 0) break;
            i++;
        }
    }
    printf("%d", ans-1);
    return 0;
}