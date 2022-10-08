#include <stdio.h>
#include <algorithm>
int a[1050];
int main() {
    int N, L, i, ans = 0;
    scanf("%d %d", &N, &L);
    for(i = 1; i <= N; i++) scanf("%d", &a[i]);
    std::sort(a+1, a+N+1);
    for(i = 1; i <= N-1; i++) {
        if(ans < a[i+1]-a[i]) ans = a[i+1]-a[i];
    }
    if(ans < a[1]*2) ans = a[1]*2;
    if(ans < (L-a[N])*2) ans = (L-a[N])*2;
    printf("%lf", 1.0*ans/2);
    return 0;
}