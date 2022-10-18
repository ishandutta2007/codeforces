/*
    author: DPair
    language: C++

    description:
    Duel!
*/
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

LL a, b, c, d;
int main(){
    int T;
    read(T);
    while(T --){
        read(a);read(b);read(c);read(d);
        if(b * c < a) {fprint(-1, 10);continue;}
        if(d >= c) {fprint(a, 10);continue;}
        LL num = a / b;//num
        LL tmp = num / d + 1;//
        num = (tmp - 1) * d;//
        fprint(a * tmp - ((num * tmp * b) >> 1), 10);
    }
}