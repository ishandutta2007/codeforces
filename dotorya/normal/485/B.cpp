#include <stdio.h>
typedef long long ll;
int main() {
    int N, i, minx = 1000000001, maxx = -1000000001, miny = 1000000001, maxy = -1000000001, t1, t2;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &t1, &t2);
        if(minx > t1) minx = t1;
        if(maxx < t1) maxx = t1;
        if(miny > t2) miny = t2;
        if(maxy < t2) maxy = t2;
    }
    N = (maxx-minx>maxy-miny)?(maxx-minx):(maxy-miny);
    printf("%lld", (long long)N*N);
    return 0;
}