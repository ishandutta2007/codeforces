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
int h[MAXN];
struct Quest{
    int id, k, nt;
}Q[MAXN];

inline void addQ(int &id, int &k, int &x){
    Q[id].id = id;Q[id].k = k;Q[id].nt = h[x];h[x] = id;
}
bool vis[MAXN];
int fa[MAXN], head[MAXN], e[MAXN], nxt[MAXN], cnt;

inline void add(int &u, int &v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

set <string> t[MAXN * 21];
int tot, lc[MAXN * 21], rc[MAXN * 21];
int n, root[MAXN], ans[MAXN];
#define LSON lc[rt], l, mid
#define RSON rc[rt], mid + 1, r

void modify(int &rt, int l, int r, int x, string &y){
    if(x > r) return ;
    if(!rt) rt = ++ tot;
    if(l == r){
        t[rt].insert(y);
        return ;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y);
    else modify(RSON, x, y);
}

int query(int rt, int l, int r, int x){
    if(x > r) return 0;
    if(!rt) return 0;
    if(l == r) return t[rt].size();
    int mid = (l + r) >> 1;
    if(x <= mid) return query(LSON, x);
    else return query(RSON, x);
}

inline bool Merge(int x, int y){
    bool ck = 0;
    if(t[x].size() > t[y].size()) swap(x, y), ck = 1;
    for (auto it = t[x].begin();it != t[x].end();++ it){
        t[y].insert(*it);
    }
    set <string> tmp;swap(tmp, t[x]);
    return ck;
}

void merge(int &rt, int l, int r, int RT){
    if(!rt || !RT) {
        rt = rt | RT;
        return ;
    }
    if(l == r){
        if(!Merge(rt, RT)) rt = RT;
        return ;
    }
    int mid = (l + r) >> 1;
    merge(LSON, lc[RT]);
    merge(RSON, rc[RT]);
}
string a[MAXN];
void work(int x, int dep){
    vis[x] = 1;
    modify(root[x], 1, n, dep, a[x]);
    for (register int i = head[x];i;i = nxt[i]){
        work(e[i], dep + 1);
        merge(root[x], 1, n, root[e[i]]);
    }
    for (register int i = h[x];i;i = Q[i].nt){
        Quest q = Q[i];
        int res = query(root[x], 1, n, dep + q.k);
        ans[q.id] = res;
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        cin >> a[i];
        read(fa[i]);
        if(fa[i]) add(fa[i], i);
    }
    int m;read(m);
    for (register int i = 1;i <= m;i ++){
        int x, k;read(x);read(k);
        addQ(i, k, x);
    }
    for (register int i = 1;i <= n;i ++) {
        if(!vis[i]) work(i, 1);
    }
    for (register int i = 1;i <= m;i ++) fprint(ans[i], 10);
    return 0;
}