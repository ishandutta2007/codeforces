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
#define MAXN 1005
int n;
int a[MAXN];
int b[MAXN];
int ans[MAXN][MAXN];
inline bool cmp(int x, int y){return a[x] > a[y];}
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    for (register int i = 1;i <= n;i ++){
        int cur = i;
        while(a[b[i]] --){
            ans[b[i]][cur] = 1;
            cur ++;
            if(cur > n + 1) cur = 1;
        }
    }
    printf("%d\n", n + 1);
    for (register int j = 1;j <= n + 1;j ++){
        for (register int i = 1;i <= n;i ++){
            if(ans[i][j]) fprint(1);
            else fprint(0);
        }
        putchar(10);
    }
}