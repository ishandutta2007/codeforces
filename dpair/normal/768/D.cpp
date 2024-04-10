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

double dp[1005];
int ans[1005];
int n, q, num;

int main(){
    read(n);
    dp[0] = 1;
    int t = 0;
    while(num <= 1000){
        t ++;
        for (register int i = n;i >= 0;i --){
            dp[i] = dp[i] * ((double)i / (double)n);
            if(i) dp[i] = dp[i] + dp[i - 1] * (double)(n - i + 1) / (double)(n);
        }
        while((double)num / 2000.0 <= dp[n]) {
            ans[num] = t;
            num ++;
            if(num > 1000) break;
        }
    }
    
    read(q);
    while(q --){
        int x;read(x);
        fprint(ans[x], 10);
    }
}