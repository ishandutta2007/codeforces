//
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
#define MAXN 500005

int n, m;
int a[MAXN], ans;

int gcd(int x, int y){return !y? x : gcd(y, x % y);}

struct Segtree{
    int dat[MAXN << 2];
    inline void pushup(int rt){dat[rt] = gcd(dat[rt << 1], dat[rt << 1 | 1]);}
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    void build(int rt, int l, int r){
        if(l == r){
            dat[rt] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    void modify(int rt, int l, int r, int x, int y){
        if(l == r) return (void)(dat[rt] = y);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y);
        else modify(RSON, x, y);
        pushup(rt);
    }
    void query(int rt, int l, int r, int x, int y, int z){
        if(ans > 1) return ;
        if(l == r) {
            ans ++;
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid && (dat[rt << 1] % z)) query(LSON, x, y, z);
        if(y > mid && (dat[rt << 1 | 1] % z)) query(RSON, x, y, z);
    }
}t;

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    t.build(1, 1, n);
    read(m);
    while(m --){
        int opt, l, r, x;
        read(opt);read(l);read(r);
        if(opt == 1){
            read(x);ans = 0;
            t.query(1, 1, n, l, r, x);
            if(ans > 1) printf("NO\n");
            else printf("YES\n");
        }
        else t.modify(1, 1, n, l, r);
    }
}