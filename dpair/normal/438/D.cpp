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
#define MAXN 100005
int n, m;
int a[MAXN];
LL t[MAXN << 2], dat[MAXN << 2];
inline void pushup(int rt){t[rt] = mx(t[rt << 1], t[rt << 1 | 1]);dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];}
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

void build(int rt, int l, int r){
    if(l == r){
        t[rt] = dat[rt] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}

void modify1(int rt, int l, int r, int x, int y, int z){
    if(t[rt] < z) return ;
    if(l == r){
        t[rt] %= z;
        dat[rt] %= z;
        return ;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify1(LSON, x, y, z);
    if(y > mid) modify1(RSON, x, y, z);
    pushup(rt);
}

void modify2(int rt, int l, int r, int x, int z){
    if(l == r) return (void)(dat[rt] = t[rt] = z);
    int mid = (l + r) >> 1;
    if(x <= mid) modify2(LSON, x, z);
    else modify2(RSON, x, z);
    pushup(rt);
}

LL query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return dat[rt];
    int mid = (l + r) >> 1;LL ret = 0;
    if(x <= mid) ret = ret + query(LSON, x, y);
    if(y > mid) ret = ret + query(RSON, x, y);
    return ret;
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    build(1, 1, n);
    while(m --){
        int opt, l, r, x;read(opt);read(l);read(r);
        if(opt == 2) read(x), modify1(1, 1, n, l, r, x);
        if(opt == 3) modify2(1, 1, n, l, r);
        if(opt == 1) fprint(query(1, 1, n, l, r), 10);
    }
}