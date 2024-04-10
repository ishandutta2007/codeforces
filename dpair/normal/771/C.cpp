/*
    author: DPair
    language: C++

    description:
    
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

int n, k;

LL dp[200005][6], f[200005][6], ans;

int cnt, e[400005], head[200005], nxt[400005];

inline void add(int &u, int &v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

inline void ins(int &x, int &y){
    f[x][1] += f[y][k];
    dp[x][1] += dp[y][k] + f[y][k];
    for (register int j = 2;j <= k;j ++){
        f[x][j] += f[y][j - 1];
        dp[x][j] += dp[y][j - 1];
    }
}

inline void del(int &x, int &y){
    f[x][1] -= f[y][k];
    dp[x][1] -= dp[y][k] + f[y][k];
    for (register int j = 2;j <= k;j ++){
        f[x][j] -= f[y][j - 1];
        dp[x][j] -= dp[y][j - 1];
    }
}

void dfs(int x, int pre){
    f[x][k] ++;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);ins(x, e[i]);
    }
}

void work(int x, int pre){
    for (register int j = 1;j <= k;j ++) ans = ans + dp[x][j];
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        del(x, e[i]);ins(e[i], x);
        work(e[i], x);
        del(e[i], x);ins(x, e[i]);
    }
}

int main(){
    read(n);read(k);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    work(1, 0);
    fprint(ans >> 1, 10);
}