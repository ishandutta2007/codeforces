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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, a[205], tot, dep[205];
LL ans = 1, in;

LL gcd(LL x, LL y){return !y ? x : gcd(y, x % y);}
inline LL lcm(LL x, LL y){return x / gcd(x, y) * y;}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i <= n;i ++){
        memset(dep, 0, sizeof(dep));
        int cur = i;
        dep[cur] = tot = 1;
        cur = a[cur];
        while(!dep[cur]){
            dep[cur] = ++ tot;
            cur = a[cur];
        }
        chmax(in, 1ll * dep[cur]);
        ans = lcm(ans, tot - dep[cur] + 1);
    }
    in --;
    LL tmp = ans;
    while(ans < in) ans += tmp;
    fprint(ans, 10);
}