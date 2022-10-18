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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int dp[205][6005];
LL a[205];
int a2[205], a5[205], sig[205];
int n, m;
inline int fix2(LL x){
    int ret = 0;
    while(!(x & 1)){
        ret ++;
        x >>= 1;
    }
    return ret;
}

inline int fix5(LL x){
    int ret = 0;
    while(x % 5 == 0){
        ret ++;
        x /= 5;
    }
    return ret;
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);a2[i] = fix2(a[i]);a5[i] = fix5(a[i]);
        sig[i] = sig[i - 1] + a5[i];
    }
    for (register int i = 0;i <= m;i ++){
        for (register int j = 0;j <= sig[n];j ++){
            dp[i][j] = -0x3f3f3f3f;
        }
    }
    dp[0][0] = 0;
    for (register int i = 1;i <= n;i ++){
        for (register int j = mn(i, m);j >= 1;j --){
            for (register int k = a5[i];k <= sig[i];k ++){
                chmax(dp[j][k], dp[j - 1][k - a5[i]] + a2[i]);
            }
        }
    }
    int ans = 0;
    for (register int i = 0;i <= sig[n];i ++) chmax(ans, mn(i, dp[m][i]));
    fprint(ans, 10);
    return 0;
}