#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005

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
int h[MAXN];
struct Quest{
    int id, k, nt;
}Q[MAXN];

inline void addQ(int &id, int &k, int &x){
    Q[id].id = id;Q[id].k = k;Q[id].nt = h[x];h[x] = id;
}

int fa[MAXN], head[MAXN], e[MAXN], nxt[MAXN], cnt;

inline void add(int &u, int &v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int tot, t[MAXN * 21], lc[MAXN * 21], rc[MAXN * 21], tp, stk[MAXN * 21];
int n, root[MAXN], ans[MAXN];
inline void pushup(int rt){t[rt] = t[lc[rt]] + t[rc[rt]];}
#define LSON lc[rt], l, mid
#define RSON rc[rt], mid + 1, r

inline int NewNode(){
    if(tp) return stk[tp --];
    else return ++ tot;
}

void modify(int &rt, int l, int r, int x, int y){
    if(!rt) rt = NewNode();
    if(l == r){
        t[rt] ^= y;
        return ;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y);
    else modify(RSON, x, y);
    pushup(rt);
}

int query(int rt, int l, int r, int x){
    if(l == r) return t[rt];
    int mid = (l + r) >> 1;
    if(x <= mid) return query(LSON, x);
    else return query(RSON, x);
}

void merge(int &rt, int l, int r, int RT){
    if(!rt || !RT) {
        rt = rt | RT;
        return ;
    }
    if(l == r){
        t[rt] ^= t[RT];
        stk[++ tp] = RT;
        t[RT] = lc[RT] = rc[RT] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    merge(LSON, lc[RT]);
    merge(RSON, rc[RT]);
    pushup(rt);
    t[RT] = lc[RT] = rc[RT] = 0;
    stk[++ tp] = RT;
}
char a[MAXN];
void work(int x, int dep){
    modify(root[x], 1, n, dep, 1 << (a[x] - 'a'));
    for (register int i = head[x];i;i = nxt[i]){
        work(e[i], dep + 1);
        merge(root[x], 1, n, root[e[i]]);
    }
    for (register int i = h[x];i;i = Q[i].nt){
        Quest q = Q[i];
        int res = query(root[x], 1, n, q.k);
        ans[q.id] = (res == (res & -res));
    }
}

int main(){
    read(n);
    int m;read(m);
    for (register int i = 2;i <= n;i ++){
        read(fa[i]);
        add(fa[i], i);
    }
    scanf("%s", a + 1);
    for (register int i = 1;i <= m;i ++){
        int x, k;read(x);read(k);
        addQ(i, k, x);
    }
    work(1, 1);
    for (register int i = 1;i <= m;i ++) {
        printf("%s\n", ans[i]? "Yes" : "No");
    }
    return 0;
}