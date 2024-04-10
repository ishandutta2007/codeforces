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

int n, m;
struct EDGE{
    int u, v, w;
    inline bool operator < (const EDGE &tmp) const{return w < tmp.w;}
}a[1000005];

int fa[1000005];

int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) fa[i] = i;
    for (register int i = 1;i <= m;i ++){
        read(a[i].u);read(a[i].v);read(a[i].w);
    }
    sort(a + 2, a + m + 1);
    for (register int i = 2;i <= m;i ++){
        int xx = find(a[i].u), yy = find(a[i].v);
        if(xx ^ yy){
            fa[xx] = yy;
        }
        if(find(a[1].v) == find(a[1].u)){
            fprint(a[i].w, 10);
            return 0;
        }
    }
    fprint(1000000000, 10);
    return 0;
}