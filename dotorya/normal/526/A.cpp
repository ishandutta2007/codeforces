#include <stdio.h>
char d[1050];
int main() {
    int N, i, j;
    scanf("%d", &N);
    scanf("%s", d);
    for(i = 0; d[i] != 0; i++) {
        for(j = 1; d[i+j] != 0; j++) {
            if(d[i] == '*' && d[i+j] == '*' && d[i+2*j] == '*' && d[i+3*j] == '*' && d[i+4*j] == '*') break;
        }
        if(d[i+j] != 0) break;
    }
    if(d[i] == 0) printf("no");
    else printf("yes");
    return 0;
}