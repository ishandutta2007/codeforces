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

int main(){
    int t;
    read(t);
    while(t --){
        int n;
        int x, sig = 0, mx = -0x3f3f3f3f;
        read(n);
        while(n --) read(x), sig = sig + x, mx = max(mx, x);
        if(mx > sig - mx) printf("T\n");
        else if(sig & 1) printf("T\n");
        else printf("HL\n");
    }
}