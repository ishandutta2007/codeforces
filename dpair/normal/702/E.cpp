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

int n;
LL m;

int son[100005][55];
LL ans1[100005][55], ans2[100005][55];

LL dfs1(int x, LL k){
    if(!k) return 0;
    int tmp = 0;LL res = 1;
    while(res <= k){
        tmp ++;res <<= 1;
    }
    tmp --;res >>= 1;
    return ans1[x][tmp] + dfs1(son[x][tmp], k - res);
}

LL dfs2(int x, LL k){
    if(!k) return 0x3f3f3f3f3f3f3f3f;
    int tmp = 0;LL res = 1;
    while(res <= k){
        tmp ++;res <<= 1;
    }
    tmp --;res >>= 1;
    return mn(ans2[x][tmp], dfs2(son[x][tmp], k - res));
}

int main(){
    read(n);read(m);
    for (register int i = 0;i < n;i ++) read(son[i][0]);
    for (register int i = 0;i < n;i ++) read(ans1[i][0]), ans2[i][0] = ans1[i][0];
    for (register int i = 1;i <= 40;i ++){
        for (register int j = 0;j < n;j ++){
            son[j][i] = son[son[j][i - 1]][i - 1];
            ans1[j][i] = ans1[j][i - 1] + ans1[son[j][i - 1]][i - 1];
            ans2[j][i] = mn(ans2[j][i - 1], ans2[son[j][i - 1]][i - 1]);
        }
    }
    for (register int i = 0;i < n;i ++) fprint(dfs1(i, m), 32), fprint(dfs2(i, m), 10);
    return 0;
}