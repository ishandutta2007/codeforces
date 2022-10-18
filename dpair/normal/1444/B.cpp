/*
    author: DPair
    language: C++

    description:
    Duel!
*/
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
int n;
const int MAXN = 300005;
const LL MOD = 998244353;
int a[MAXN];
LL fac[MAXN], inv[MAXN];
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
inline void init(){
    fac[0] = 1;
    for (register int i = 1;i <= (n << 1);i ++) fac[i] = fac[i - 1] * i % MOD;
    inv[n << 1] = ksm(fac[n << 1], MOD - 2);
    for (register int i = (n << 1);i >= 1;i --) inv[i - 1] = inv[i] * i % MOD; 
}

inline LL Comb(LL x, LL y){
    if(y > x) return 0;
    return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

inline void MAIN(){
    read(n);
    init();
    for (register int i = 1;i <= (n << 1);i ++) read(a[i]);
    sort(a + 1, a + (n << 1) + 1);
    LL ans = 0;
    for (register int i = n + 1;i <= (n << 1);i ++) ans = (ans + a[i]) % MOD;
    for (register int i = 1;i <= n;i ++) ans = (ans - (a[i] % MOD) + MOD) % MOD;
    fprint(ans * Comb((n << 1), n) % MOD, 10);
}

int main(){
    int T = 1;
    while(T --) MAIN();
}