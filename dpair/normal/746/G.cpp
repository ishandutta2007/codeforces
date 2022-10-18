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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, m, k;
int a[200005], sig1, sig2;
int con[200005];

int main(){
    read(n);read(m);read(k);
    con[0] = 1;
    for (register int i = 1;i <= m;i ++) read(a[i]), sig2 += a[i] - 1, con[i] = a[i];
    sig2 ++;
    for (register int i = 1;i <= m;i ++){
        int num = mx(a[i] - a[i + 1], 0);
        sig1 += num;
        con[i] -= num;
    }
    if(sig1 > k || sig2 < k) return printf("-1\n"), 0;
    k -= sig1;
    fprint(n, 10);int lst = 1, fst = 0;
    for (register int i = 1;i <= m;i ++){
        k -= con[i - 1];
        ++ fst;
        printf("%d %d\n", fst, lst + 1);
        k ++;
        for (register int j = 2;j <= a[i];j ++){
            if(k < 0){
                ++ fst;
                printf("%d %d\n", fst, lst + j);
                k ++;
            }
            else printf("%d %d\n", fst, lst + j);
        }
        fst = lst;
        lst = a[i] + lst;
    }
}