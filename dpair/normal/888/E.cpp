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
int n, m;
int a[45];
int b1[1000005], tot1, b2[1000005], tot2;
int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    int k1 = (n >> 1), k2 = n - k1;
    for (register int i = 0;i < (1 << k1);i ++){
        int num = 0;
        for (register int j = 0;j < k1;j ++){
            if(i & (1 << j)) num = (num + a[j + 1]) % m;
        }
        b1[++ tot1] = num;
    }
    for (register int i = 0;i < (1 << k2);i ++){
        int num = 0;
        for (register int j = 0;j < k2;j ++){
            if(i & (1 << j)) num = (num + a[j + k1 + 1]) % m;
        }
        b2[++ tot2] = num;
    }
    sort(b1 + 1, b1 + tot1 + 1);
    sort(b2 + 1, b2 + tot2 + 1);
    int ans = mx(b1[tot1], b2[tot2]);
    int t1 = unique(b1 + 1, b1 + tot1 + 1) - b1 - 1;
    int t2 = unique(b2 + 1, b2 + tot2 + 1) - b2 - 1;
    for (register int i = 1;i <= t1;i ++){
        int l = 1, r = t2, pos = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(b2[mid] + b1[i] < m) pos = mid, l = mid + 1;
            else r = mid - 1; 
        }
        chmax(ans, b2[pos] + b1[i]);
    }
    fprint(ans, 10);
}