//
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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
#define MAXN 200005
int dep[MAXN], dfn[MAXN], low[MAXN], head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1], tot, n, m, a[MAXN];
inline void add(int u, int v){nxt[++ cnt] = head[u];head[u] = cnt;e[cnt] = v;}
void dfs(int x, int pre){dep[x] = dep[pre] + 1;dfn[x] = ++ tot;for (register int i = head[x];i;i = nxt[i]) {if(e[i] == pre) continue;dfs(e[i], x);}low[x] = tot;}
struct Segtree{
    int dat[MAXN << 2], tag[MAXN << 2];
    inline void update(int rt, int l, int r, int w){
        if(l == r) dat[rt] += w;
        tag[rt] += w;
    }
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    inline void pushdown(int rt, int l, int r){
        if(tag[rt]){
            int mid = (l + r) >> 1;
            update(LSON, tag[rt]);update(RSON, tag[rt]);
            tag[rt] = 0;
        }
    }
    void modify(int rt, int l, int r, int x, int y, LL z){
        if(x <= l && r <= y) return update(rt, l, r, z);
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y, z);
        if(y > mid) modify(RSON, x, y, z);
    }
    int query(int rt, int l, int r, int x){
        if(l == r) return dat[rt];
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid) return query(LSON, x);
        else return query(RSON, x);
    }
}t;

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 2;i <= n;i ++) {
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    int x, opt, y;
    while(m --){
        read(opt);read(x);
        if(opt == 1){read(y);t.modify(1, 1, n, dfn[x], low[x], y * (dep[x] & 1? -1 : 1));}
        else fprint(t.query(1, 1, n, dfn[x]) * (dep[x] & 1? -1 : 1) + a[x], 10);
    }
}