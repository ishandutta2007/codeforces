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
#define MAXN 200005
#define block 4475
#define B MAXN / block + 5
int n, m;
int a[MAXN];
int bel[MAXN], fst[B], lst[B], fa[B][105];

inline void rebuild(int x){
    for (register int i = fst[x];i <= lst[x];i ++) a[i] = fa[x][a[i]];
    for (register int i = 1;i <= 100;i ++) fa[x][i] = i;
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i <= n;i ++){
        bel[i] = (i - 1) / block + 1;
        if(!fst[bel[i]]) fst[bel[i]] = i;
        lst[bel[i]] = i;
    }
    for (register int i = 1;i <= bel[n];i ++)
        for (register int j = 1;j <= 100;j ++)
            fa[i][j] = j;
    read(m);
    while(m --){
        int l, r, x, y;
        read(l);read(r);read(x);read(y);
        int L = bel[l], R = bel[r];
        if(L == R){
            rebuild(L);
            for (register int i = l;i <= r;i ++) if(a[i] == x) a[i] = y;
        }
        else{
            rebuild(L);rebuild(R);
            for (register int i = l;i <= lst[L];i ++) if(a[i] == x) a[i] = y;
            for (register int i = fst[R];i <= r;i ++) if(a[i] == x) a[i] = y;
            for (register int i = L + 1;i < R;i ++){
                for (register int j = 1;j <= 100;j ++){
                    if(fa[i][j] == x) fa[i][j] = y;
                }
            }
        }
    }
    for (register int i = 1;i <= bel[n];i ++) rebuild(i);
    for (register int i = 1;i <= n;i ++) fprint(a[i], 32);
    putchar(10);
}