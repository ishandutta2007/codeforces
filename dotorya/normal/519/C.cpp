#include <stdio.h>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(b >= 2*a) printf("%d", a);
    else if(a >= 2*b) printf("%d", b);
    else printf("%d", (a+b)/3);
    return 0;
}