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
#define int long long
int n;

inline double dis(int x, int y, int xx, int yy){return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));}
#define PI 3.141592653589793238462643383279
struct Circle{
    int x, y;
    int r;
    inline bool in (Circle tmp){
        if(dis(x, y, tmp.x, tmp.y) < tmp.r && r < tmp.r) return 1;
        else return 0;
    }
    inline double sz(){return PI * (double)r * (double)r;}
}a[1005];
int fa[1005], r_fa[1005];
int head[1005], nxt[1005], e[1005], cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
double ans;
void dfs(int x, int dep, int opt){
    if(dep == 2) opt = -opt;
    ans += opt * a[x].sz();
    for (register int i = head[x];i;i = nxt[i]){
        dfs(e[i], dep + 1, -opt);
    }
}

signed main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i].x);read(a[i].y);read(a[i].r);
        r_fa[i] = 0x3f3f3f3f;
    }
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= n;j ++){
            if(i == j) continue;
            if(a[i].in(a[j]) && r_fa[i] > a[j].r){
                fa[i] = j;
                r_fa[i] = a[j].r;
            }
        }
    }
    for (register int i = 1;i <= n;i ++) add(fa[i], i);
    dfs(0, 0, -1);
    printf("%.8lf\n", ans);
    return 0;
}