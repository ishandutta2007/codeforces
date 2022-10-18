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
LL exgcd(LL x, LL y, LL &a, LL &b){
    if(!y){a = 1;b = 0;return x;}
    LL ret = exgcd(y, x % y, a, b);
    LL tmp = a;
    a = b;b = tmp - x / y * b;
    return ret;
}
LL MOD;
inline LL inv(LL x){
    LL a, b;
    exgcd(x, MOD, a, b);
    a = (a % MOD + MOD) % MOD;
    return a;
}
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = (ret * x) % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
int n, m;
int prime[15], tot;
#define MAXN 100005
LL a[MAXN];

int cnt[MAXN << 2][15];
LL t[MAXN << 2], num[MAXN << 2];
LL mul[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushup(int rt){t[rt] = (t[rt << 1] + t[rt << 1 | 1]) % MOD;}
inline void update1(int rt, LL val){
    mul[rt] = mul[rt] * val % MOD;
    t[rt] = t[rt] * val % MOD;
}
inline void update2(int rt, LL val){
    num[rt] = num[rt] * val % MOD;
}
inline void update(int rt, LL val){
    update1(rt, val);
    for (register int i = 1;i <= tot;i ++){
        while(val % prime[i] == 0) val /= prime[i], cnt[rt][i] ++;
    }
    update2(rt, val);
}
inline void pushdown(int rt){
    if(mul[rt] ^ 1){
        update1(rt << 1, mul[rt]);
        update1(rt << 1 | 1, mul[rt]);
        update2(rt << 1, num[rt]);
        update2(rt << 1 | 1, num[rt]);
        for (register int i = 1;i <= tot;i ++) cnt[rt << 1][i] += cnt[rt][i], cnt[rt << 1 | 1][i] += cnt[rt][i], cnt[rt][i] = 0;
        mul[rt] = 1;num[rt] = 1;
    }
}
void build(int rt, int l, int r){
    mul[rt] = 1;num[rt] = 1;
    if(l == r){
        t[rt] = a[l] % MOD;
        for (register int i = 1;i <= tot;i ++){
            while(a[l] % prime[i] == 0) cnt[rt][i] ++, a[l] /= prime[i];
        }
        num[rt] = a[l] % MOD;
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
void modify(int rt, int l, int r, int x, int y, LL z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
void change(int rt, int l, int r, int x, LL z){
    if(l == r){
        for (register int i = 1;i <= tot;i ++){
            while(z % prime[i] == 0) cnt[rt][i] --, z /= prime[i];
        }
        num[rt] = num[rt] * inv(z) % MOD;
        t[rt] = num[rt];
        for (register int i = 1;i <= tot;i ++){
            t[rt] = t[rt] * ksm(prime[i], cnt[rt][i]) % MOD;
        }
        return ;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) change(LSON, x, z);
    else change(RSON, x, z);
    pushup(rt);
}
LL query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;LL ret = 0;
    if(x <= mid) ret = query(LSON, x, y);
    if(y > mid) ret = (ret + query(RSON, x, y)) % MOD;
    return ret;
}
int main(){
    read(n);read(MOD);

    LL tmp = MOD;
    for (register int i = 2;1ll * i * i <= tmp;i ++){
        if(tmp % i == 0){
            while(tmp % i == 0) tmp /= i;
            prime[++ tot] = i;
        }
    }
    if(tmp > 1) prime[++ tot] = tmp;

    for (register int i = 1;i <= n;i ++) read(a[i]);
    build(1, 1, n);
    read(m);
    while(m --){
        int opt, l, r;
        LL x;
        read(opt);
        if(opt == 1) read(l), read(r), read(x), modify(1, 1, n, l, r, x);
        if(opt == 2) read(l), read(x), change(1, 1, n, l, x);
        if(opt == 3) read(l), read(r), fprint(query(1, 1, n, l, r), 10);
    }
}