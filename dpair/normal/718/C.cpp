//hoho
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

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
int a[MAXN], n, m;
struct Matrix{
    LL dat[2][2];
    int row, column;
    inline void init(int tmp1, int tmp2){dat[0][0] = dat[0][1] = dat[1][0] = dat[1][1] = 0;row = tmp1, column = tmp2;}
    inline void init_one(int tmp){init(tmp, tmp);dat[0][0] = dat[1][1] = 1;}
    inline bool is_one(){return dat[0][0] == 1 && dat[1][1] == 1 && dat[1][0] == 0 && dat[0][1] == 0;}
    inline Matrix operator + (const Matrix &b) const{
        Matrix c;c.init(row, column);
        for (register int i = 0;i < row;i ++){
            for (register int j = 0;j < column;j ++){
                c.dat[i][j] = (dat[i][j] + b.dat[i][j]) % MOD;
            }
        }
        return c;
    }
    inline Matrix operator * (const Matrix &b) const{
        Matrix c;c.init(row, b.column);
        for (register int i = 0;i < row;i ++){
            for (register int k = 0;k < column;k ++){
                for (register int j = 0;j < b.column;j ++){
                    c.dat[i][j] = (c.dat[i][j] + dat[i][k] * b.dat[k][j]) % MOD;
                }
            }
        }
        return c;
    }
    inline Matrix ksm(int y){
        Matrix ret;ret.init_one(row);
        Matrix tmp;tmp.row = row;tmp.column = column;
        tmp.dat[0][0] = dat[0][0];tmp.dat[0][1] = dat[0][1];tmp.dat[1][0] = dat[1][0];tmp.dat[1][1] = dat[1][1];
        while(y){
            if(y & 1) ret = ret * tmp;
            tmp = tmp * tmp;
            y >>= 1;
        }
        return ret;
    }
};
Matrix ch, tmp;
struct Segtree{
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    Matrix dat[MAXN << 2], tag[MAXN << 2];
    inline void pushup(int rt){dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];}
    inline void update(int rt, Matrix &x){
        dat[rt] = dat[rt] * x;
        tag[rt] = tag[rt] * x;
    }
    inline void pushdown(int rt){
        if(!tag[rt].is_one()){
            update(rt << 1, tag[rt]);
            update(rt << 1 | 1, tag[rt]);
            tag[rt].init_one(2);
        }
    }
    void build(int rt, int l, int r){
        tag[rt].init_one(2);
        if(l == r){
            dat[rt].init(1, 2);
            dat[rt].dat[0][1] = dat[rt].dat[0][0] = 1;
            if(a[l] > 1) dat[rt] = dat[rt] * ch.ksm(a[l] - 1);
            return ;
        }
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    void modify(int rt, int l, int r, int x, int y, Matrix &z){
        if(x <= l && r <= y) return update(rt, z);
        pushdown(rt);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y, z);
        if(y > mid) modify(RSON, x, y, z);
        pushup(rt);
    }
    LL query(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return dat[rt].dat[0][1];
        pushdown(rt);
        int mid = (l + r) >> 1;LL ret = 0;
        if(x <= mid) ret = (ret + query(LSON, x, y)) % MOD;
        if(y > mid) ret = (ret + query(RSON, x, y)) % MOD;
        return ret;
    }
}t;

int main(){
    ch.init(2, 2);ch.dat[0][0] = ch.dat[1][0] = ch.dat[0][1] = 1;
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    t.build(1, 1, n);
    while(m --){
        int opt, l, r, x;read(opt);read(l);read(r);
        if(opt == 1){
            read(x);
            tmp = ch.ksm(x);
            t.modify(1, 1, n, l, r, tmp);
        }
        else fprint(t.query(1, 1, n, l, r), 10);
    }
}