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
#define MAXN 300005
int n, a[MAXN], m;
struct Element{
    LL lnum, rnum;
    int lpeak, rpeak;
    int lup, rup;
    int num, len;
    inline void print(){
        printf("debug:\n");
        printf("lnum = %lld, rnum = %lld\n", lnum, rnum);
        printf("lpeak = %d, rpeak = %d\n", lpeak, rpeak);
        printf("lup = %d, rup = %d\n", lup, rup);
        printf("num = %d, len = %d\n", num, len);
        printf("-----done-----\n");
    }
    inline Element operator + (const Element &b) const{
        Element ret;ret.len = len + b.len;
        ret.num = mx(num, b.num);
        ret.lnum = lnum;ret.rnum = b.rnum;
        if(rnum > b.lnum){
            chmax(ret.num, rpeak + b.lup);
            if(lup == len) ret.lup = lup + b.lup;
            else ret.lup = lup;
            ret.rup = b.rup;
            if(lpeak == len) ret.lpeak = lpeak + b.lup;
            else ret.lpeak = lpeak;
            if(b.lup == b.len) ret.rpeak = b.len + rpeak;
            else ret.rpeak = b.rpeak;
        }
        if(rnum < b.lnum){
            chmax(ret.num, rup + b.lpeak);
            if(b.rup == b.len) ret.rup = b.rup + rup;
            else ret.rup = b.rup;
            ret.lup = lup;
            if(b.rpeak == b.len) ret.rpeak = b.rpeak + rup;
            else ret.rpeak = b.rpeak;
            if(rup == len) ret.lpeak = len + b.lpeak;
            else ret.lpeak = lpeak;
        }
        if(rnum == b.lnum){
            ret.lpeak = lpeak;
            ret.rpeak = b.rpeak;
            ret.lup = lup;
            ret.rup = b.rup;
        }
        return ret;
    }
}t[MAXN << 2];
LL lazy[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
void build(int rt, int l, int r){
    if(l == r){
        t[rt].len = 1;
        t[rt].lnum = t[rt].rnum = a[l];
        t[rt].lpeak = t[rt].rpeak = t[rt].lup = t[rt].rup = t[rt].num = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
inline void update(int rt, LL val){
    t[rt].lnum += val;t[rt].rnum += val;
    lazy[rt] += val;
}
inline void pushdown(int rt){
    if(lazy[rt]){
        update(rt << 1, lazy[rt]);
        update(rt << 1 | 1, lazy[rt]);
        lazy[rt] = 0;
    }
}

void output(int rt, int l, int r){
    if(l == r){
        printf("rt = %d, l = %d, r = %d\n", rt, l, r);
        t[rt].print();
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    output(LSON);output(RSON);
    printf("rt = %d, l = %d, r = %d\n", rt, l, r);
    t[rt].print();
}

void modify(int rt, int l, int r, int x, int y, LL z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    build(1, 1, n);
    // output(1, 1, n);
    read(m);
    while(m --){
        int l, r;LL w;read(l);read(r);read(w);
        modify(1, 1, n, l, r, w);
        fprint(t[1].num, 10);
        // output(1, 1, n);
    }
}