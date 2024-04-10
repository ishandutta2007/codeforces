#include <stdio.h>
int chk[200050];
char d[200050];
int main() {
    scanf("%s", &d[1]);
    int i, L;
    for(L = 1; d[L] != 0; L++);
    L--;
    int N, t;
    scanf("%d",&N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        chk[t]++;
        chk[L+2-t]--;
    }
    t = 0;
    for(i = 1; i <= L; i++) {
        t += chk[i];
        if(t % 2 == 0) printf("%c", d[i]);
        else printf("%c", d[L+1-i]);
    }
    return 0;
}