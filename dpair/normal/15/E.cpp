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
#define MAXN 1000005
LL n;
const LL MOD = 1000000009;
LL b[MAXN];
int main(){
    b[0] = 1;
    read(n);n >>= 1;
    for (register int i = 1;i <= n;i ++) b[i] = (b[i - 1] << 1) % MOD;
    LL ans = 1, cnt = 2;
    for (register int i = 2;i <= n;i ++){
        ans = ans * (b[i] + MOD - 3) % MOD;
        cnt = (cnt + (ans << 2)) % MOD;
    }
    LL ret = 0;
    ret = cnt * cnt % MOD;
    ret = (ret << 1) % MOD;
    fprint((ret + 2) % MOD, 10);
}