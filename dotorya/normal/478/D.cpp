#include <stdio.h>
typedef long long ll;
ll MOD = 1000000007;
ll dp[2][400050]; // red block 
int getH(int x) {
    int st = 1, en = 1000, mi, ans = 0;
    while(st <= en) {
        mi = (st+en)/2;
        if(mi*(mi+1)/2 <= x) {
            ans = mi;
            st = mi+1;
        }
        else en = mi-1;
    }
    return ans;
}
int MAX(int a, int b) {
    if(a<b) return b;
    else return a;
}
int main() {
    int R, G, i, j, H, mx;
    scanf("%d %d", &R, &G);
    H = getH(R+G);
    dp[1][0] = dp[1][1] = 1;
    for(i = 2; i <= H; i++) {
        mx = i*(i+1)/2;
        for(j = 0; j <= mx; j++) {
            dp[i%2][j] = 0;
            dp[i%2][j] += dp[(i-1)%2][j];
            if(j >= i) dp[i%2][j] += dp[(i-1)%2][j-i];
            dp[i%2][j] %= MOD;
        }
    }
    ll ans = 0;
    for(i = MAX(0,H*(H+1)/2-G); i <= R; i++) ans += dp[H%2][i];
    printf("%lld", ans%MOD);
    return 0;
}