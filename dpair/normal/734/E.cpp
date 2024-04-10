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

int n, head[200005], nxt[400005], e[400005], val[400005], cnt;
int a[200005];
inline void add(int u, int v, int w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
}
int dep[200005], deep;
void dfs(int x, int pre){
    if(dep[x] > dep[deep]) deep = x;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dep[e[i]] = dep[x] + val[i];
        dfs(e[i], x);
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v, a[u] ^ a[v]);add(v, u, a[u] ^ a[v]);
    }
    deep = 1;
    dfs(1, 0);
    dep[deep] = 0;
    dfs(deep, 0);
    fprint((dep[deep] + 1) >> 1, 10);
    return 0;
}