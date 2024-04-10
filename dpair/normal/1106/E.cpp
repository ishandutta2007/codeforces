#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pi;
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

int n, m, k;

struct Redbag{
    int l, r;
    int val, d;
    inline bool operator < (const Redbag &tmp) const{
        return val < tmp.val || (val == tmp.val && d < tmp.d);
    }
}q[100005];

pi t[400005], lazy[400005], a[100005];

inline void pushup(int rt){
    if(t[rt << 1] != t[rt << 1 | 1]) t[rt] = make_pair(0, 0);
    else t[rt] = t[rt << 1];
}

inline void update(int rt, pi z){
    t[rt] = z;
    lazy[rt] = z;
}

inline void pushdown(int rt){
    if(lazy[rt].first){
        update(rt << 1, lazy[rt]);
        update(rt << 1 | 1, lazy[rt]);
        lazy[rt] = make_pair(0, 0);
    }
}

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

void modify(int rt, int l, int r, int x, int y, pi z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt); 
}

pi query(int rt, int l, int r, int x){
    if(t[rt].first) return t[rt];
    if(l == r && l == x) return t[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) return query(LSON, x);
    else return query(RSON, x);
}

LL dp[100005][205];

LL dfs(int x, int y){
    if(y < 0) return 0x3f3f3f3f3f3f3f3f;
    if(x > n) return 0;
    if(~dp[x][y]) return dp[x][y];
    if(!a[x].first) return dp[x][y] = dfs(x + 1, y);
    return dp[x][y] = min(dfs(x + 1, y - 1), dfs(a[x].second + 1, y) + a[x].first);
}


int main(){
    read(n);read(m);read(k);
    for (register int i = 1;i <= k;i ++){
        read(q[i].l);read(q[i].r);
        read(q[i].d);read(q[i].val);
    }
    sort(q + 1, q + k + 1);
    for (register int i = 1;i <= k;i ++) modify(1, 1, n, q[i].l, q[i].r, make_pair(q[i].val, q[i].d));
    for (register int i = 1;i <= n;i ++) a[i] = query(1, 1, n, i);
    memset(dp, -1, sizeof(dp));
    fprint(dfs(1, m), 10);
    return 0;
}