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
LL a[200005], ans, dp[200005], res, dep[200005], sz[200005]; 
int head[200005], nxt[400005], cnt, e[400005];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

void dfs1(int x, int pre){
    ans = ans + a[x] * dep[x];
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + 1;
        dfs1(e[i], x);
        sz[x] = sz[x] + sz[e[i]];
    }
    sz[x] += a[x];
}

void dfs2(int x, int pre){
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dp[e[i]] = dp[x] + sz[1] - (sz[e[i]] << 1);
        res = max(dp[e[i]], res);
        dfs2(e[i], x);
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs1(1, 0);dfs2(1, 0);
    fprint(ans + res, 10);
    return 0;
}