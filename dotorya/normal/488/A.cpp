#include <stdio.h>
bool chk_8(int a) {
    if(a<0) a = -a;
    while(a>0) {
        if(a%10 == 8) break;
        a /= 10;
    }
    if(a != 0) return true;
    else return false;
}
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= 20; i++) {
        if(chk_8(N+i)) break;
    }
    printf("%d", i);
    return 0;
}