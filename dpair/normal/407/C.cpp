/*
    author: Mendeleyev
    language: C++

    description:
    I'm Mendeleyev.
*/
#include <cstdio>

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
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){
    read(x);read(args...);
}
#include <algorithm>
using std :: sort;

#define MAXN 100005
int n, m;
int a[MAXN];
typedef long long LL;
const LL MOD = 1e9 + 7;
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
LL fac[MAXN], inv[MAXN];
LL dp[105][MAXN];
const int N = 1e5;
inline void init(){
    fac[0] = 1;
    for (int i = 1;i <= N;++ i) fac[i] = fac[i - 1] * i % MOD;
    inv[N] = ksm(fac[N], MOD - 2);
    for (int i = N;i >= 1;-- i) inv[i - 1] = inv[i] * i % MOD;
}
inline LL C(LL x, LL y){return fac[x] * inv[y] % MOD * inv[x - y] % MOD;}
int main(){
    read(n, m);init();
    for (int i = 1;i <= n;++ i) read(a[i]);
    while(m --){
        int l, r, k;read(l, r, k);
        for (int i = 0;i <= k;++ i) {
            dp[i][l] = (dp[i][l] + C(k, k - i)) % MOD;
            dp[i][r + 1] = (dp[i][r + 1] - C(r - l + 1 + k, k - i) + MOD) % MOD;
        }
    }
    for (int i = 1;i <= n;++ i){
        for (int j = 100;j >= 0;-- j){
            dp[j][i] = (dp[j][i] + dp[j][i - 1] + dp[j + 1][i - 1]) % MOD;
        }
    }
    for (int i = 1;i <= n;++ i) fprint((dp[0][i] + a[i]) % MOD, 32);
    putchar(10);
}