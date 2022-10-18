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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
#define MAXN 100005
int n, m;
int a[MAXN];
LL b[MAXN];
LL x, y;
LL dp[MAXN];
inline void work(){
    memset(dp, 128, sizeof(dp));
    LL ans = 0;
    int fst = 0, sec = 0;
    dp[0] = 0;
    for (register int i = 1;i <= n;i ++){
        LL num;
        if(a[i] == fst) num = dp[sec];
        else num = dp[fst];
        chmax(dp[a[i]], mx(dp[a[i]] + b[i] * x, num + b[i] * y));
        chmax(ans, dp[a[i]]);
        if(a[i] == fst) continue;
        if(dp[a[i]] >= dp[fst]){
            sec = fst;
            fst = a[i];
        }
        else if(dp[a[i]] >= dp[sec]){
            sec = a[i];
        }
    }
    fprint(ans, 10);
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(b[i]);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    while(m --){read(x);read(y);work();}
    return 0;
}