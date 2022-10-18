//
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
#define MAXN 200005

int n, m;
int dfn[MAXN], low[MAXN], head[MAXN], e[MAXN], cnt, nxt[MAXN], re[MAXN];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int tot;

void dfs(int x){
    dfn[x] = ++ tot;
    re[tot] = x;
    for (register int i = head[x];i;i = nxt[i]) dfs(e[i]);
    low[x] = tot;
}
int a[MAXN];
struct Segtree{
    int dat[MAXN << 2], tag[MAXN << 2];
    inline void pushup(int rt){dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];}
    inline void update(int rt, int l, int r){
        dat[rt] = (r - l + 1 - dat[rt]);
        tag[rt] ^= 1;
    }
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    inline void pushdown(int rt, int l, int r){
        if(tag[rt]){
            int mid = (l + r) >> 1;
            update(LSON);update(RSON);
            tag[rt] = 0;
        }
    }
    void build(int rt, int l, int r){
        tag[rt] = 0;
        if(l == r){
            dat[rt] = a[re[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    void modify(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return update(rt, l, r);
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y);
        if(y > mid) modify(RSON, x, y);
        pushup(rt);
    }
    int query(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return dat[rt];
        pushdown(rt, l, r);
        int mid = (l + r) >> 1, ret = 0;
        if(x <= mid) ret += query(LSON, x, y);
        if(y > mid) ret += query(RSON, x, y);
        return ret;
    }
}t;

int main(){
    read(n);
    for (register int i = 2;i <= n;i ++) {
        int fa;read(fa);add(fa, i);
    }
    for (register int i = 1;i <= n;i ++) read(a[i]);
    dfs(1);
    t.build(1, 1, n);
    read(m);
    char opt[10];
    int x;
    while(m --){
        scanf("%s", opt);
        read(x);
        if(opt[0] == 'g') fprint(t.query(1, 1, n, dfn[x], low[x]), 10);
        else t.modify(1, 1, n, dfn[x], low[x]);
    }
}