#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD 1000000007
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

int n, m, k;
LL dp[1005][1005];
int main(){
    read(n);read(m);read(k);
    if(n < m) swap(n, m);
    if((k << 1 | 1) > n) return printf("0\n"), 0;
    for (register int i = 1;i <= n;i ++) dp[i][0] = 1;
    for (register int t = 1;t <= k;t ++){
        for (register int i = (t << 1 | 1);i <= n;i ++){
            for (register int j = ((t - 1) << 1 | 1);j <= i - 2;j ++){
                dp[i][t] = (dp[i][t] + dp[j][t - 1] * (i - j - 1)) % MOD;
            }
        }
    }
    fprint(dp[n][k] * dp[m][k] % MOD, 10);
    return 0;
}