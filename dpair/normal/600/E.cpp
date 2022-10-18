#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int n;
int sz[100005];
int num[100005];

int cnt, nxt[200005], e[200005], head[100005], ret[100005], col[100005];
int son[100005];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

void build(int x, int pre){
    sz[x] ++;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        build(e[i], x);
        if(!son[x] || sz[son[x]] < sz[e[i]]) son[x] = e[i];
        sz[x] += sz[e[i]];
    }
}

void resume(int x, int pre){
    num[col[x]] --;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        resume(e[i], x);
    }
}

int mx, res;

void getans(int x, int pre, int gson){
    num[col[x]] ++;
    if(num[col[x]] > mx){
        res = col[x];
        mx = num[col[x]];
    }
    else if(num[col[x]] == mx) res += col[x];
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre || e[i] == gson) continue;
        getans(e[i], x, gson);
    }
}

void dfs(int x, int pre){
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre || e[i] == son[x]) continue;
        dfs(e[i], x);
        resume(e[i], x);
        mx = res = 0;
    }
    if(son[x]) dfs(son[x], x);
    getans(x, pre, son[x]);
    ret[x] = res;
}

signed main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(col[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    build(1, 0);
    dfs(1, 0);
    for (register int i = 1;i <= n;i ++) fprint(ret[i], 32);
    putchar(10);
}