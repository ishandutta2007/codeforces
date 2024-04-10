#include <stdio.h>
char c1[150];
char c2[150];
int d1[150];
int d2[150];
int main() {
    int i, L;
    scanf("%s %s", c1, c2);
    for(L = 0; c1[L] != 0; L++) {
        d1[L] = c1[L]-'a';
        d2[L] = c2[L]-'a';
    }
    d1[L-1]++;
    for(i = L-1; i >= 0; i--) {
        if(d1[i] == 26) {
            d1[i] = 0;
            d1[i-1]++;
        }
    }
    int chk = 0;
    for(i = 0; i < L; i++) {
        if(d1[i] < d2[i]) {
            chk = 1;
            break;
        }
        if(d1[i] > d2[i]) break;
    }
    if(chk == 0) printf("No such string");
    else for(i = 0; i < L; i++) printf("%c", d1[i]+'a');
    return 0;
}