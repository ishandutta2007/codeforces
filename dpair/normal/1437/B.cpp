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
int n;
int a[100005];
inline void work(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        scanf("%1d", &a[i]);
        if(i & 1) a[i] ^= 1;
    }
    int ans1 = 0, ans2 = 0;
    for (register int i = 1;i <= n;i ++){
        if(a[i] && !a[i - 1]) ans1 ++;
    }
    for (register int i = 1;i <= n;i ++) a[i] ^= 1;
    for (register int i = 1;i <= n;i ++){
        if(a[i] && !a[i - 1]) ans2 ++;
    }
    fprint(min(ans1, ans2), 10);
}

int main(){
    int T;read(T);
    while(T --) work();
}