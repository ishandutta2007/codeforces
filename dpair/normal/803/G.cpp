#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
int lc[8000005], rc[8000005], tot;
int num[8000005], lazy[8000005];
#define LSON lc[rt], l, mid
#define RSON rc[rt], mid + 1, r

int n, m, k;
int a[100005][21];
int laoge[100005];
inline void init(){
    for (register int j = 1;j <= 20;j ++){
        for (register int i = 1;i + (1 << j) - 1 <= n;i ++){
            a[i][j] = mn(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
        }
    }
    laoge[1] = 0;
    for (register int i = 2;i <= n;i ++) laoge[i] = laoge[i >> 1] + 1; 
}

inline int fake_query(int l, int r){
    int k = laoge[r - l + 1];
    return mn(a[l][k], a[r - (1 << k) + 1][k]);
}

inline int idb(int x){return ((x - 1) / n + 1);}
inline int work(int l, int r){
    if(idb(l) == idb(r)) return fake_query((l - 1) % n + 1, (r - 1) % n + 1);
    else if(r - l + 1 >= n) return fake_query(1, n);
    else return mn(fake_query((l - 1) % n + 1, n), fake_query(1, (r - 1) % n + 1));
}

inline void pushup(int rt, int l, int r){
    num[rt] = 0x3f3f3f3f;
    int mid = (l + r) >> 1;
    if(!lc[rt]) chmin(num[rt], work(l, mid));
    else chmin(num[rt], num[lc[rt]]);
    if(!rc[rt]) chmin(num[rt], work(mid + 1, r));
    else chmin(num[rt], num[rc[rt]]);
}
inline void update(int &rt, int val){
    if(!rt) rt = ++ tot;
    num[rt] = val;
    lazy[rt] = val;
}
inline void pushdown(int rt){
    if(lazy[rt]){
        update(lc[rt], lazy[rt]);
        update(rc[rt], lazy[rt]);
        lazy[rt] = 0;
    }
}
void modify(int &rt, int l, int r, int x, int y, int z){
    if(!rt) rt = ++ tot;
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt, l, r);
}

int query(int rt, int l, int r, int x, int y){
    if(!rt) return work(mx(l, x), mn(y, r));
    if(x <= l && r <= y) return num[rt];
    pushdown(rt);
    int ret = 0x3f3f3f3f;int mid = (l + r) >> 1;
    if(x <= mid) chmin(ret, query(LSON, x, y));
    if(y > mid) chmin(ret, query(RSON, x, y));
    return ret;
}
int root;
int main(){
    read(n);read(k);
    for (register int i = 1;i <= n;i ++) read(a[i][0]);
    init();read(m);
    while(m --){
        int opt, l, r, x;
        read(opt);read(l);read(r);
        if(opt == 1){
            read(x);
            modify(root, 1, n * k, l, r, x);
        }
        else fprint(query(root, 1, n * k, l, r), 10);
    }
}