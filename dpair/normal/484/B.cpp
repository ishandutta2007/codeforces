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

int ans;
int n, a[200005];
bitset <1000005> vis;
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    sort(a + 1, a + n + 1);
    for (register int i = 1;i <= n;i ++){
        if(vis[a[i]]) continue;
        vis[a[i]] = 1;
        if(a[i] <= 500){
            for (register int j = n;j > i;j --){
                chmax(ans, a[j] % a[i]);
            }
        }
        else{
            for (register int j = (a[i] << 1);j <= a[n] + a[i];j += a[i]){
                int pos = i, l = i, r = n;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(a[mid] < j) pos = mid, l = mid + 1;
                    else r = mid - 1;
                }
                chmax(ans, a[pos] % a[i]);
            }
        }
    }
    fprint(ans, 10);
    return 0;
}