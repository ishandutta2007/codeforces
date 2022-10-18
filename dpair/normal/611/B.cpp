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

LL dp[105][2][2][2], l, r;
int len, a[105];
LL dfs(int stp, bool zenith, bool zero, bool app){
    // printf("stp = %d, zenith = %d, zero = %d, app = %d\n", stp, zenith, zero, app);
    if(!stp) return app;
    if(~dp[stp][zenith][zero][app]) return dp[stp][zenith][zero][app];
    int Zenith = zenith? a[stp] : 1;
    LL ret = 0;
    for (register int i = 0;i <= Zenith;i ++){
        if(app && !i) continue;
        ret = ret + dfs(stp - 1, zenith && i == Zenith, zero && !i, app || (!i && !zero));
    }
    return dp[stp][zenith][zero][app] = ret;
}

inline LL work(LL x){
    memset(dp, -1, sizeof(dp));
    len = 0;
    while(x){
        a[++ len] = (x & 1);
        x >>= 1;
    }
    return dfs(len, 1, 1, 0);
}

int main(){
    read(l);read(r);
    // work(l);
    fprint(work(r) - work(l - 1), 10);
}