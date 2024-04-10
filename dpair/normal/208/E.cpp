#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

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

struct Quest{
    int id, k;
    Quest (int tmp1, int tmp2) : id(tmp1), k(tmp2){}
};
vector <Quest> vec[MAXN];
bool vis[MAXN];
int fa[MAXN][21], dep[MAXN], head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

void dfs(int x, int pre){
    vis[x] = 1;
    dep[x] = dep[pre] + 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        fa[e[i]][0] = x;
        for (register int j = 1;j <= 20;j ++) fa[e[i]][j] = fa[fa[e[i]][j - 1]][j - 1];
        dfs(e[i], x);
    }
}

inline int k_th(int x, int k){
    int cur = 0;
    while(k){
        if(k & 1) x = fa[x][cur];
        cur ++;
        k >>= 1;
    }
    return x;
}

int tot, t[MAXN * 33], lc[MAXN * 33], rc[MAXN * 33];
int n, root[MAXN], ans[MAXN];
inline void pushup(int rt){t[rt] = t[lc[rt]] + t[rc[rt]];}
#define LSON lc[rt], l, mid
#define RSON rc[rt], mid + 1, r

void modify(int &rt, int l, int r, int x){
    if(!rt) rt = ++ tot;
    if(l == r){
        t[rt] ++;
        return ;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x);
    else modify(RSON, x);
    pushup(rt);
}

int query(int rt, int l, int r, int x){
    if(!rt) return 0;
    if(l == r) return t[rt];
    int mid = (l + r) >> 1;
    if(x <= mid) return query(LSON, x);
    else return query(RSON, x);
}

int merge(int rt, int l, int r, int RT){
    if(!rt) return RT;
    if(!RT) return rt;
    if(l == r){t[rt] += t[RT];return rt;}
    int mid = (l + r) >> 1;
    lc[rt] = merge(LSON, lc[RT]);
    rc[rt] = merge(RSON, rc[RT]);
    pushup(rt);return rt;
}

void work(int x, int pre){
    vis[x] = 0;
    modify(root[x], 1, n, dep[x]);
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        work(e[i], x);
        root[x] = merge(root[x], 1, n, root[e[i]]);
    }
    for (register int i = 0;i < vec[x].size();i ++){
        Quest q = vec[x][i];
        ans[q.id] = query(root[x], 1, n, dep[x] + q.k) - 1;
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(fa[i][0]);
        add(fa[i][0], i);
    }
    for (register int i = 1;i <= n;i ++){
        if(!vis[i]) dfs(i, 0);
    }
    int m;read(m);
    for (register int i = 1;i <= m;i ++){
        int x, k;read(x);read(k);
        if(dep[x] > k){
            vec[k_th(x, k)].push_back(Quest(i, k));
        }
    }
    for (register int i = 1;i <= n;i ++){
        if(vis[i]) work(i, 0);
    }
    for (register int i = 1;i <= m;i ++) fprint(ans[i], 32);
    putchar(10);
    return 0;
}