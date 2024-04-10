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

bitset <65> t[1600005];
int lazy[1600005];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

int head[400005], nxt[800005], e[800005], cnt;
int c[400005];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int dfn[400005], low[400005], dep;
void build(int x, int pre){
    dfn[x] = ++ dep;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        build(e[i], x);
    }
    low[x] = dep;
}

inline void pushup(int rt){t[rt] = (t[rt << 1] | t[rt << 1 | 1]);}
inline void update(int rt, int val){
    t[rt] &= 0;
    t[rt][val] = 1;
    lazy[rt] = val;
}
inline void pushdown(int rt){
    if(lazy[rt]){
        update(rt << 1, lazy[rt]);
        update(rt << 1 | 1, lazy[rt]);
        lazy[rt] = 0;
    }
}

void modify(int rt, int l, int r, int x, int y, int z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}

bitset <65> query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    bitset <65> ret;
    if(x <= mid) ret |= query(LSON, x, y);
    if(y > mid) ret |= query(RSON, x, y);
    return ret;
}
int n, m;
int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(c[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    build(1, 0);
    for (register int i = 1;i <= n;i ++) modify(1, 1, n, dfn[i], dfn[i], c[i]);
    while(m --){
        int opt, x, y;
        read(opt);
        if(opt == 1) read(x), read(y), modify(1, 1, n, dfn[x], low[x], y);
        else read(x), fprint(query(1, 1, n, dfn[x], low[x]).count(), 10);
    }
    return 0;
}