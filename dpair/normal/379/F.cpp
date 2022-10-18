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

int n, m;
int fa[1000005][21];
int rt1 = 2, rt2 = 3, ans = 2;
int dep[1000005];
inline int LCA(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for (register int i = 20;i >= 0;i --){
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        if(dep[x] == dep[y]) break;
    }
    if(x == y) return x;
    for (register int i = 20;i >= 0;i --){
        if(fa[x][i] ^ fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
inline int dist(int u, int v){
    int lca = LCA(u, v);
    // fprint(lca, 10);
    return dep[u] + dep[v] - (dep[lca] << 1);
}
int main(){
    read(m);n = 4;
    dep[1] = 1;dep[2] = dep[3] = dep[4] = 2;
    fa[2][0] = fa[3][0] = fa[4][0] = 1;
    while(m --){
        int u;read(u);
        fa[++ n][0] = u;dep[n] = dep[u] + 1;
        for (register int i = 1;i <= 20;i ++) fa[n][i] = fa[fa[n][i - 1]][i - 1];
        fa[++ n][0] = u;dep[n] = dep[u] + 1;
        for (register int i = 1;i <= 20;i ++) fa[n][i] = fa[fa[n][i - 1]][i - 1];
        if(dist(n, rt1) == ans + 1){
            ans ++;
            rt2 = n;
        }
        else if(dist(n, rt2) == ans + 1){
            ans ++;
            rt1 = n;
        }
        fprint(ans, 10);
    }
}