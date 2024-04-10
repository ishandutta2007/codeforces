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
typedef long long LL;
const LL MOD = 1000000007;
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}
unordered_map <int, LL> mem;
LL dfs(int x){
    if(x == 1) return 1ll;
    if(mem[x]) return mem[x];
    LL ret = 1;
    for (register int d = 2;d * d <= x;d ++){
        if(x % d == 0) {ret = (ret + dfs(d)) % MOD;
            if((d * d) ^ x) {ret = (ret + dfs(x / d)) % MOD;}
        }
    }
    return mem[x] = (ksm(2, x - 1) - ret + MOD) % MOD;
}

int main(){
    int x, y;
    read(x);read(y);
    if(y % x) return printf("0\n"), 0;
    fprint(dfs(y / x), 10);
    return 0;
}