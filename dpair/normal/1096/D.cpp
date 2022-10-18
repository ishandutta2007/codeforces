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


int n;
int s[100005];
int mem[256];
LL dp[5];

int main(){
    read(n);
    mem['h'] = 1;mem['a'] = 2;mem['r'] = 3;mem['d'] = 4;
    for (register int i = 1;i <= n;i ++) s[i] = mem[getchar()];
    dp[1] = dp[2] = dp[3] = -1;
    int i = 0;
    while(n --){
        int w;read(w);
        if(s[++ i]){
            if(!~dp[s[i]]) dp[s[i]] = dp[s[i] - 1];
            else chmin(dp[s[i]], dp[s[i] - 1]);
            if(~dp[s[i] - 1]) dp[s[i] - 1] = dp[s[i] - 1] + w;
        }
    }
    fprint(mx(0ll, mn(mn(dp[0], dp[1]), mn(dp[2], dp[3]))), 10);
    return 0;
}