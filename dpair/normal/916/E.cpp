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

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
#define MAXN 100005
int root, n, q;
int dep[MAXN], fa[MAXN][21], cnt, head[MAXN], e[MAXN << 1], nxt[MAXN << 1], dfn[MAXN], low[MAXN], tot;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int a[MAXN], re[MAXN];
void dfs(int x, int pre){
    dep[x] = dep[pre] + 1;
    dfn[x] = ++ tot;re[dfn[x]] = a[x];
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

inline int lca(int x, int y){
    int u = LCA(x, y), v = LCA(x, root), w = LCA(y, root);
    if(dep[u] >= dep[v] && dep[u] >= dep[w]) return u;
    if(dep[v] >= dep[u] && dep[v] >= dep[w]) return v;
    if(dep[w] >= dep[v] && dep[w] >= dep[u]) return w;
}

LL t[MAXN << 2], lazy[MAXN << 2];
inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
inline void update(int rt, int l, int r, LL w){
    t[rt] += 1ll * (r - l + 1) * w;
    lazy[rt] += w;
}
inline void pushdown(int rt, int l, int r){
    if(lazy[rt]){
        int mid = (l + r) >> 1;
        update(LSON, lazy[rt]);
        update(RSON, lazy[rt]);
        lazy[rt] = 0;
    }
}
void build(int rt, int l, int r){
    if(l == r){
        t[rt] = re[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
void modify(int rt, int l, int r, int x, int y, LL z){
    if(x <= l && r <= y) return update(rt, l, r, z);
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
LL query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;LL ret = 0;
    if(x <= mid) ret = ret + query(LSON, x, y);
    if(y > mid) ret = ret + query(RSON, x, y);
    return ret;
}
int main(){
    read(n);read(q);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);root = 1;
    build(1, 1, n);
    while(q --){
        int opt, u, v, x;read(opt);read(u);
        if(opt == 1) root = u;
        if(opt == 2){
            read(v);read(x);
            int w = lca(u, v);
            if(root == w) modify(1, 1, n, 1, n, x);
            else if(dfn[root] >= dfn[w] && dfn[root] <= low[w]){
                int cur = root;
                for (register int i = 20;i >= 0;i --) if(dep[fa[cur][i]] > dep[w]) cur = fa[cur][i];
                modify(1, 1, n, 1, n, x);
                modify(1, 1, n, dfn[cur], low[cur], -x);
            }
            else modify(1, 1, n, dfn[w], low[w], x);
        }
        if(opt == 3){
            LL ret = 0;
            if(root == u) ret = query(1, 1, n, 1, n);
            else if(dfn[root] >= dfn[u] && dfn[root] <= low[u]){
                int cur = root;
                for (register int i = 20;i >= 0;i --) if(dep[fa[cur][i]] > dep[u]) cur = fa[cur][i];
                ret = query(1, 1, n, 1, n);
                ret -= query(1, 1, n, dfn[cur], low[cur]);
            }
            else ret = query(1, 1, n, dfn[u], low[u]);
            fprint(ret, 10);
        }
    }
}