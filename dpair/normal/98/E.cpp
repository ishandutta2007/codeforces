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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

double dp[1005][1005];

double dfs(int n, int m){
    if(!n) return 1.0 / (m + 1);
    if(!m) return 1.0;
    if(dp[n][m]) return dp[n][m];
    double A = ((1.0 * m) / (1.0 * (m + 1))) * (1.0 - dfs(m - 1, n));
    double B = (1.0 / (1.0 * (m + 1))) + A;
    double C = 1.0;double D = 1.0 - dfs(m, n - 1);
    double p = (C - D) / (B + C - A - D);
    return dp[n][m] = A * p + C * (1 - p);
}

int main(){
    int n, m;
    read(n);read(m);
    double ans = dfs(n, m);
    printf("%.9lf %.9lf\n", ans, 1 - ans);
}