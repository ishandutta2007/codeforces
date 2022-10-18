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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
struct DAT{
    bool all;
    LL sig;
    inline DAT operator + (const DAT &tmp) const{
        DAT res;res.all = all & tmp.all;
        res.sig = sig + tmp.sig;
        return res;
    }
};
#define MAXN 300005
int a[MAXN], n, m;
int ch[1000005];
int tot;
inline void init(){
    for (register int i = 1;i <= tot;i ++){
        for (register int j = i;j <= tot;j += i){
            ch[j] ++;
        }
    }
}

struct Segtree{
    DAT dat[MAXN << 2];
    inline void pushup(int rt){dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];}
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    void build(int rt, int l, int r){
        // printf("build l = %d, r = %d, rt = %d\n", l, r, rt);
        if(l == r) {
            dat[rt].sig = a[l];
            dat[rt].all = ((a[l] == 1) || (a[l] == 2));
            // printf("abnormal end build l = %d, r = %d, rt = %d, sig = %lld, all = %d, a[l] = %d\n", l, r, rt, dat[rt].sig, dat[rt].all, a[l]);
            return ;
        }
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
        // printf("end build l = %d, r = %d, rt = %d, sig = %lld, all = %d\n", l, r, rt, dat[rt].sig, dat[rt].all);
    }
    void modify(int rt, int l, int r, int x, int y){
        if(dat[rt].all) return ;
        if(l == r){
            dat[rt].sig = ch[dat[rt].sig];
            dat[rt].all = (dat[rt].sig == 1 || dat[rt].sig == 2);
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y);
        if(y > mid) modify(RSON, x, y);
        pushup(rt);
    }
    LL query(int rt, int l, int r, int x, int y){
        // printf("rt = %d, l = %d, r = %d, x = %d, y = %d\n", rt, l, r, x, y);
        if(x <= l && r <= y) return dat[rt].sig;
        int mid = (l + r) >> 1;
        if(x <= mid && y > mid) return query(LSON, x, y) + query(RSON, x, y);
        if(x <= mid) return query(LSON, x, y);
        if(y > mid) return query(RSON, x, y);
    }
}t;


int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]), chmax(tot, a[i]);
    // for (register int i = 1;i <= n;i ++) fprint(a[i], 32);
    // putchar(10);
    init();
    t.build(1, 1, n);
    while(m --){
        int opt, l, r;read(opt);read(l);read(r);
        if(opt == 1) t.modify(1, 1, n, l, r);
        else fprint(t.query(1, 1, n, l, r), 10);
    }
}