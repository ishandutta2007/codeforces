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

int dp[300005][2], lst[300005], n, m;

struct EDGE{
    int u, v, val;
    inline bool operator < (const EDGE &tmp) const{
        return val < tmp.val;
    }
}a[300005];

int main(){
    read(n);read(m);
    for (register int i = 1;i <= m;i ++){
        read(a[i].u);read(a[i].v);read(a[i].val);
    }
    sort(a + 1, a + m + 1);
    int ans = 0;
    for (register int i = 1;i <= m;i ++){
        if(lst[a[i].v] == a[i].val){
            if(lst[a[i].u] == a[i].val) chmax(dp[a[i].v][1], dp[a[i].u][0] + 1);
            else chmax(dp[a[i].v][1], mx(dp[a[i].u][0], dp[a[i].u][1]) + 1);
        }
        else{
            lst[a[i].v] = a[i].val;
            chmax(dp[a[i].v][0], dp[a[i].v][1]);
            if(lst[a[i].u] == a[i].val) chmax(dp[a[i].v][1], dp[a[i].u][0] + 1);
            else chmax(dp[a[i].v][1], mx(dp[a[i].u][0], dp[a[i].u][1]) + 1);
        }
        chmax(ans, mx(dp[a[i].v][0], dp[a[i].v][1]));
    }
    fprint(ans, 10);
    return 0;
}