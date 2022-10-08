#include <stdio.h>
char d[100050];
int main() {
    scanf("%s", d);
    int i, j, L, chk = 0;
    for(L = 0; d[L] != 0; L++);
    for(i = 0; i < L; i++) {
        if((d[i]-'0')%2 == 0) break;
    }
    if(i == L) {
        printf("-1");
        return 0;
    }
    for(i = 0; i < L; i++) {
        if((d[i]-'0')%2 == 0 && d[i] < d[L-1]) break;
    }
    if(i != L) {
        for(j = 0; j < L; j++) {
            if(j != i && j != L-1) printf("%c", d[j]);
            else printf("%c", d[L-1+i-j]);
        }
        return 0;
    }
    for(i = L-1; i >= 0; i--) {
        if((d[i]-'0')%2 == 0) break;
    }
    for(j = 0; j < L; j++) {
        if(j != i && j != L-1) printf("%c", d[j]);
        else printf("%c", d[L-1+i-j]);
    }
    return 0;
}