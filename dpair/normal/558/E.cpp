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

#define MAXN 100005

struct Element{
    int cnt[26];
    inline void init(){memset(cnt, 0, sizeof(cnt));}
    inline void overwrite(int num, int col){init();cnt[col] = num;}
    inline Element operator + (const Element &tmp) const{
        Element ret;
        for (register int i = 0;i < 26;i ++) ret.cnt[i] = tmp.cnt[i] + cnt[i];
        return ret;
    }
};
char a[MAXN];
struct SegTree{
    Element dat[MAXN << 2];
    int lazy[MAXN << 2];
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    inline void pushup(int rt){dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];}
    inline void update(int rt, int l, int r, int val){
        lazy[rt] = val;
        dat[rt].overwrite(r - l + 1, val);
    }
    inline void pushdown(int rt, int l, int r){
        if(~lazy[rt]){
            int mid = (l + r) >> 1;
            update(LSON, lazy[rt]);
            update(RSON, lazy[rt]);
            lazy[rt] = -1;
        }
    }
    void build(int rt, int l, int r){
        lazy[rt] = -1;dat[rt].init();
        if(l == r){dat[rt].cnt[a[l] - 'a'] ++;return ;}
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    void modify(int rt, int l, int r, int x, int y, int z){
        if(x <= l && r <= y) return update(rt, l, r, z);
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y, z);
        if(y > mid) modify(RSON, x, y, z);
        pushup(rt);
    }
    Element query_E(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return dat[rt];
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;Element ret;ret.init();
        if(x <= mid) ret = ret + query_E(LSON, x, y);
        if(y > mid) ret = ret + query_E(RSON, x, y);
        return ret;
    }
}t;
int n, m;
int main(){
    read(n);read(m);
    scanf("%s", a + 1);
    t.build(1, 1, n);
    for (register int i = 1;i <= m;i ++){
        int opt, l, r;read(l);read(r);
        read(opt);
        if(opt == 1){
            int cur = l;Element res = t.query_E(1, 1, n, l, r);
            for (register int i = 0;i < 26;i ++){
                int num = res.cnt[i];
                if(!num) continue;
                t.modify(1, 1, n, cur, cur + num - 1, i);
                cur += num;
            }
        }
        else{
            int cur = l;Element res = t.query_E(1, 1, n, l, r);
            for (register int i = 25;i >= 0;i --){
                int num = res.cnt[i];
                if(!num) continue;
                t.modify(1, 1, n, cur, cur + num - 1, i);
                cur += num;
            }
        }
    }
    for (register int i = 1;i <= n;i ++) {
        Element res = t.query_E(1, 1, n, i, i);
        for (register int j = 0;j < 26;j ++) if(res.cnt[j]) {putchar(j + 97);break;}
    }
    putchar(10);
}