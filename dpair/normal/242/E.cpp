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

#define MAXN 100005
int t[MAXN << 2][21], lazy[MAXN << 2];//
int n, m;
int a[MAXN];

inline void pushup(int rt){for (register int i = 0;i <= 20;i ++) t[rt][i] = t[rt << 1][i] + t[rt << 1 | 1][i];}
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
void build(int rt, int l, int r){
    if(l == r){
        for (register int i = 0;i <= 20;i ++){
            if(a[l] & (1 << i)) t[rt][i] = 1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
inline void update(int rt, int l, int r, int x){
    for (register int i = 0;i <= 20;i ++){
        if(x & (1 << i)){
            t[rt][i] = (r - l + 1) - t[rt][i];
        }
    }
    lazy[rt] ^= x;
}
inline void pushdown(int rt, int l, int r){
    if(lazy[rt]){
        int mid = (l + r) >> 1;
        update(LSON, lazy[rt]);
        update(RSON, lazy[rt]);
        lazy[rt] = 0;
    }
}
void modify(int rt, int l, int r, int x, int y, int z){
    if(x <= l && r <= y) return update(rt, l, r, z);
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
LL query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y){
        LL ret = 0, base = 1;
        for (register int i = 0;i <= 20;i ++){
            ret = ret + base * t[rt][i];
            base <<= 1;
        }
        return ret;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(LSON, x, y) + query(RSON, x, y);
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    build(1, 1, n);
    read(m);
    while(m --){
        int opt, l, r, x;read(opt);read(l);read(r);
        if(opt == 2) read(x), modify(1, 1, n, l, r, x);
        else fprint(query(1, 1, n, l, r), 10);
    }
}