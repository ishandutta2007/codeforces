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

int dp[2][305][305];
int a[305][305], n;
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        dp[1][0][i] = dp[1][i][0] = dp[0][0][i] = dp[0][i][0] = -0x3f3f3f3f;
        for (register int j = 1;j <= n;j ++){
            read(a[i][j]);
            dp[1][i][j] = dp[0][i][j] = -0x3f3f3f3f;
        }
    }
    dp[0][1][1] = a[1][1];dp[0][0][0] = dp[1][0][0] = -0x3f3f3f3f;
    for (register int k = 3;k <= (n << 1);k ++){
        for (register int i = mn(k - 1, n);i >= 1 && k - i <= n;i --){
            for (register int j = i;j >= 1 && k - j <= n;j --){
                dp[k & 1][i][j] = mx(mx(dp[(k & 1) ^ 1][i][j], dp[(k & 1) ^ 1][i - 1][j]), mx(dp[(k & 1) ^ 1][i][j - 1], dp[(k & 1) ^ 1][i - 1][j - 1])) + a[i][k - i] + a[j][k - j];
                if(i == j) dp[k & 1][i][j] -= a[i][k - i];
                // printf("i = %d, j = %d, dp[i][j] = %d\n", i, j, dp[k & 1][i][j]);
            }
        }
    }
    fprint(dp[0][n][n], 10);
    return 0;
}