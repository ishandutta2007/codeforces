#include <bits/stdc++.h>
using namespace std;

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

int n, d;

int dp[30005][1005], a[30005], ans;
int zero = 500, x;
int main(){
    memset(dp, 128, sizeof(dp));
    read(n);read(d);
    for (register int i = 1;i <= n;i ++){
        read(x);a[x] ++;
    }
    ans = dp[d][zero] = a[d];//j -> d - zero + j 
    for (register int i = d + 1;i <= x;i ++){
        for (register int j = 1;j < (zero << 1);j ++){
            int skip = (d + j - zero);
            if(skip <= 0 || i - skip < d || i - skip > x) continue;
            dp[i][j] = mx(dp[i - skip][j + 1], mx(dp[i - skip][j], dp[i - skip][j - 1])) + a[i];
            chmax(ans, dp[i][j]);
            // printf("i = %d, skip = %d, dp[i][j] = %d\n", i, skip, dp[i][j]);
        }
    }
    fprint(ans, 10);
    return 0;
}