#include <bits/stdc++.h>
using namespace std;
#define MOD 7340033
typedef long long LL;
int n, _k;
LL dp[35][1005], f[35][1005];

inline int lowbit(int x){
    int ret = 0;
    while(x > 1 && (x & 1)) ret ++, x >>= 1;
    return ret;
}

int main(){
    for (register int i = 0;i <= 30;i ++) dp[i][0] = f[i][0] = 1;
    for (register int i = 1;i <= 30;i ++){
        for (register int j = 1;j <= 1000;j ++){
            for (register int k = 0;k < j;k ++) dp[i][j] = (dp[i][j] + f[i - 1][k] * f[i - 1][j - k - 1]) % MOD;
            for (register int k = 0;k <= j;k ++) f[i][j] = (f[i][j] + dp[i][k] * dp[i][j - k]) % MOD;
        }
    }
    int ___;
    scanf("%d", &___);
    while(___ --) {
        scanf("%d%d", &n, &_k);
        n = lowbit(n);
        printf("%lld\n", dp[n][_k]);
    }
}