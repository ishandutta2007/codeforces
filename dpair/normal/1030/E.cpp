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
typedef long long LL;

int n;
int c[300005];
int sig[300005], s[2];
LL ans = 0;
int main(){
    read(n);s[0] ++;
    for (register int i = 1;i <= n;i ++){
        LL x;read(x);
        while(x){
            if(x & 1) c[i] ++;
            x >>= 1;
        }
        sig[i] = sig[i - 1] + c[i];
        ans = ans + s[sig[i] & 1];
        s[sig[i] & 1] ++;
    }
    for (register int i = 1;i <= n;i ++){
        int mx = -0x3f3f3f3f;
        for (register int j = i;j >= 1 && j >= i - 64;j --){
            mx = max(mx, c[j]);
            if(((mx << 1) > (sig[i] - sig[j - 1])) && ((sig[i] & 1) == (sig[j - 1] & 1))) ans --;
        }
    }
    fprint(ans, 10);
    return 0;
}