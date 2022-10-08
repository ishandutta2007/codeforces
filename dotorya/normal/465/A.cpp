#include <stdio.h>
char d[100050];
int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", d);
    int i;
    for(i = 0; d[i] != 0; i++) {
        if(d[i] == '0') break;
    }
    if(d[i] == 0) printf("%d", i);
    else printf("%d", i+1);
    return 0;
}