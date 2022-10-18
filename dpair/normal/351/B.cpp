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

int n;
int c[3005];

inline int lowbit(int x){return x & -x;}
inline void modify(int x){for (;x <= n;x += lowbit(x)) c[x] ++;}
inline int query(int x){int ret = 0;for (;x;x -= lowbit(x)) ret = ret + c[x];return ret;}

int main(){
    read(n);int ans = 0;
    for (register int i = 1;i <= n;i ++){
        int x;read(x);modify(x);
        ans += i - query(x);
    }
    fprint(ans & 1? (ans << 1) - 1 : (ans << 1), 10);
    return 0;
}