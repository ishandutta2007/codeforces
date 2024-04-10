#include <stdio.h>
char d[1005];
int chk[30];
bool ANS_CHK[1005];
int main() {
    int i, j, K;
    scanf("%d %s", &K, &d[1]);
    for(i = 1; d[i] != 0; i++) {
        if(chk[d[i]-'a'] == 0) chk[d[i]-'a'] = i;
    }
    int cnt = 0;
    for(i = 0; i <= 25; i++) {
        if(chk[i] != 0) {
            cnt++;
            ANS_CHK[chk[i]] = true;
        }
    }
    if(cnt < K) printf("NO");
    else {
        printf("YES");
        cnt = 0;
        for(i = 1; d[i] != 0; i++) {
            if(ANS_CHK[i] && cnt < K) {
                printf("\n");
                cnt++;
            }
            printf("%c", d[i]);
        }
    }
    return 0;
}