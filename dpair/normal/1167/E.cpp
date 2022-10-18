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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, x;
int l[1000005], r[1000005];
int L[1000005][21], R[1000005][21];
int Luogu[1000005];
int RL, RR;
inline int getL(int ll, int rr){
    if(rr < ll) return 0x3f3f3f3f;
    int num = Luogu[rr - ll + 1];
    return mn(L[ll][num], L[rr - (1 << num) + 1][num]);
}

inline int getR(int ll, int rr){
    if(rr < ll) return -0x3f3f3f3f;
    int num = Luogu[rr - ll + 1];
    return mx(R[ll][num], R[rr - (1 << num) + 1][num]);
}

int main(){
    read(n);read(x);
    for (register int i = 1;i <= n;i ++){
        int a;read(a);
        r[a] = i;
        if(!l[a]) l[a] = i;
    }
    for (register int i = 1;i <= x;i ++){
        if(!l[i]) l[i] = 0x3f3f3f3f;
        if(!r[i]) r[i] = -0x3f3f3f3f;
        L[i][0] = l[i];R[i][0] = r[i];
    }
    for (register int i = 1;i <= 20;i ++){
        for (register int j = 1;j + (1 << i) - 1 <= x;j ++){
            L[j][i] = mn(L[j][i - 1], L[j + (1 << (i - 1))][i - 1]);
            R[j][i] = mx(R[j][i - 1], R[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (register int i = 2;i <= x;i ++) Luogu[i] = Luogu[i >> 1] + 1;
    RL = 1;
    while(RL < x && l[RL] > getR(1, RL - 1)) RL ++;
    RR = x;
    while(RR > 1 && r[RR] < getL(RR + 1, x)) RR --;
    int it = RR + 1;
    long long ans = 0;
    for (register int i = 0;i < RL;i ++){
        while(it <= x && (getL(it, x) <= getR(1, i) || it <= (i + 1))) it ++;
        ans += x - it + 2;
        // printf("i = %d, it = %d, RL = %d, RR = %d\n", i, it, RL, RR);
    }
    fprint(ans, 10);
    return 0;
}