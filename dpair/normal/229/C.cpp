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

int n, m;
LL ans;
LL d[1000005];

inline void add(int u, int v){
    LL num = 0;
    d[u] --;num -= d[u];
    d[v] --;num -= d[v];
    num += (n - 1) - d[u] - 1 + (n - 1) - d[v] - 1;
    ans += (num >> 1);
}

int main(){
    read(n);read(m);
    if(n <= 2) return printf("0\n"), 0;
    ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (register int i = 1;i <= n;i ++) d[i] = n - 1;
    while(m --){
        int u, v;read(u);read(v);
        add(u, v);
    }
    fprint(ans, 10);
    return 0;
}