#include <stdio.h>
#include <algorithm>
long long d[5];
int main() {
    scanf("%lld %lld %lld", &d[0], &d[1], &d[2]);
    std::sort(d, d+3);
    if(d[2] >= 2*(d[0]+d[1])) printf("%lld", d[0]+d[1]);
    else printf("%lld", (d[0]+d[1]+d[2])/3);
    return 0;
}