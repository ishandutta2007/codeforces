#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
#define MOD 998244353
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}

int n;
LL p[200005], dp[200005];
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(p[i]);
        dp[i] = 100ll * (dp[i - 1] + 1) % MOD * ksm(p[i], MOD - 2) % MOD;
    }
    fprint(dp[n], 10);
    return 0;
}