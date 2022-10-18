#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int UI;
typedef pair <int, int> pi;

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

int n;
LL a[200005], sig[200005], ans_res, ans_i;
double ans = -1e9 - 7;

inline double calc(int x, int pos){
    return (double)(sig[pos - x] - sig[pos] + sig[n - x + 1] - sig[n + 1] + a[pos]) / (double)(2.0 * x + 1.0);
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    if(n <= 2){
        printf("1\n%lld\n", a[1]);
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (register int i = n;i >= 1;i --) sig[i] = sig[i + 1] + a[i];
    for (register int i = 2;i < n;i ++){
        int r = mn(i - 1, n - i), l = 1, res = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(calc(mid, i) > calc(mid - 1, i)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        if(ans < calc(res, i) - a[i]){
            ans = calc(res, i) - a[i];
            ans_res = res;ans_i = i;
        }
    }
    fprint(ans_res << 1 | 1, 10);
    for (register int i = ans_i - ans_res;i <= ans_i;i ++) fprint(a[i], 32);
    for (register int i = n - ans_res + 1;i <= n;i ++) fprint(a[i], 32);
    putchar(10);
    return 0;
}