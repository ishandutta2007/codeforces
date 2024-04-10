#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int UI;
typedef pair <int, int> pi;

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

inline ULL calc(ULL x){
    int ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
ULL a, k, s, base;

inline void work(){
    read(a);read(s);k = 0;base = 1;
    ULL num = calc(a);
    while(num > s){
        k += (10 - (a % 10)) * base;
        a += (10 - (a % 10));
        base *= 10;a /= 10;
        num = calc(a);
    }
    fprint(k, 10);
}

int main(){
    int t;
    read(t);
    while(t --) work();
    return 0;
}