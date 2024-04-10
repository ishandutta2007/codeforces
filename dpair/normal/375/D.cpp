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

int n, m, block;
int a[100005], t[100005];

int dfn[100005], low[100005], nxt[200005], e[200005], head[100005], ctt;

inline void add(int u, int v){
    nxt[++ ctt] = head[u];
    head[u] = ctt;
    e[ctt] = v;
}
int lin_toto;
void dfs(int x, int pre){
    dfn[x] = ++ lin_toto;
    a[dfn[x]] = t[x];
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
    }
    low[x] = lin_toto;
}

inline int idb(int x){return (x / block);}

struct QUEST{
    int l, r, k;
    int id;
    inline bool operator <(const QUEST &tmp) const{
        return (idb(l) ^ idb(tmp.l)) ?(l < tmp.l) : ((idb(l) & 1)? r < tmp.r : r > tmp.r);
    }
}q[100005];

int cnt[100005], ans[100005];
int ret[100005];
inline void add(int x){
    ans[++ cnt[x]] ++;
}
inline void del(int x){
    ans[cnt[x] --] --;
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;++ i) read(t[i]);
    block = sqrt(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    dfs(1, 0);
    for (register int i = 1;i <= m;++ i) {read(q[i].l);read(q[i].k);q[i].id = i;q[i].r = low[q[i].l];q[i].l = dfn[q[i].l];}
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = l - 1;
    for (register int i = 1;i <= m;++ i){
        // printf("i = %d, q[i].l = %d, q[i].r = %d, q[i].k = %d, q[i].id = %d\n", i, q[i].l, q[i].r, q[i].k, q[i].id);
        while(l > q[i].l) add(a[-- l]);
        while(r < q[i].r) add(a[++ r]);
        while(l < q[i].l) del(a[l ++]);
        while(r > q[i].r) del(a[r --]);
        ret[q[i].id] = ans[q[i].k];
    }
    for (register int i = 1;i <= m;++ i) fprint(ret[i], 10);
    return 0;
}