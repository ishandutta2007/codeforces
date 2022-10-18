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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

struct SegTree{
    int num[2000005], lazy[2000005];
    inline void init(){
        memset(num, 0, sizeof(num));
        memset(lazy, 0, sizeof(lazy));
    }
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    inline void pushup(int rt){num[rt] = mx(num[rt << 1], num[rt << 1 | 1]);}
    inline void update(int rt, int z){
        num[rt] = z;
        lazy[rt] = z;
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
    int query(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return num[rt];
        pushdown(rt);
        int mid = (l + r) >> 1, ret = 0;
        if(x <= mid) chmax(ret, query(LSON, x, y));
        if(y > mid) chmax(ret, query(RSON, x, y));
        return ret;
    }
}t1, t2;

int head[500005], nxt[1000005], e[1000005], cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int dfn[500005], low[500005];
int tot, n;
void dfs(int x, int pre){
    dfn[x] = ++ tot;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
    }
    low[x] = tot;
}

int main(){
    t1.init();t2.init();
    read(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    int Q, t = 0;read(Q);
    while(Q --){
        t ++;
        int opt, x;
        read(opt);read(x);
        if(opt == 1) t1.modify(1, 1, n, dfn[x], low[x], t);
        if(opt == 2) t2.modify(1, 1, n, dfn[x], dfn[x], t);
        if(opt == 3){
            int ret1 = t1.query(1, 1, n, dfn[x], dfn[x]);
            int ret2 = t2.query(1, 1, n, dfn[x], low[x]);
            if(ret1 <= ret2) fprint(0, 10);
            else fprint(1, 10);
        }
    }
}