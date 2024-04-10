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

inline LL calc(LL x){
    LL ret = 0, i;
    for (i = 1;(i << 1) <= x;i *= 10){
        ret += i;
    }
    if(x - i >= 0) ret += (x - i + 1);
    return ret;
}
int n, k;
double p[1005], dp[1005];
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        LL l, r;read(l);read(r);
        p[i] = (double)(calc(r) - calc(l - 1)) / (double)(r - l + 1);
    }
    dp[0] = 1;
    read(k);
    for (register int i = 1;i <= n;i ++){
        for (register int j = i;j >= 0;j --){
            dp[j] = dp[j] * (1 - p[i]);
            if(j) dp[j] += dp[j - 1] * p[i];
        }
    }
    double ans = 0;
    k = (n * k / 100 + ((n * k) % 100? 1 : 0));
    for (register int i = k;i <= n;i ++) ans += dp[i];
    printf("%.15f\n", ans);
    return 0;
}