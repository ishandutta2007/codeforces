#include <stdio.h>
char t[100050];
int d[5];
int main() {
    scanf("%d %d %d %d", &d[1], &d[2], &d[3], &d[4]);
    scanf("%s", t);
    int ans = 0, i;
    for(i = 0; t[i] != 0; i++) {
        ans += d[t[i]-'0'];
    }
    printf("%d", ans);
    return 0;
}