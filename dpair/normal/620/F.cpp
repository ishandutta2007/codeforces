#include <cstdio>
#include <algorithm>
using std :: sort;
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
#define MAXN 50005

int n, m;

int dp[MAXN], a[MAXN];
int l[MAXN], r[MAXN], ans[MAXN];
int val[MAXN << 5];
inline void init(){
    for (register int i = 1;i <= 1000000;i ++) val[i] = val[i - 1] ^ i;
}
int main(){
    read(n);read(m);
    init();
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
    }
    for (register int i = 1;i <= m;i ++){
        read(l[i]);read(r[i]);
    }
    for (register int i = 1;i <= n;i ++){
        dp[i] = a[i];
        for (register int j = i + 1;j <= n;j ++){
            dp[j] = dp[j - 1];
            if(a[j] <= a[i]){
                chmax(dp[j], val[a[i]] ^ val[a[j] - 1]);
            }
            else{
                chmax(dp[j], val[a[j]] ^ val[a[i] - 1]);
            }
        }
        for (register int j = 1;j <= m;j ++){
            if(i >= l[j] && i <= r[j]){
                chmax(ans[j], dp[r[j]]);
            }
        }
    }
    for (register int i = 1;i <= m;i ++) fprint(ans[i], 10);
}