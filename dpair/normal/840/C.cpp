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
#define MAXN 305
int n, tot, total;
int a[MAXN], cnt[MAXN];
unordered_map <int, int> h;
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
LL dp[MAXN], f[MAXN], tmp[MAXN];
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
        for (register int j = 2;1ll * j * j <= a[i];j ++){
            while(a[i] % (j * j) == 0){
                a[i] /= (j * j);
            }
        }
        if(!h[a[i]]) h[a[i]] = ++ tot;
        a[i] = h[a[i]];
        cnt[a[i]] ++;
    }
    fac[0] = 1;
    for (register int i = 1;i <= n;i ++) fac[i] = fac[i - 1] * i % MOD;
    inv[n] = ksm(fac[n], MOD - 2);
    for (register int i = n - 1;i >= 0;i --) inv[i] = inv[i + 1] * (i + 1) % MOD;
    dp[0] = 1;
    for (register int i = 1;i <= tot;i ++){
        for (register int j = 0;j < total + cnt[i];j ++) f[j] = 0;
        LL cur = 1;
        for (register int j = cnt[i];j >= 1;j --){
            tmp[cnt[i] - j] = cur * inv[cnt[i] - j] % MOD;
            cur = (cur * j * (j - 1)) % MOD;
        }
        for (register int j = 0;j <= total;j ++){
            for (register int k = 0;k < cnt[i];k ++){
                f[j + k] = (f[j + k] + tmp[k] * dp[j]) % MOD;
            }
        }
        total += cnt[i] - 1;
        for (register int j = 0;j <= total;j ++) dp[j] = f[j];
    }
    for (register int i = 0;i <= total;i ++) dp[i] = (dp[i] * fac[n - i]) % MOD;
    LL ans = 0;
    for (register int i = 0;i <= total;i ++){
        if(i & 1) ans = (ans - dp[i] + MOD) % MOD;
        else ans = (ans + dp[i]) % MOD;
    }
    fprint(ans, 10);
}