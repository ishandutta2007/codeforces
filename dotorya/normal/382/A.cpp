#include <stdio.h>

char d[1000000];
char d2[1000000];
int main() {
    int i, l = 0, r = 0, chk = 0, len = 0;
    scanf("%s", d);
    for(i = 0; d[i] != 0; i++) {
        if(d[i] == '|') chk = 1;
        else if(chk == 0) l++;
        else r++;
    }
    scanf("%s", d2);
    for(i = 0; d2[i] != 0; i++) len++;
    if((l+r+len)%2) printf("Impossible");
    else if(l>r+len || r>l+len) printf("Impossible");
    else {
        for(i = 0; i < l; i++) printf("%c", d[i]);
        for(i = 0; i < (r+len-l)/2; i++) printf("%c", d2[i]);
        printf("|");
        for(i = l+1; d[i] != 0; i++) printf("%c", d[i]);
        for(i = (r+len-l)/2; i < len; i++) printf("%c", d2[i]);
    }
    return 0;
}