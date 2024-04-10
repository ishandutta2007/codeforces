#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
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

LL dp[100005][105], sig[100005];

int n, k, len, a[100005], cnt[105], ans;

inline void add(int x){if(!(cnt[x] ++)) ans ++;}
inline void del(int x){if(!(-- cnt[x])) ans --;}

int main(){
    read(n);read(k);read(len);
    sig[0] = 1;
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
        if(~a[i]) add(a[i]);
        if(i > len && (~a[i - len])) del(a[i - len]);
        for (register int j = 1;j <= k;j ++){
            if(i >= len && (!ans || (ans == 1 && cnt[j]))) dp[i][j] = (dp[i][j] - sig[i - len] + dp[i - len][j] + MOD) % MOD;
            dp[i][j] += sig[i - 1];dp[i][j] %= MOD;
            if(~a[i] && (a[i] ^ j)) dp[i][j] = 0;
            sig[i] = (sig[i] + dp[i][j]) % MOD;
        }
    }
    fprint(sig[n], 10);
    return 0;
}