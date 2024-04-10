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

int n;
LL sig[805][805];
LL a[500005];
inline void add(int x, LL val){
    a[x] += val;
    for (register int i = 1;i <= sqrt(n);i ++) sig[i][x % i] += val;
}

inline LL get(int x, int y){
    if(x <= sqrt(n)) return sig[x][y];
    LL ret = 0;
    for (register int i = y;i <= n;i += x) ret += a[i];
    return ret;
}

int main(){
    n = 500000;
    int Q;read(Q);
    while(Q --){
        int opt, x, y;// x  n
        read(opt);read(x);read(y);
        if(opt == 1) add(x, y);
        else fprint(get(x, y), 10);
    }
    return 0;
}