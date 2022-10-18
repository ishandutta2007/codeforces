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
LL x, y;
inline void MAIN(){
    read(x);read(y);
    if(x % y != 0) {
        fprint(x, 10);
        return ;
    }
    else{
        LL mem = x, ans = 1;
        for (register LL i = 2;i * i <= y;i ++){
            x = mem;
            if(y % i == 0){
                while(x % i == 0) x /= i;
                while(y % i == 0){
                    y /= i;
                    x *= i;
                }
                x /= i;
                chmax(ans, x);
            }
        }
        x = mem;
        if(y > 1) {
            while(x % y == 0) x /= y;
            chmax(ans, x);
        }
        // if(y > 1) chmax(ans, x / y);
        fprint(ans, 10);
    }
}

int main(){
    int T;read(T);
    while(T --) MAIN();
}