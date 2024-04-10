#pragma GCC optimize(2, 3, "Ofast")
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

int a[1000005];
int n;

inline int cnt(LL x){
    int ret = 0;
    while(x){
        if(x & 1) ret ++;
        x >>= 1;
    }
    return ret;
}
int b[(1 << 22 | 1)];
void ins(int x, int val){
    if(~b[x]) return ;
    b[x] = val;
    // printf("x = %d, val = %d\n", x, val);
    for (register int i = 0;i < 22;i ++){
        if(!(x & (1 << i)) && (!~b[(x ^ (1 << i))])) ins(x ^ (1 << i), val);
    }
}
int main(){
    read(n);
    memset(b, -1, sizeof(b));
    int zenith = 0;
    for (register int i = 0;i < 22;i ++) zenith ^= (1 << i);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);ins(a[i], a[i]);
    }
    for (register int i = 1;i <= n;i ++){
        fprint(b[zenith ^ a[i]], 32);
    }
    putchar(10);return 0;
}