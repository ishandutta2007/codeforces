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

int n, d;
int a[2005], cur;
#define MOD 1000000007
LL ans = 0;
int head[2005], nxt[4005], cnt, e[4005];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

LL dfs(int x, int pre){
    if(a[x] > a[cur] || (a[x] == a[cur] && x < cur) || (a[cur] - a[x] > d)) return 0;
    LL ret = 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        ret = ret * (dfs(e[i], x) + 1) % MOD;
    }
    return ret;
}


int main(){
    read(d);read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    for (register int i = 1;i <= n;i ++){
        cur = i;
        ans = (ans + dfs(i, 0)) % MOD;
    }
    fprint(ans, 10);
    return 0;
}