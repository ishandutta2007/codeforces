#include <stdio.h>
int main() {
    int t,i,sum=0;
    for(i = 0; i <= 4; i++) {
        scanf("%d", &t);
        sum += t;
    }
    if(sum%5 != 0 || sum == 0) printf("-1");
    else printf("%d", sum/5);
    return 0;
}