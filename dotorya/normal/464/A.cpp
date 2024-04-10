#include <stdio.h>
char d[1050];
int N, P, L;
char max_char(int a) {
    char mx = 'a'+P-1;
    if(a >= 1) {
        if(mx == d[a-1]) mx--;
    }
    if(a >= 2) {
        if(mx == d[a-2]) mx--;
    }
    if(a >= 1) {
        if(mx == d[a-1]) mx--;
    }
    return mx;
}
int main() {
    int i, st, j;
    scanf("%d %d %s", &N, &P, d);
    for(L = 0; d[L] != 0; L++);
    for(i = L-1; i >= 0; i--) {
        if(d[i] != max_char(i)) break;
    }
    if(i == -1) {
        printf("NO");
        return 0;
    }
    st = i;
    for(i = d[st]+1; i <= 'a'+P-1; i++) {
        if(st >= 1) {
            if(i == d[st-1]) continue;
        }
        if(st >= 2) {
            if(i == d[st-2]) continue;
        }
        d[st] = i;
        break;
    }
    for(i = st+1; i <= L-1; i++) {
        if(i == 1) {
            if(d[i-1] == 'a') d[i] = 'b';
            else d[i] = 'a';
        }
        else {
            if(d[i-1] != 'a' && d[i-2] != 'a') d[i] = 'a';
            else if((d[i-1] != 'b' && d[i-2] == 'a') || (d[i-2] != 'b' && d[i-1] == 'a')) d[i] = 'b';
            else d[i] = 'c';
        }
    }
    printf("%s", d);
    return 0;
}