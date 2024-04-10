#include <stdio.h>
int main() {
    int X, Y, N, i;
    const int MOD = 1000000007;
    scanf("%d %d %d", &X, &Y, &N);
    N = N % 6;
    int ans;
    if(N == 1) ans = X;
    else if(N == 2) ans = Y;
    else if(N == 3) ans = Y-X;
    else if(N == 4) ans = -X;
    else if(N == 5) ans = -Y;
    else if(N == 0) ans = X-Y;
    ans %= MOD;
    if(ans < 0) ans += MOD;
    printf("%d", ans);
    return 0;
}