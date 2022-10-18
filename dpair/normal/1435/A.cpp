/*
    author: DPair
    language: C++

    description:
    Duel!
*/
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

int a[105];

int main(){
    int T;
    read(T);
    while(T --){
        int n;read(n);
        for (register int i = 1;i <= n;i ++) read(a[i]);
        for (register int i = 1;i <= (n >> 1);i ++){
            fprint(-a[(i << 1)], 32);
            fprint(a[(i << 1) - 1], 32);
        }
        putchar(10);
    }
}