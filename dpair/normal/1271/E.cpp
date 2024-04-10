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
LL n, k;

// map <LL, LL> mem;

inline LL f(LL x){
    LL ret = 1, cur = 2;
    while((x << 1) <= n){
        if((x << 1) + cur <= n) ret = ret + cur;
        else ret = ret + n - (x << 1) + 1;
        x <<= 1, cur <<= 1;
    }
    return ret;
}


inline LL check(LL x){
    if(x & 1) return f(x);
    else return f(x) + f(x + 1);
}

int main(){
    read(n);read(k);
    LL l = 1, r = (n >> 1), ans = 0;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(check(mid << 1) >= k) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    LL ans2 = 0;
    l = 0, r = ((n - 1) >> 1);
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(check(mid << 1 | 1) >= k) ans2 = mid, l = mid + 1;
        else r = mid - 1;
    }
    fprint(max(ans << 1, ans2 << 1 | 1), 10);
    return 0;
}