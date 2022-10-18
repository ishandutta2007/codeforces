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

int head[100005], nxt[200005], e[200005], cnt;
int ans[100005];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int dep[100005], fa[100005][21];

void dfs1(int x, int pre){
    dep[x] = dep[pre] + 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(pre == e[i]) continue;
        fa[e[i]][0] = x;
        for (register int j = 1;j <= 20;j ++) fa[e[i]][j] = fa[fa[e[i]][j - 1]][j - 1];
        dfs1(e[i], x);
    }
}

void dfs2(int x, int pre){
    for (register int i = head[x];i;i = nxt[i]){
        if(pre == e[i]) continue;
        dfs2(e[i], x);
        ans[x] += ans[e[i]];
    }
}

inline int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for (register int i = 20;i >= 0;i --){
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        if(dep[x] == dep[y]) break;
    }
    if(x == y) return x;
    for (register int i = 20;i >= 0;i --){
        if(fa[x][i] ^ fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int n, k;
int a[100005], b[100005];
int main(){
    read(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
        a[i] = u;b[i] = v;
    }
    dfs1(1, 0);
    read(k);
    while(k --){
        int u, v;read(u);read(v);
        int lca = LCA(u, v);
        ans[u] ++;ans[v] ++;ans[lca] -= 2;
    }
    dfs2(1, 0);
    for (register int i = 1;i < n;i ++){
        if(dep[a[i]] < dep[b[i]]) swap(a[i], b[i]);
        fprint(ans[a[i]], 32);
    }
    putchar(10);
}