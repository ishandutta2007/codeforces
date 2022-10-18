//And they lived happily ever after
#include <cstdio>
int x, y;
int main(){
    scanf("%d", &x);
    if(x >> 5 & 1) y |= 1 << 5;
    if(x >> 1 & 1) y |= 1 << 1;
    if(x & 1) y |= 1 << 4;
    if(x >> 4 & 1) y |= 1;
    if(x >> 2 & 1) y |= 1 << 3;
    if(x >> 3 & 1) y |= 1 << 2;
    printf("%d\n", y);
}