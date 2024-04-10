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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
#define MAXN 1000005
struct DPair{
    int val, id;
    inline bool operator > (const DPair &tmp) const{
        return val > tmp.val || (val == tmp.val && id < tmp.id);
    }
}t[MAXN * 25];

int lc[MAXN * 25], rc[MAXN * 25], root[MAXN], tot;

inline void pushup(int rt){t[rt] = mx(t[lc[rt]], t[rc[rt]]);}
#define LSON lc[rt], l, mid
#define RSON rc[rt], mid + 1, r
void modify(int &rt, int l, int r, int x){
    if(!rt) rt = ++ tot;
    if(l == r){
        t[rt].val ++;
        t[rt].id = x;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x);
    else modify(RSON, x);
    pushup(rt);
}

int merge(int rt, int RT, int l, int r){
    if(!rt) return RT;
    if(!RT) return rt;
    if(l == r){t[rt].val += t[RT].val;t[rt].id = l;return rt;}
    int mid = (l + r) >> 1;
    lc[rt] = merge(lc[rt], lc[RT], l, mid);
    rc[rt] = merge(rc[rt], rc[RT], mid + 1, r);
    pushup(rt);return rt;
}
int head[MAXN], nxt[MAXN << 1], e[MAXN << 1], cnt;
int n, dep[MAXN];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int ans[MAXN];
void dfs(int x, int pre){
    dep[x] = dep[pre] + 1;
    modify(root[x], 1, n, dep[x]);
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
        root[x] = merge(root[x], root[e[i]], 1, n);
    }
    ans[x] = t[root[x]].id - dep[x];
}

int main(){
    read(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    for (register int i = 1;i <= n;i ++) fprint(ans[i], 10);
    return 0;
}