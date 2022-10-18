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

LL dp[25][15][15][5][5];
int n, t;
int main(){
    read(n);read(t);
    for (register int i = 1;i <= 4;i ++){
        for (register int j = i + 1;j <= 4;j ++){
            dp[2][0][0][i][j] = dp[2][0][0][j][i] = 1;
        }
    }
    for (register int k = 3;k <= n;k ++){
        for (register int t1 = 0;t1 <= t;t1 ++){
            for (register int t2 = 0;t2 < t;t2 ++){
                for (register int num = 1;num <= 4;num ++){
                    for (register int i = 1;i <= 4;i ++){
                        for (register int j = 1;j <= 4;j ++){
                            if(i == j) continue;
                            if(j == num) continue;
                            if(j < i && j < num) dp[k][t1 + 1][t2][j][num] += dp[k - 1][t1][t2][i][j];
                            else if(j > i && j > num) dp[k][t1][t2 + 1][j][num] += dp[k - 1][t1][t2][i][j];
                            else dp[k][t1][t2][j][num] += dp[k - 1][t1][t2][i][j];
                        }
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (register int i = 1;i <= 4;i ++){
        for (register int j = 1;j <= 4;j ++){
            ans = ans + dp[n][t][t - 1][i][j];
        }
    }
    fprint(ans, 10);
    return 0;
}