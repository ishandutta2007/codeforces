#include <stdio.h>
char d[100050];
int cnt[4];
int assignNumber(char c) {
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    return -1;
}
int main() {
    int N, i;
    scanf("%d", &N);
    scanf("%s", d);
    for(i = 0; i < N; i++) {
        cnt[assignNumber(d[i])]++;
    }
    int mx = cnt[0], C = 0;
    for(i = 1; i <= 3; i++) if(mx < cnt[i]) mx = cnt[i];
    for(i = 0; i <= 3; i++) if(mx == cnt[i]) C++;
    long long ans = 1;
    for(i = 1; i <= N; i++) ans = (ans * C) % 1000000007;
    printf("%lld", ans);
    return 0;
}