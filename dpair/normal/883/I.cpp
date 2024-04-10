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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int a[300005], n, m;
bitset <300005> b;

inline bool check(int x){
    b &= 0;b[0] = 1;int l = 1;
    for (register int i = 1;i <= n;i ++){
        while(a[i] - a[l] > x) l ++;
        while(l <= i - m + 1){
            if(b[l - 1]) {b[i] = 1;break;}
            else l ++;
        }
    }
    return b[n];
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    sort(a + 1, a + n + 1);
    int l = 0, r = a[n], ans = a[n];
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    fprint(ans, 10);
    return 0;
}