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

int n, k, a[500005];
LL sig;

inline bool check1(int x){
    LL ret = 0;
    for (register int i = 1;i <= n;i ++){
        if(a[i] > x) ret += a[i] - x;
        if(ret > k) return 0;
    }
    return ret <= k;
}

inline bool check2(int x){
    LL ret = 0;
    for (register int i = 1;i <= n;i ++){
        if(a[i] < x) ret += x - a[i];
        if(ret > k) return 0;
    }
    return ret <= k;
}

int main(){
    read(n);read(k);
    for (register int i = 1;i <= n;i ++) read(a[i]), sig += a[i];
    int l = 1, r = 1000000000, R = 1, L = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check1(mid)) R = mid, r = mid - 1;
        else l = mid + 1;
    }
    l = 1, r = 1000000000;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check2(mid)) L = mid, l = mid + 1;
        else r = mid - 1;
    }
    fprint(max(R - L, sig % n ? 1 : 0), 10);
    return 0;
}