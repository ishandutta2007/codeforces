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

#define MAXN 100005
int n;
int cnt, head[MAXN], nxt[MAXN << 1], e[MAXN << 1];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int u[MAXN], v[MAXN], val[MAXN];
int dep[MAXN], fa[MAXN][21];

int tot, dfn[MAXN], low[MAXN];
void dfs(int x, int pre){
    dep[x] = dep[pre] + 1;
    dfn[x] = ++ tot;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        fa[e[i]][0] = x;
        for (register int j = 1;j <= 20;j ++) fa[e[i]][j] = fa[fa[e[i]][j - 1]][j - 1];
        dfs(e[i], x);
    }
    low[x] = tot;
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
int c[MAXN];
inline int lowbit(int x){return x & -x;}
inline int query(int x){int ret = 0;for(;x;x -= lowbit(x)) ret += c[x];return ret;}
inline void modify(int x, int y){for(;x <= n;x += lowbit(x)) c[x] += y;}
int main(){
    read(n);
    for (register int i = 1;i < n;i ++){
        read(u[i]);read(v[i]);
        add(u[i], v[i]);add(v[i], u[i]);
    }
    dfs(1, 0);
    int q;read(q);
    while(q --){
        int x, y, opt;read(opt);read(x);
        if(opt == 1){
            if(val[x]){
                val[x] = 0;
                if(dep[u[x]] > dep[v[x]]) x = u[x];
                else x = v[x];
                modify(dfn[x], -1);modify(low[x] + 1, 1);
            }
        }
        if(opt == 2){
            if(!val[x]){
                val[x] = 1;
                if(dep[u[x]] > dep[v[x]]) x = u[x];
                else x = v[x];
                modify(dfn[x], 1);modify(low[x] + 1, -1);
            }
        }
        if(opt == 3){
            read(y);
            int lca = LCA(x, y);
            int num = query(dfn[x]) + query(dfn[y]) - (query(dfn[lca]) << 1);
            int dis = dep[x] + dep[y] - (dep[lca] << 1);
            if(!num) fprint(dis, 10);
            else fprint(-1, 10);
        }
    }
}